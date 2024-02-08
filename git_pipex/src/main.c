/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:00:32 by lmattern          #+#    #+#             */
/*   Updated: 2024/02/08 15:44:01 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int		main(int argc, char **argv, char **envp)
{
	t_data	data;

	init_n_check_arguments(argc, argv, &data);
	check_and_parse_cmd(argc, argv, envp, &data);
	print_commands(data.cmds);//debug

	open_input_file(data.file_in_name, &data);
	open_output_file(data.file_out_name, &data);
	execute_commands(&data, envp);
	
	return (EXIT_SUCCESS);
}

void	init_n_check_arguments(int argc, char **argv, t_data *data)
{
	char	*base_name;
	if (argc < 4)
	{
		fprintf(stderr, "Usage: ./pipex file_in cmd1 [cmd2 ...] [file_out]\n");
		exit(EXIT_FAILURE);
	}
	ft_memset(data, 0, sizeof(*data));
	base_name = ft_strrchr(argv[0], '/');
	if (base_name != NULL)
		data->program_name = base_name + 1;
	else
		data->program_name = argv[0];
	data->file_in_name = argv[1];
	data->file_out_name = argv[argc - 1];
	printf("pgrm : %s\n", data->program_name);
	printf("infile :%s\n", data->file_in_name);
	printf("outfile :%s\n", data->file_out_name);
}

int	open_input_file(char *file_name, t_data *data)
{
	data->file_in = open(file_name, O_RDONLY);
	if (data->file_in == -1)
	{
		perror("Error opening input file");
		return (-1);
	}
	return (0);
}

int	open_output_file(char *file_name, t_data *data)
{
	data->file_out = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data->file_out == -1)
	{
		perror("Error opening output file");
		return (-1);
	}
	return (0);
}

int create_pipe(int pipefd[2])
{
	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		return -1;
	}
	return 0;
}

void execute_command(t_cmds *cmd, int input_fd, int output_fd, char **envp)
{
	pid_t pid = fork();
	if (pid == 0) {
		if (input_fd != STDIN_FILENO) {
			dup2(input_fd, STDIN_FILENO);
			close(input_fd);
		}
		if (output_fd != STDOUT_FILENO) {
			dup2(output_fd, STDOUT_FILENO);
			close(output_fd);
		}
		execve(cmd->full_path, cmd->cmd_n_args, envp);
		perror("execve");
	}
}
void close_fds(int fds[])
{
	for (int i = 0; i < 2; ++i) {
		if (fds[i] != -1) {
			close(fds[i]);
		}
	}
}
void execute_commands(t_data *data, char **envp)
{
    int input_fd;
    int pipefd[2];
    int output_fd;
    t_cmds *cmd;

    input_fd = data->file_in; // Initialisation avec le fichier d'entrée
    cmd = data->cmds;

    while (cmd != NULL) {
        if (cmd->next != NULL) {
            if (create_pipe(pipefd) != 0) {
                exit(EXIT_FAILURE); // Gestion simplifiée des erreurs
            }
        } else {
            pipefd[0] = -1;
            pipefd[1] = -1;
        }

        if (cmd->next == NULL) {
            output_fd = data->file_out; // Dernière commande écrit dans file_out
        } else {
            output_fd = pipefd[1];
        }

        execute_command(cmd, input_fd, output_fd, envp);

        // Fermeture des descripteurs non nécessaires et préparation pour le prochain tour
        if (input_fd != data->file_in) {
            close(input_fd);
        }

        // Préparation de input_fd pour la prochaine commande
        input_fd = pipefd[0];

        if (cmd->next != NULL && output_fd != data->file_out) {
            close(output_fd);
        }

        cmd = cmd->next; // Passage à la commande suivante

        // Réinitialisation des pipefd pour la prochaine itération
        pipefd[0] = -1;
        pipefd[1] = -1;
    }

    // Attendre que tous les processus enfants se terminent
    pid_t pid;
    while ((pid = wait(NULL)) > 0);
}
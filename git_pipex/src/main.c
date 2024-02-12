/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:00:32 by lmattern          #+#    #+#             */
/*   Updated: 2024/02/12 18:45:54 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	init_n_check_arguments(argc, argv, &data);
	check_and_parse_cmd(argc, argv, envp, &data);
	open_input_file(data.file_in_name, &data);
	print_commands(data.cmds);
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
	/*printf("pgrm : %s\n", data->program_name);
	printf("infile :%s\n", data->file_in_name);
	printf("outfile :%s\n", data->file_out_name);*/
}

void	open_input_file(char *file_name, t_data *data)
{
	data->file_in = open(file_name, O_RDONLY);
	if (data->file_in == -1)
	{
		ft_putstr_fd(data->program_name, 2);
		write(2, ": ", 2);
		ft_putchar_fd(ft_tolower((strerror(errno))[0]), 2);
		ft_putstr_fd(strerror(errno) + 1, 2);
		write(2, ": ", 2);
		ft_putstr_fd(data->file_in_name, 2);
		write(2, "\n", 1);
		data->cmds->exec = 0;
	}
}

void	open_output_file(char *file_name, t_data *data)
{
	data->file_out = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data->file_out == -1)
	{
		ft_putstr_fd(data->program_name, 2);
		write(2, ": ", 2);
		ft_putchar_fd(ft_tolower((strerror(errno))[0]), 2);
		ft_putstr_fd(strerror(errno) + 1, 2);
		write(2, ": ", 2);
		ft_putstr_fd(data->file_out_name, 2);
		write(2, "\n", 1);
	}
}

int	create_pipe(int pipefd[2])
{
	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		return (-1);
	}
	return (0);
}

void	execute_command(t_cmds *cmd, int input_fd, int output_fd, char **envp)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		if (input_fd != STDIN_FILENO)
		{
			dup2(input_fd, STDIN_FILENO);
			close(input_fd);
		}
		if (output_fd != STDOUT_FILENO)
		{
			dup2(output_fd, STDOUT_FILENO);
			close(output_fd);
		}
		execve(cmd->full_path, cmd->cmd_n_args, envp);
		perror("execve");
	}
}

void	close_fds(int fds[])
{
	int	i;

	i = 0;
	while (++i < 2)
	{
		if (fds[i] != -1)
			close(fds[i]);
	}
}

void	execute_commands(t_data *data, char **envp)
{
	int		input_fd;
	int		pipefd[2];
	int		output_fd;
	t_cmds	*cmd;
	pid_t	pid;

	input_fd = data->file_in;
	cmd = data->cmds;
	while (cmd != NULL)
	{
		if (cmd->next != NULL)
		{
			if (create_pipe(pipefd) != 0)
				exit(EXIT_FAILURE);
		}
		else
		{
			pipefd[0] = -1;
			pipefd[1] = -1;
		}
		if (cmd->next == NULL)
			output_fd = data->file_out;
		else
			output_fd = pipefd[1];
		if (cmd->exec == 1)
		{
			execute_command(cmd, input_fd, output_fd, envp);
		}
		else
		{
			ft_putstr_fd(data->program_name, 2);
			ft_putstr_fd(": command not found: ", 2);
			ft_putstr_fd(cmd->cmd, 2);
			ft_putchar_fd('\n', 2);
		}
		if (input_fd != data->file_in)
			close(input_fd);
		input_fd = pipefd[0];
		if (cmd->next != NULL && output_fd != data->file_out)
			close(output_fd);
		cmd = cmd->next;
		pipefd[0] = -1;
		pipefd[1] = -1;
	}
	while ((pid = wait(NULL)) > 0);
}

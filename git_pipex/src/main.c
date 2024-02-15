/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:00:32 by lmattern          #+#    #+#             */
/*   Updated: 2024/02/15 19:09:35 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	free_cmds(t_cmds *cmds)
{
	int	i;

	i = 0;
	if (cmds)
	{
		free(cmds->cmd);
		free(cmds->full_path);
		if (cmds->cmd_n_args)
		{
			while (cmds->cmd_n_args[i] != NULL)
				free(cmds->cmd_n_args[i++]);
			free(cmds->cmd_n_args);
		}
		free_cmds(cmds->next);
		free(cmds);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	init_n_check_arguments(argc, argv, &data);
	check_and_parse_cmd(argc, argv, envp, &data);
	//print_commands(data.cmds);
	open_input_file(data.file_in_name, &data);
	open_output_file(data.file_out_name, &data);
	execute_commands(&data, envp);
	free_cmds(data.cmds);
	return (EXIT_SUCCESS);
}

void	init_n_check_arguments(int argc, char **argv, t_data *data)
{
	char	*base_name;

	if (argc < 4)
	{
		ft_putstr_fd("Usage: ./pipex file_in cmd1 [cmd2 ...] [file_out]\n", 2);
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

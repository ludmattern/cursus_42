/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:00:32 by lmattern          #+#    #+#             */
/*   Updated: 2024/02/17 20:40:52 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	bool	status_fdi;
	bool	status_fdo;
	int		status_exec;

	init_n_check_arguments(argc, argv, &data);
	check_and_parse_cmd(argc, argv, envp, &data);
	status_fdi = open_input_file(data.file_in_name, &data);
	status_fdo = open_output_file(data.file_out_name, &data);
	status_exec = execute_commands(&data, envp);
	if (data.file_in != -1 && status_fdi)
		close(data.file_in);
	if (data.file_out != -1 && status_fdo)
		close(data.file_out);
	free_cmds(data.cmds);
	return (status_exec);
}

void	init_n_check_arguments(int argc, char **argv, t_data *data)
{
	char	*base_name;

	if (argc < 5)
	{
		ft_putstr_fd("Usage: ./pipex file_in cmd1 cmd2 ... [file_out]\n", 2);
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

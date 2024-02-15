/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_files.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:00:32 by lmattern          #+#    #+#             */
/*   Updated: 2024/02/15 13:08:23 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	open_input_file(char *file_name, t_data *data)
{
	data->exec_first = true;
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
		data->exec_first = false;
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
		free_cmds(data->cmds);
		exit(EXIT_FAILURE);
	}
}

void	close_fds(int *fds)
{
	int	i;

	i = 0;
	while (++i < 2)
	{
		if (fds[i] != -1)
			close(fds[i]);
	}
}

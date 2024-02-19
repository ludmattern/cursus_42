/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_files.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:00:32 by lmattern          #+#    #+#             */
/*   Updated: 2024/02/18 15:17:40 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

bool	open_input_file(char *file_name, t_data *data)
{
	data->exec_first = true;
	if (file_name && ft_strncmp(file_name, "/dev/urandom", 11) != 0)
		data->file_in = open(file_name, O_RDONLY);
	else
		data->file_in = -1;
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
		return (false);
	}
	return (true);
}

bool	open_output_file(char *file_name, t_data *data)
{
	struct s_cmds	*current;

	data->file_out = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data->file_out == -1)
	{
		current = data->cmds;
		while (current->next)
			current = current->next;
		current->pass = true;
		return (false);
	}
	return (true);
}

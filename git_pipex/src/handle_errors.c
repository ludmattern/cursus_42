/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:00:32 by lmattern          #+#    #+#             */
/*   Updated: 2024/02/17 16:05:37 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	display_outfile_error(t_data *data)
{
	ft_putstr_fd(data->program_name, 2);
	write(2, ": ", 2);
	ft_putchar_fd(ft_tolower((strerror(errno))[0]), 2);
	ft_putstr_fd(strerror(errno) + 1, 2);
	write(2, ": ", 2);
	ft_putstr_fd(data->file_out_name, 2);
	write(2, "\n", 1);
}

void	display_cmd_error(t_data *data, t_cmds *cmd)
{
	ft_putstr_fd(data->program_name, 2);
	ft_putstr_fd(": command not found: ", 2);
	ft_putstr_fd(cmd->cmd, 2);
	ft_putchar_fd('\n', 2);
}

void	display_file_error(t_data *data, t_cmds *cmd)
{
	ft_putstr_fd(data->program_name, 2);
	ft_putstr_fd(": no such file or directory: ", 2);
	ft_putstr_fd(cmd->cmd, 2);
	ft_putchar_fd('\n', 2);
}

void	display_slash_error(t_data *data, t_cmds *cmd)
{
	ft_putstr_fd(data->program_name, 2);
	ft_putstr_fd(": permission denied: ", 2);
	ft_putstr_fd(cmd->cmd, 2);
	ft_putchar_fd('\n', 2);
}

void	handle_cmd_err(char **cmd_n_args, t_data *data, char **paths, char *str)
{
	if (cmd_n_args)
		free_array(&cmd_n_args);
	if (data->cmds)
		free_cmds(data->cmds);
	if (paths)
		free_array(&paths);
	if (str)
		free(str);
	exit (EXIT_FAILURE);
}

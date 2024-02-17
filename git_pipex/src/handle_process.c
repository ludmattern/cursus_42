/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:34:50 by lmattern          #+#    #+#             */
/*   Updated: 2024/02/17 21:39:59 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	hdl_pipes(t_cmds **cmd, int pipefd[2], int *error_status, t_data *data)
{
	if ((*cmd)->next != NULL)
	{
		if (pipe(pipefd) != 0)
		{
			*error_status = -1;
			if ((*cmd)->input_fd != -1 && (*cmd)->input_fd != data->file_in)
			{
				close((*cmd)->input_fd);
				(*cmd)->input_fd = -1;
			}
			if ((*cmd)->output_fd != -1 && (*cmd)->next != NULL && \
			(*cmd)->output_fd != data->file_out)
			{
				close((*cmd)->output_fd);
				(*cmd)->output_fd = -1;
			}
			return (-1);
		}
	}
	else
	{
		pipefd[0] = -1;
		pipefd[1] = -1;
	}
	return (0);
}

int	wait_for_children(int *last_exit_status)
{
	pid_t	pid;
	int		status;

	while (true)
	{
		pid = wait(&status);
		if (pid <= 0)
			break ;
		if (WIFEXITED(status))
		{
			*last_exit_status = WEXITSTATUS(status);
		}
	}
	return (*last_exit_status);
}

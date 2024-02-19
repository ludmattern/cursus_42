/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cmds2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:46:41 by lmattern          #+#    #+#             */
/*   Updated: 2024/02/18 15:48:24 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	exec_or_display_error(t_cmds *cmd, char **envp, t_data *data, int pipefd[2])
{
	int	error;

	error = 0;
	if (cmd->pass == 1)
		error = display_outfile_error(data);
	else if (cmd->exec == 1)
		error = execute_command(cmd, envp, data, pipefd);
	else if (data->exec_first == true)
	{
		if (cmd->exec == 2)
			error = display_file_error(data, cmd);
		else if (cmd->exec == 3)
			error = display_slash_error(data, cmd);
		else
			error = display_cmd_error(data, cmd);
	}
	data->exec_first = true;
	return (error);
}

void	init_params(int *error_status, t_cmds **cmd, t_data *data)
{
	*error_status = 0;
	*cmd = data->cmds;
	(*cmd)->input_fd = data->file_in;
}

void	hld_exec_error(int error_status, int pipefd[2])
{
	if (error_status != 0)
	{
		if (pipefd[0] != -1)
		{
			close(pipefd[0]);
			pipefd[0] = -1;
		}
		if (pipefd[1] != -1)
		{
			close(pipefd[1]);
			pipefd[1] = -1;
		}
	}
}

void	close_and_reset_fds(t_cmds *cmd, int pipefd[2], t_data *data)
{
	if (cmd->input_fd != -1 && cmd->input_fd != data->file_in)
	{
		close(cmd->input_fd);
		cmd->input_fd = -1;
	}
	if (cmd->next != NULL)
		cmd->next->input_fd = pipefd[0];
	if (cmd->output_fd != -1 && cmd->next != NULL && \
	cmd->output_fd != data->file_out)
	{
		close(cmd->output_fd);
		cmd->output_fd = -1;
	}
	pipefd[0] = -1;
	pipefd[1] = -1;
}

int	execute_commands(t_data *data, char **envp)
{
	int		pipefd[2];
	t_cmds	*cmd;
	int		error_status;

	init_params(&error_status, &cmd, data);
	while (cmd != NULL)
	{
		if (hdl_pipes(&cmd, pipefd, &error_status, data) == -1)
			break ;
		if (cmd->next == NULL)
			cmd->output_fd = data->file_out;
		else
			cmd->output_fd = pipefd[1];
		error_status = exec_or_display_error(cmd, envp, data, pipefd);
		hld_exec_error(error_status, pipefd);
		close_and_reset_fds(cmd, pipefd, data);
		cmd = cmd->next;
	}
	return (wait_for_children(&error_status));
}

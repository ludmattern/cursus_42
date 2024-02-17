/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cmds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:46:41 by lmattern          #+#    #+#             */
/*   Updated: 2024/02/17 22:23:39 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	fork_error(t_cmds *cmd)
{
	if (cmd->input_fd != -1)
	{
		close(cmd->input_fd);
		cmd->input_fd = -1;
	}
	if (cmd->output_fd != -1)
	{
		close(cmd->output_fd);
		cmd->output_fd = -1;
	}
	return (-1);
}

void	handle_execve_error(t_cmds *cmd, t_data *data, int pipefd[2])
{
	perror("execve");
	if (cmd->input_fd != STDIN_FILENO)
		close(STDIN_FILENO);
	if (cmd->output_fd != STDOUT_FILENO)
		close(STDOUT_FILENO);
	if (data->file_in != -1)
		close(data->file_in);
	if (data->file_out != -1)
		close(data->file_out);
	free_cmds(data->cmds);
	if (pipefd[0] != -1)
		close(pipefd[0]);
	if (pipefd[1] != -1)
		close(pipefd[1]);
	exit(EXIT_FAILURE);
}

int	execute_command(t_cmds *cmd, char **envp, t_data *data, int pipefd[2])
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		if (cmd->input_fd != STDIN_FILENO)
		{
			dup2(cmd->input_fd, STDIN_FILENO);
			close(cmd->input_fd);
		}
		if (cmd->output_fd != STDOUT_FILENO)
		{
			dup2(cmd->output_fd, STDOUT_FILENO);
			close(cmd->output_fd);
		}
		execve(cmd->full_path, cmd->cmd_n_args, envp);
		handle_execve_error(cmd, data, pipefd);
	}
	else if (pid < 0)
		return (fork_error(cmd));
	return (0);
}

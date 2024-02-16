/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cmds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:46:41 by lmattern          #+#    #+#             */
/*   Updated: 2024/02/16 20:47:32 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	wait_for_children(void)
{
	pid_t	pid;

	while (true)
	{
		pid = wait(NULL);
		if (pid <= 0)
			break ;
	}
}

int	execute_command(t_cmds *cmd, char **envp)
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
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("fork");
		return (-1);
	}
	return (0);
}

int	execute_or_display_error(t_cmds *cmd, char **envp, t_data *data)
{
	if (cmd->exec == 1)
		return (execute_command(cmd, envp));
	else if (data->exec_first == true)
	{
		if (cmd->exec == 2)
			display_file_error(data, cmd);
		else if (cmd->exec == 3)
			display_slash_error(data, cmd);
		else
			display_cmd_error(data, cmd);
	}
	data->exec_first = true;
	return (0);
}

void	init_params(int *error_status, t_cmds **cmd, t_data *data)
{
	*error_status = 0;
	*cmd = data->cmds;
	(*cmd)->input_fd = data->file_in;
}

int	execute_commands(t_data *data, char **envp)
{
	int		pipefd[2];
	t_cmds	*cmd;
	int		error_status;

	init_params(&error_status, &cmd, data);
	while (cmd != NULL && error_status == 0)
	{
		handle_pipes(cmd, pipefd);
		if (cmd->next == NULL)
			cmd->output_fd = data->file_out;
		else
			cmd->output_fd = pipefd[1];
		error_status = execute_or_display_error(cmd, envp, data);
		if (cmd->input_fd != data->file_in)
			close(cmd->input_fd);
		if (cmd->next != NULL)
			cmd->next->input_fd = pipefd[0];
		if (cmd->next != NULL && cmd->output_fd != data->file_out)
			close(cmd->output_fd);
		cmd = cmd->next;
		pipefd[0] = -1;
		pipefd[1] = -1;
	}
	wait_for_children();
	return (error_status);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:00:32 by lmattern          #+#    #+#             */
/*   Updated: 2024/02/17 20:09:27 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

char	*check_pathed_cmd(char *cmd, t_data *data, char **cmd_n_args)
{
	char	*full_cmd_path;

	full_cmd_path = ft_strdup(cmd);
	if (!full_cmd_path)
		handle_cmd_err(cmd_n_args, data, NULL, full_cmd_path);
	if (access(full_cmd_path, X_OK) != 0)
	{
		free(full_cmd_path);
		return (NULL);
	}
	return (full_cmd_path);
}

int	initial_check(int *should_exec, char *cmd_str, char **full_cmd_path)
{
	int	i;

	i = 0;
	*should_exec = 0;
	(void)cmd_str;
	(void)full_cmd_path;
	return (0);
}

void	append_command(t_cmds **head, t_cmds *new_cmd)
{
	t_cmds	*last_cmd;

	if (*head == NULL)
		*head = new_cmd;
	else
	{
		last_cmd = *head;
		while (last_cmd->next != NULL)
			last_cmd = last_cmd->next;
		last_cmd->next = new_cmd;
	}
}

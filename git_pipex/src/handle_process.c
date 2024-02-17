/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:34:50 by lmattern          #+#    #+#             */
/*   Updated: 2024/02/17 18:27:00 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	handle_pipes(t_cmds *cmd, int pipefd[2], int *error_status)
{
	if (cmd->next != NULL)
	{
		if (pipe(pipefd) != 0)
		{
			*error_status = -1;
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

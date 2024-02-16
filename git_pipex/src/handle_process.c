/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:34:50 by lmattern          #+#    #+#             */
/*   Updated: 2024/02/16 20:49:05 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	handle_pipes(t_cmds *cmd, int pipefd[2])
{
	if (cmd->next != NULL)
	{
		if (pipe(pipefd) != 0)
		{
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		pipefd[0] = -1;
		pipefd[1] = -1;
	}
}

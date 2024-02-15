/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:00:32 by lmattern          #+#    #+#             */
/*   Updated: 2024/02/15 17:22:42 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	handle_cmd_err(char **cmd_n_args, t_data *data, char **paths, char *str)
{
	perror("malloc");
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

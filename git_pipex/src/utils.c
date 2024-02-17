/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:05:20 by lmattern          #+#    #+#             */
/*   Updated: 2024/02/17 20:09:25 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	get_env_path(char **envp, t_data *data)
{
	int	i;

	i = -1;
	data->path = NULL;
	while (envp[++i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			data->path = envp[i] + 5;
			return ;
		}
	}
	ft_putstr_fd("Path not found\n", 2);
	exit(EXIT_FAILURE);
}

void	free_cmds(t_cmds *cmds)
{
	int	i;

	i = 0;
	if (cmds)
	{
		free(cmds->cmd);
		free(cmds->full_path);
		if (cmds->cmd_n_args)
		{
			while (cmds->cmd_n_args[i] != NULL)
				free(cmds->cmd_n_args[i++]);
			free(cmds->cmd_n_args);
		}
		free_cmds(cmds->next);
		free(cmds);
	}
}

void	free_array(char ***array)
{
	int	i;

	i = 0;
	while ((*array)[i] != NULL)
		free((*array)[i++]);
	free(*array);
}

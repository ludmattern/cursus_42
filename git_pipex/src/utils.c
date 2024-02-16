/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:05:20 by lmattern          #+#    #+#             */
/*   Updated: 2024/02/16 15:47:33 by lmattern         ###   ########.fr       */
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
/*
void	print_commands(const t_cmds *cmds)
{
	const t_cmds	*current_cmd;
	int				cmd_index;
	char			**arg;

	current_cmd = cmds;
	cmd_index = 1;
	while (current_cmd)
	{
		printf("Command #%d:\n", cmd_index++);
		printf("  Command: %s\n", current_cmd->cmd);
		printf("  should exec: %i\n", current_cmd->exec);
		if (current_cmd->full_path)
			printf("  Full Path: %s\n", current_cmd->full_path);
		else
			printf("  Full Path: Command not found or path not set\n");
		if (current_cmd->cmd_n_args)
		{
			printf("  Arguments: ");
			arg = current_cmd->cmd_n_args;
			while (*arg)
			{
				printf("%s, ", *arg);
				arg++;
			}
			printf("\n");
		}
		else
			printf("  Arguments: None\n");
		current_cmd = current_cmd->next;
		printf("\n");
	}
	if (cmd_index == 1)
		printf("No commands to display.\n");
}
*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:00:32 by lmattern          #+#    #+#             */
/*   Updated: 2024/02/17 20:09:28 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	check_and_parse_cmd(int argc, char **argv, char **envp, t_data *data)
{
	struct s_cmds	*current;
	int				i;

	get_env_path(envp, data);
	data->cmds = NULL;
	i = 2;
	while (i < argc - 1)
		add_command(data, argv[i++]);
	current = data->cmds;
	while (current->next)
		current = current->next;
	current->last = true;
}

char	*get_cmd(char *path, char *cmd, t_data *data, char **cmd_n_args)
{
	char	**paths;
	char	*cmd_path;
	char	*full_cmd_path;
	int		i;

	paths = ft_split(path, ':');
	if (!paths)
		handle_cmd_err(cmd_n_args, data, NULL, NULL);
	i = 0;
	while (paths[++i] != NULL)
	{
		cmd_path = ft_strjoin(paths[i], "/");
		if (!cmd_path)
			handle_cmd_err(cmd_n_args, data, paths, NULL);
		full_cmd_path = ft_strjoin(cmd_path, cmd);
		free(cmd_path);
		if (!full_cmd_path)
			handle_cmd_err(cmd_n_args, data, paths, NULL);
		if (access(full_cmd_path, X_OK) == 0)
			return (free_array(&paths), full_cmd_path);
		free(full_cmd_path);
	}
	return (free_array(&paths), NULL);
}

t_cmds	*new_c(char *c_str, char *full_cmd_path, char **cmd_n_args, int exec)
{
	t_cmds	*new_cmd;
	char	*first_space;

	new_cmd = NULL;
	new_cmd = malloc(sizeof(t_cmds));
	if (!new_cmd)
		return (perror("malloc"), NULL);
	first_space = ft_strchr(c_str, ' ');
	if (first_space == NULL)
		new_cmd->cmd = ft_strdup(c_str);
	else
		new_cmd->cmd = ft_strndup(c_str, first_space - c_str);
	if (!new_cmd->cmd)
		return (free(new_cmd), perror("malloc"), NULL);
	new_cmd->full_path = full_cmd_path;
	new_cmd->cmd_n_args = cmd_n_args;
	new_cmd->exec = exec;
	new_cmd->last = false;
	new_cmd->input_fd = -1;
	new_cmd->output_fd = -1;
	new_cmd->pass = false;
	new_cmd->outfile_error = NULL;
	new_cmd->next = NULL;
	return (new_cmd);
}

void	add_command(t_data *data, char *cmd_str)
{
	char	**cmd_n_args;
	char	*full_cmd_path;
	int		should_exec;
	t_cmds	*new_cmd;
	int		check;

	cmd_n_args = parse_cmd(cmd_str, data);
	check = initial_check(&should_exec, cmd_str, &full_cmd_path);
	if (check != -1 && !cmd_n_args[0])
		full_cmd_path = NULL;
	else if (check != -1 && ft_strchr(cmd_n_args[0], '/'))
	{
		full_cmd_path = check_pathed_cmd(cmd_n_args[0], data, cmd_n_args);
		if (!full_cmd_path)
			should_exec = 2;
	}
	else if (check != -1)
		full_cmd_path = get_cmd(data->path, cmd_n_args[0], data, cmd_n_args);
	if (full_cmd_path && !should_exec)
		should_exec = 1;
	new_cmd = new_c(cmd_str, full_cmd_path, cmd_n_args, should_exec);
	if (!new_cmd)
		handle_cmd_err(cmd_n_args, data, NULL, full_cmd_path);
	append_command(&(data->cmds), new_cmd);
}

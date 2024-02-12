/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secondary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:00:32 by lmattern          #+#    #+#             */
/*   Updated: 2024/02/12 18:58:38 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	free_array(char ***array)
{
	int	i;

	i = 0;
	while ((*array)[i] != NULL)
		free((*array)[i++]);
	free(*array);
}

void	check_and_parse_cmd(int argc, char **argv, char **envp, t_data *data)
{
	int	i;

	get_env_path(envp, data);
	data->cmds = NULL;
	i = 2;
	while (i < argc - 1)
		add_command(data, argv[i++]);
}

void	get_env_path(char **envp, t_data *data)
{
	int	i;

	i = 0;
	data->path = NULL;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			data->path = envp[i] + 5;
			return ;
		}
		i++;
	}
	fprintf(stderr, "Path not found\n");
	exit(EXIT_FAILURE);
}

char	*get_cmd(char *path, char *cmd)
{
	char	**paths;
	char	*cmd_path;
	char	*full_cmd_path;
	int		i;

	paths = ft_split(path, ':');
	if (!paths)
		return (NULL);
	i = 1;
	while (paths[i] != NULL)
	{
		cmd_path = ft_strjoin(paths[i], "/");
		full_cmd_path = ft_strjoin(cmd_path, cmd);
		free(cmd_path);
		if (access(full_cmd_path, X_OK) == 0)
			return (free_array(&paths), full_cmd_path);
		free(full_cmd_path);
		i++;
	}
	free_array(&paths);
	return (NULL);
}

int	count_args(const char *cmd_str)
{
	int			args_count;
	bool		in_quotes;
	const char	*p;

	args_count = 0;
	in_quotes = false;
	p = cmd_str;
	while (*p == ' ')
		p++;
	while (*p)
	{
		if (*p == '\'')
		{
			in_quotes = !in_quotes;
			p++;
			continue ;
		}
		if (*p == ' ' && !in_quotes)
		{
			args_count++;
			while (*p == ' ')
				p++;
			continue ;
		}
		p++;
	}
	if (p != cmd_str && *(p - 1) != ' ')
		args_count++;
	return (args_count);
}

char	*ft_strndup(const char *s, size_t n)
{
	char	*dup;
	size_t	len;

	len = ft_strlen(s);
	if (n < len)
		len = n;
	dup = (char *)malloc((len + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, s, len + 1);
	return (dup);
}

char	**parse_cmd(const char *cmd_str)
{
	char		**args;
	int			arg_index;
	bool		in_quotes;
	const char	*arg_start;
	const char	*p;
	int			length;

	arg_index = 0;
	in_quotes = false;
	arg_start = NULL;
	p = cmd_str;
	args = malloc((count_args(cmd_str) + 1) * sizeof(char *));
	if (!args)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	while (*p)
	{
		if (*p == '\'')
		{
			in_quotes = !in_quotes;
			if (in_quotes)
			{
				arg_start = p + 1;
			}
			else
			{
				length = p - arg_start;
				args[arg_index++] = ft_strndup(arg_start, length);
				arg_start = NULL;
			}
		}
		else if (!in_quotes && (*p == ' ' || *(p + 1) == '\0'))
		{
			if (arg_start)
			{
				length = p - arg_start + (*(p + 1) == '\0');
				args[arg_index++] = ft_strndup(arg_start, length);
				arg_start = NULL;
			}
		}
		else if (!in_quotes && *p != ' ' && !arg_start)
		{
			arg_start = p;
		}
		p++;
	}
	args[arg_index] = NULL;
	return (args);
}

void	add_command(t_data *data, char *cmd_str)
{
	char	**cmd_n_args;
	char	*full_cmd_path;
	bool	should_exec;
	t_cmds	*new_cmd;

	cmd_n_args = parse_cmd(cmd_str);
	full_cmd_path = get_cmd(data->path, cmd_n_args[0]);
	if (full_cmd_path)
		should_exec = 1;
	else
		should_exec = 0;
	new_cmd = create_new_command(cmd_str, full_cmd_path, cmd_n_args, should_exec);
	append_command(&(data->cmds), new_cmd);
}

t_cmds	*create_new_command(char *cmd_str, char *full_cmd_path, char **cmd_n_args, bool should_exec)
{
	t_cmds	*new_cmd;
	char	*first_space;

	new_cmd = malloc(sizeof(t_cmds));
	if (!new_cmd)
	{
		perror("Failed to allocate memory for new command");
		exit(EXIT_FAILURE);
	}
	first_space = ft_strchr(cmd_str, ' ');
	if (first_space == NULL)
		new_cmd->cmd = ft_strdup(cmd_str);
	else
		new_cmd->cmd = ft_strndup(cmd_str, first_space - cmd_str);
	if (!new_cmd->cmd)
	{
		perror("Failed to allocate memory for command name");
		exit(EXIT_FAILURE);
	}
	new_cmd->full_path = full_cmd_path;
	new_cmd->cmd_n_args = cmd_n_args;
	new_cmd->exec = should_exec;
	new_cmd->next = NULL;
	return (new_cmd);
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

void	print_commands(const t_cmds *cmds)
{
	const t_cmds	*current_cmd;
	int				cmd_index;
	char			**arg;

	current_cmd = cmds;
	cmd_index = 1;
	while (current_cmd != NULL)
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
			while (*arg != NULL)
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

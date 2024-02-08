/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secondary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:00:32 by lmattern          #+#    #+#             */
/*   Updated: 2024/02/08 15:37:28 by lmattern         ###   ########.fr       */
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
	get_env_path(envp, data);
	data->cmds = NULL;

	for (int i = 2; i < argc - 1; i++) {
		add_command(data, argv[i]/*, envp*/);
	}

	data->file_in = open(argv[1], O_RDONLY);
	if (data->file_in < 0) {
		perror("Error opening input file");
		exit(EXIT_FAILURE);
	}

	data->file_out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data->file_out < 0) {
		perror("Error opening output file");
		exit(EXIT_FAILURE);
	}
}


void	get_env_path(char **envp, t_data *data) {
	int i = 0;
	data->path = NULL;
	while (envp[i] != NULL) {
		if (ft_strncmp(envp[i], "PATH=", 5) == 0) {
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
	char **paths = ft_split(path, ':');
	if (!paths)
		return NULL;
	for (int i = 0; paths[i] != NULL; ++i)
	{
		char *cmd_path = ft_strjoin(paths[i], "/");
		char *full_cmd_path = ft_strjoin(cmd_path, cmd);
		free(cmd_path);
		if (access(full_cmd_path, X_OK) == 0)
			return (free_array(&paths), full_cmd_path);
		free(full_cmd_path);
	}
	free_array(&paths);
	return NULL;
}

// Fonction pour compter le nombre d'arguments dans la commande
int count_args(const char *cmd_str) {
    int args_count = 0;
    bool in_quotes = false;
    const char *p = cmd_str;

    // Ignorer les espaces de début
    while (*p == ' ') p++;

    while (*p) {
        if (*p == '\'') {
            // Basculer l'état de in_quotes
            in_quotes = !in_quotes;
            p++;
            continue;
        }

        if (*p == ' ' && !in_quotes) {
            // Un nouvel argument commence
            args_count++;
            while (*p == ' ') p++; // Ignorer les espaces multiples
            continue;
        }
        p++;
    }

    // Compter le dernier argument si la chaîne ne se termine pas par des espaces
    if (p != cmd_str && *(p - 1) != ' ') args_count++;

    return args_count;
}

char *ft_strndup(const char *s, size_t n) {
    char *dup;
    size_t len = ft_strlen(s);
    if (n < len) {
        len = n;
    }

    // Allocation pour len caractères + '\0'
    dup = (char *)malloc((len + 1) * sizeof(char));
    if (!dup) {
        return NULL; // Échec de l'allocation
    }

    // Copie sécurisée de la chaîne avec ft_strlcpy
    ft_strlcpy(dup, s, len + 1); // +1 pour inclure le caractère nul de terminaison

    return dup;
}

char **parse_cmd(const char *cmd_str) {
	printf("Debug cmd_str before parsing: %s\n", cmd_str);

    int args_count = count_args(cmd_str) + 1; // +1 pour NULL à la fin
    char **args = malloc(args_count * sizeof(char *));
    if (!args) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    int arg_index = 0;
    bool in_quotes = false;
    const char *arg_start = NULL; // Début de l'argument courant

    for (const char *p = cmd_str; *p; p++) {
        if (*p == '\'') {
            in_quotes = !in_quotes;
            if (in_quotes) arg_start = p + 1; // Commencer après le guillemet
            else {
                // Fin de l'argument entre guillemets
                int length = p - arg_start;
                args[arg_index] = ft_strndup(arg_start, length);
                arg_index++;
            }
            continue;
        }

        if (!in_quotes) {
            if ((*p == ' ' || *(p + 1) == '\0') && arg_start) {
                int length = p - arg_start + (*(p + 1) == '\0' && *p != ' ');
                args[arg_index] = ft_strndup(arg_start, length);
                arg_index++;
                arg_start = NULL; // Réinitialiser pour le prochain argument
            } else if (*p != ' ' && !arg_start) {
                // Début d'un nouvel argument
                arg_start = p;
            }
        }
    }

    args[arg_index] = NULL; // Terminer le tableau avec NULL
    return args;
}


void	add_command(t_data *data, char *cmd_str)
{
	char **cmd_n_args = parse_cmd(cmd_str);
	char *full_cmd_path = get_cmd(data->path, cmd_n_args[0]);
	bool should_exec = full_cmd_path != NULL;
	t_cmds *new_cmd = create_new_command(cmd_str, full_cmd_path, cmd_n_args, should_exec);
	append_command(&(data->cmds), new_cmd);
}


t_cmds	*create_new_command(char *cmd_str, char *full_cmd_path, char **cmd_n_args, bool should_exec) {
	t_cmds *new_cmd = malloc(sizeof(t_cmds));
	if (!new_cmd) {
		perror("Failed to allocate memory for new command");
		exit(EXIT_FAILURE);
	}
	new_cmd->cmd = ft_strdup(cmd_str);
	new_cmd->full_path = full_cmd_path;
	new_cmd->cmd_n_args = cmd_n_args;
	new_cmd->exec = should_exec;
	new_cmd->next = NULL;

	return new_cmd;
}

void	append_command(t_cmds **head, t_cmds *new_cmd) {
	if (*head == NULL) {
		*head = new_cmd;
	} else {
		t_cmds *last_cmd = *head;
		while (last_cmd->next != NULL) {
			last_cmd = last_cmd->next;
		}
		last_cmd->next = new_cmd;
	}
}

void print_commands(const t_cmds *cmds) {
    const t_cmds *current_cmd = cmds;
    int cmd_index = 1;

    while (current_cmd != NULL) {
        printf("Command #%d:\n", cmd_index++);
        printf("  Command: %s\n", current_cmd->cmd);
		printf("  should exec: %i\n", current_cmd->exec);
        if (current_cmd->full_path) {
            printf("  Full Path: %s\n", current_cmd->full_path);
        } else {
            printf("  Full Path: Command not found or path not set\n");
        }
        if (current_cmd->cmd_n_args) {
            printf("  Arguments: ");
            for (char **arg = current_cmd->cmd_n_args; *arg != NULL; arg++) {
                printf("'%s' ", *arg);
            }
            printf("\n");
        } else {
            printf("  Arguments: None\n");
        }
        current_cmd = current_cmd->next;
        printf("\n"); // Ajoute une ligne vide pour séparer les commandes
    }
    if (cmd_index == 1) {
        printf("No commands to display.\n");
    }
}

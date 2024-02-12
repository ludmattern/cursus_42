/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 09:26:11 by lmattern          #+#    #+#             */
/*   Updated: 2024/02/12 18:28:30 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include "../lib/libft/inc/libft.h"
# include "../lib/ft_printf/ft_printf.h"
# include "../lib/libft/inc/get_next_line.h"

typedef struct s_cmds
{
	char			*cmd;
	char			*full_path;
	char			**cmd_n_args;
	bool			exec;
	struct s_cmds	*next;
}	t_cmds;

typedef struct s_data
{
	char	*program_name;
	char	*file_in_name;
	char	*file_out_name;
	int		file_in;
	int		file_out;
	char	*path;
	t_cmds	*cmds;
}	t_data;

void	init_n_check_arguments(int argc, char **argv, t_data *data);
void	open_input_file(char *file_name, t_data *data);
void	open_output_file(char *file_name, t_data *data);
void	create_and_execute_child_processes(char *cmd1, char *cmd2, t_data *data);
void	execute_first_command(char *cmd, int file_in, int pipefd[]);
void	execute_second_command(char *cmd, int file_out, int pipefd[]);
void	close_pipe_ends(int pipefd[2]);
void	check_and_get_cmd(char *cmd1, char *cmd2, char **envp, t_data *data);
void	print_commands(const t_cmds *cmds);
void	append_command(t_cmds **head, t_cmds *new_cmd);
t_cmds	*create_new_command(char *cmd_str, char *full_cmd_path, char **cmd_n_args, bool should_exec);
void	add_command(t_data *data, char *cmd_str);
char	*get_cmd(char *path, char *cmd);
void	get_env_path(char **envp, t_data *data);
void	check_and_parse_cmd(int argc, char **argv, char **envp, t_data *data);
void	free_array(char ***array);
void	execute_commands(t_data *data, char **envp);

#endif
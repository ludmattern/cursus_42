/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 09:26:11 by lmattern          #+#    #+#             */
/*   Updated: 2024/02/18 15:47:21 by lmattern         ###   ########.fr       */
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
	int				exec;
	int				input_fd;
	int				output_fd;
	bool			last;
	bool			pass;
	char			*outfile_error;
	struct s_cmds	*next;
}	t_cmds;

typedef struct s_data
{
	char	*program_name;
	char	*file_in_name;
	char	*file_out_name;
	int		file_in;
	int		exec_first;
	int		file_out;
	char	*path;
	t_cmds	*cmds;
}	t_data;

typedef struct s_parser
{
	char		**args;
	const char	*arg_start;
	int			arg_index;
	bool		in_quotes;
}	t_parser;

/*
checking
*/
void	init_n_check_arguments(int argc, char **argv, t_data *data);

/*
handling commands
*/
char	*get_cmd(char *path, char *cmd, t_data *data, char **cmd_n_args);
int		execute_commands(t_data *data, char **envp);
int		execute_command(t_cmds *cmd, char **envp, t_data *data, int pipefd[2]);

/*
parsing
*/
void	check_and_parse_cmd(int argc, char **argv, char **envp, t_data *data);
char	**parse_cmd(const char *cmd_str, t_data *data);
int		count_args(const char *cmd_str);
void	add_command(t_data *data, char *cmd_str);
void	append_command(t_cmds **head, t_cmds *new_cmd);
t_cmds	*new_c(char *c_str, char *c_path, char **c_n_args, int exec);
int		initial_check(int *should_exec, char *cmd_str, char **full_cmd_path);
char	*check_pathed_cmd(char *cmd, t_data *data, char **cmd_n_args);

/*
utils
*/
void	get_env_path(char **envp, t_data *data);
void	free_cmds(t_cmds *cmds);
void	free_array(char ***array);

/*
handling files
*/
bool	open_input_file(char *file_name, t_data *data);
bool	open_output_file(char *file_name, t_data *data);

/*
handling errors
*/
void	handle_cmd_err(char **cmd_args, t_data *data, char **paths, char *str);
int		display_cmd_error(t_data *data, t_cmds *cmd);
int		display_file_error(t_data *data, t_cmds *cmd);
int		display_slash_error(t_data *data, t_cmds *cmd);
int		display_outfile_error(t_data *data);

/*
handling process
*/
int		create_pipe(int pipefd[2]);
int		hdl_pipes(t_cmds **cmd, int pipefd[2], int *error_status, t_data *data);
int		wait_for_children(int *last_exit_status);

#endif
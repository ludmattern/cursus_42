/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:03:09 by lmattern          #+#    #+#             */
/*   Updated: 2023/11/22 14:02:58 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct	s_list
{
	char		*content;
	struct s_list	*next;
}			t_list;

char	*get_next_line(int fd);
int 	is_newline(t_list *buffer);
t_list	*ft_lstlast(t_list *buffer);
void	store_next_line(int fd, t_list **buffer);
void	buffer_join(t_list **buffer, char *temp, ssize_t read_state);
void	extract_line(t_list *buffer, char **line);
void	malloc_line(char **line, t_list *buffer);
void	trim_prev_line(t_list **buffer);
size_t 	ft_strlen(const char *str);
void	free_buffer(t_list *buffer);

#endif

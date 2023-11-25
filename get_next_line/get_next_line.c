/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:03:09 by lmattern          #+#    #+#             */
/*   Updated: 2023/11/22 14:02:58 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*buffer = NULL;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) == -1)
		return (NULL);
	line = NULL;
	store_next_line(fd, &buffer);
	if (!buffer)
		return (NULL);
	extract_line(buffer, &line);
	trim_prev_line(&buffer);
	if (line[0] == '\0')
	{
		free_buffer(buffer);
		buffer = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}

void	store_next_line(int fd, t_list **buffer)
{
	char	*temp;
	ssize_t	read_status;

	read_status = 1;
	while (!is_newline(*buffer) && read_status != 0)
	{
		temp = malloc(BUFFER_SIZE + 1);
		if (!temp)
			return ;
		read_status = read(fd, temp, BUFFER_SIZE);
		if (read_status == -1 || (read_status == 0 && !(*buffer)))
		{
			free(temp);
			return ;
		}
		temp[read_status] = '\0';
		buffer_join(buffer, temp, read_status);
		free(temp);
	}
}

void	buffer_join(t_list **buffer, char *temp, ssize_t read_status)
{
	int		i;
	t_list	*last;
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->content = malloc(read_status + 1);
	if (!new_node->content)
		return ;
	i = 0;
	while (temp[i] && i < read_status)
	{
		new_node->content[i] = temp[i];
		i++;
	}
	new_node->content[i] = '\0';
	if (!(*buffer))
	{
		*buffer = new_node;
		return ;
	}
	last = ft_lstlast(*buffer);
	last->next = new_node;
}

void	extract_line(t_list *buffer, char **line)
{
	int	i;
	int	j;

	if (!buffer)
		return ;
	malloc_line(line, buffer);
	if (!(*line))
		return ;
	j = 0;
	while (buffer)
	{
		i = 0;
		while (buffer->content[i])
		{
			if (buffer->content[i] == '\n')
			{
				(*line)[j++] = buffer->content[i];
				break ;
			}
			(*line)[j++] = buffer->content[i++];
		}
		buffer = buffer->next;
	}
	(*line)[j] = '\0';
}

void	trim_prev_line(t_list **buffer)
{
	t_list	*last;
	t_list	*clean_node;
	int		i;
	int		j;

	clean_node = malloc(sizeof(t_list));
	if (!buffer || !clean_node)
		return ;
	clean_node->next = NULL;
	last = ft_lstlast(*buffer);
	i = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content && last->content[i] == '\n')
		i++;
	clean_node->content = malloc((ft_strlen(last->content) - i) + 1);
	if (!(clean_node->content))
		return ;
	j = 0;
	while (last->content[i])
		clean_node->content[j++] = last->content[i++];
	clean_node->content[j] = '\0';
	free_buffer(*buffer);
	*buffer = clean_node;
}

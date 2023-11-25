/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:03:09 by lmattern          #+#    #+#             */
/*   Updated: 2023/11/22 14:02:58 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	is_newline(t_list *buffer)
{
	int		i;
	t_list	*current;

	if (!buffer)
		return (0);
	current = ft_lstlast(buffer);
	i = 0;
	while (current->content[i])
	{
		if (current->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

t_list	*ft_lstlast(t_list *buffer)
{
	t_list	*current;

	current = buffer;
	while (current && current->next)
		current = current->next;
	return (current);
}

void	malloc_line(char **line, t_list *buffer)
{
	int	i;
	int	len;

	len = 0;
	while (buffer)
	{
		i = 0;
		while (buffer->content[i])
		{
			if (buffer->content[i] == '\n')
			{
				len++;
				break ;
			}
			len++;
			i++;
		}
		buffer = buffer->next;
	}
	*line = malloc(len + 1);
}

void	free_buffer(t_list *buffer)
{
	t_list	*current;
	t_list	*next;

	current = buffer;
	while (current)
	{
		free(current->content);
		next = current->next;
		free(current);
		current = next;
	}
}

size_t	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (*(str++))
		len++;
	return (len);
}
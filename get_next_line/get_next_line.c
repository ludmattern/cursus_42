/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:03:09 by lmattern          #+#    #+#             */
/*   Updated: 2023/11/22 15:53:26 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
# define BUFFER_SIZE 5

char	*get_next_line(int fd)
{
	char	buf[BUFFER_SIZE + 1];
	static char	*temp = NULL;
	char	*line;
	size_t	i;

	if (fd < 0 || BUFFER_SIZE <= 0)
			return (NULL);
	line = NULL;
	while (read(fd, buf, BUFFER_SIZE) && !ft_strchr(buf, '\n'))
	{
		temp = ft_strjoin(temp, buf);
		if (!temp)
			return (NULL);
	}
	i = 0;
	while (!ft_strchr('\n', temp[i]) || temp[i])
		i++;

	line = ft_substr(temp, 0, i);
	free(temp);
	return(line);
}

#include <fcntl.h>
#include <stdio.h>

int	main()
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	printf(get_next_line(fd));

}

//read : -1 pb, 1 ok, 0 fin de fichier
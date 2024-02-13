/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 11:11:40 by lmattern          #+#    #+#             */
/*   Updated: 2024/01/15 16:45:33 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

/* 
counts lines of the input file
*/
size_t	count_file_lines(int fd, size_t i)
{
	ssize_t	read_status;
	char	buf[4096];
	size_t	line_count;

	line_count = 0;
	if (fd == -1)
		inpt_err("Error opening file", fd, NULL, 0);
	read_status = 1;
	while (read_status > 0)
	{
		read_status = read(fd, buf, 4096);
		if (read_status == -1)
			inpt_err("Error reading file", fd, NULL, 0);
		if (!read_status)
			break ;
		i = 0;
		while (i < (size_t)read_status)
			if (buf[i++] == '\n')
				line_count++;
	}
	if (!read_status && i > 0 && buf[i - 1] != '\n')
		line_count++;
	close(fd);
	return (line_count);
}

/* 
fills the input array according to the content of the input file
*/
void	parse_input(char ***tab, const char *ground_file)
{
	int		fd;
	char	*line;
	size_t	nb_lines;
	size_t	i;

	nb_lines = count_file_lines(open(ground_file, O_RDONLY), 0);
	if (!nb_lines)
		inpt_err("Error empty file", -1, NULL, 0);
	fd = open(ground_file, O_RDONLY);
	if (fd == -1)
		inpt_err("Error opening file", fd, NULL, 0);
	*tab = ft_calloc((nb_lines + 1), sizeof(char *));
	if (!(*tab))
		inpt_err("Error allocating memory", fd, NULL, 0);
	i = 0;
	while (i < nb_lines)
	{
		line = get_next_line(fd);
		if (!line)
			inpt_err("Error reading file", fd, tab, i);
		(*tab)[i++] = line;
	}
	get_next_line(-1);
	close(fd);
}

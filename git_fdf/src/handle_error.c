/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 11:18:36 by lmattern          #+#    #+#             */
/*   Updated: 2024/01/14 17:14:55 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

/*
Similar to clean_exit() but determines what level of cleaning it has to do 
according to the arguments before exiting the program.
*/
void	mlx_err(const char *msg, t_mlx *data, t_map	**map)
{
	if (data->img_ptr)
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	map_clear(map);
	ft_putstr_fd(msg, 2);
	exit(EXIT_FAILURE);
}

/* 
Exits with a message and closes file or/and frees the input array.
*/
void	inpt_err(const char *msg, int fd, char ***tab, size_t tab_len)
{
	size_t	i;

	i = 0;
	if (fd > 0)
		close(fd);
	if (tab && *tab)
	{
		while (i < tab_len)
			free((*tab)[i++]);
		free(*tab);
	}
	ft_putstr_fd(msg, 2);
	exit(EXIT_FAILURE);
}

/* 
Exits with a message and frees the layout arrays.
*/
void	map_err(const char *msg, char ***tab, char ***tkn, t_map **map)
{
	size_t	i;

	i = 0;
	if (tab && *tab)
		ft_free_array(tab);
	if (tkn && *tkn)
		ft_free_array(tkn);
	if (map && *map)
		map_clear(map);
	ft_putstr_fd(msg, 2);
	exit(EXIT_FAILURE);
}

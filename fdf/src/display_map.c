/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 15:49:06 by lmattern          #+#    #+#             */
/*   Updated: 2024/01/14 21:29:09 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

/*
Ends mlx loop if the ESC key is hit.
*/
void	deal_key(int keycode, t_mlx *data)
{
	if (keycode == 65307)
		mlx_loop_end(data->mlx_ptr);
}

/*
Ends mlx loop if the window red cross is clicked.
*/
void	close_event(t_mlx *data)
{
	mlx_loop_end(data->mlx_ptr);
}

/*
Initializes some data values to further use and error checks.
*/
void	data_init(t_mlx *data)
{
	data->width = 2000;
	data->height = 1950;
	data->win_ptr = NULL;
	data->img_ptr = NULL;
	data->buffer = NULL;
}

/*
Frees all ressources and ends the program.
*/
void	clean_exit(t_mlx *data, t_map **map)
{
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	map_clear(map);
	exit(EXIT_SUCCESS);
}

/*
Draws image from map and displays it into the window then exits the program.
*/
void	display_map(t_mlx *data, t_map **map)
{
	data_init(data);
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		mlx_err("Error mlx initialisation", data, map);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->width, data->height, \
					"Worst FDF you've ever seen");
	if (!data->win_ptr)
		mlx_err("Error mlx window creation", data, map);
	data->img_ptr = mlx_new_image(data->mlx_ptr, data->width, data->height);
	if (!data->img_ptr)
		mlx_err("Error mlx img creation", data, map);
	data->buffer = mlx_get_data_addr(data->img_ptr, &data->pixel_bits, \
					&data->line_bytes, &data->endian);
	if (!data->buffer)
		mlx_err("Error mlx img allocation", data, map);
	draw_pixels_to_image(*data, *map);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	mlx_key_hook(data->win_ptr, (void *)deal_key, data);
	mlx_hook(data->win_ptr, 17, 0, (void *)close_event, data);
	mlx_loop(data->mlx_ptr);
	clean_exit(data, map);
}

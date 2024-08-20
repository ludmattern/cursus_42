/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:21:25 by lmattern          #+#    #+#             */
/*   Updated: 2024/01/14 21:34:28 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

/*
Initializes bounds struct with accurates value to be used into find max bounds 
function.
*/
void	init_bounds(t_bounds *bounds)
{
	bounds->min_x = INT_MAX;
	bounds->min_y = INT_MAX;
	bounds->max_x = INT_MIN;
	bounds->max_y = INT_MIN;
}

/*
Browses map keeping track on minimum and maximum values.
*/
t_bounds	find_max_bounds(t_map **map)
{
	t_bounds	bounds;
	int			i;

	i = -1;
	init_bounds(&bounds);
	while (++i < (*map)->height)
		browse_map_data((*map)->points[i], &bounds, map);
	return (bounds);
}

/*
Calculates the right zoom factor to apply to the map in order to make it fit 
inside the image.
*/
double	calculate_zoom_factor(t_bounds bounds)
{
	double	zoom_factor_x;
	double	zoom_factor_y;

	zoom_factor_x = 1.0;
	zoom_factor_y = 1.0;
	if (bounds.max_x - bounds.min_x > 0)
		zoom_factor_x = 2000.0 / (bounds.max_x - bounds.min_x + 1);
	if (bounds.max_y - bounds.min_y > 0)
		zoom_factor_y = 1950.0 / (bounds.max_y - bounds.min_y + 1);
	if (zoom_factor_x < zoom_factor_y)
		return (zoom_factor_x);
	else
		return (zoom_factor_y);
}

/*
Calculates the offsets to apply to the map to center it in the middle of the 
image.
*/
void	calc_offsets(t_bounds *offsets, t_bounds bounds, double zoom)
{
	int	zoomed_width;
	int	zoomed_height;

	zoomed_width = (int)((bounds.max_x - bounds.min_x) * zoom);
	zoomed_height = (int)((bounds.max_y - bounds.min_y) * zoom);
	offsets->max_x = (2000 - zoomed_width) / 2 - (int)(bounds.min_x * zoom);
	offsets->max_y = (1950 - zoomed_height) / 2 - (int)(bounds.min_y * zoom);
}

/*
Applies offset and zoom value to center the map inside the image.
*/
void	adjust_scale_and_pos(t_map **map)
{
	t_bounds	bounds;
	t_bounds	offsets;
	t_point		*tmp_point;
	double		zoom_factor;
	int			i;

	bounds = find_max_bounds(map);
	zoom_factor = calculate_zoom_factor(bounds);
	calc_offsets(&offsets, bounds, zoom_factor);
	i = -1;
	while (++i < (*map)->height)
	{
		tmp_point = (*map)->points[i];
		while (tmp_point != NULL)
		{
			tmp_point->x = (int)(tmp_point->x * zoom_factor) + offsets.max_x;
			tmp_point->y = (int)(tmp_point->y * zoom_factor) + offsets.max_y;
			tmp_point = tmp_point->next;
		}
	}
}

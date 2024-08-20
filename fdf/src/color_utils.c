/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 21:09:17 by lmattern          #+#    #+#             */
/*   Updated: 2024/01/14 21:30:55 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

/*
Calculates a value that is a linear interpolation between start and end, based 
on t. The result is determined by how far t is between 0 and 1.
*/
int	interpolation(int start, int end, float t)
{
	int	result;

	result = (int)(start + t * (end - start));
	return (result);
}

/*
Calculates the color between a start and end color. It extracts and interpolates
each RGB component and combines them into a single color.
*/
int	interpolate_color(t_color *color)
{
	color->red = interpolation((color->start_color >> 16) & 0xFF, \
					(color->end_color >> 16) & 0xFF, color->progress);
	color->green = interpolation((color->start_color >> 8) & 0xFF, \
					(color->end_color >> 8) & 0xFF, color->progress);
	color->blue = interpolation(color->start_color & 0xFF, color->end_color & \
					0xFF, color->progress);
	return ((color->red << 16) | (color->green << 8) | color->blue);
}

/*
Initialize the starting and ending color based on the points altitudes.
*/
void	init_color(t_color *color, t_point *s, t_point *e, t_map *map)
{
	color->start_color = altitude_to_color(s->z, map->min_z, map->max_z);
	color->end_color = altitude_to_color(e->z, map->min_z, map->max_z);
}

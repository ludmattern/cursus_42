/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:25:15 by lmattern          #+#    #+#             */
/*   Updated: 2024/01/15 15:48:40 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

/*
Initializes the parameters required for draw line. It calculates the 
differences in x and y directions (dx, dy), their absolute values, and 
determines the step direction (sx, sy) and initial error term based on which 
direction is dominant.
*/
void	init_line_params(t_lineparams *p, t_point *start, t_point *end)
{
	p->dx = end->x - start->x;
	p->dy = end->y - start->y;
	if (p->dx < 0)
		p->abs_dx = -p->dx;
	else
		p->abs_dx = p->dx;
	if (p->dy < 0)
		p->abs_dy = -p->dy;
	else
		p->abs_dy = p->dy;
	p->x = start->x;
	p->y = start->y;
	if (p->dx > 0)
		p->sx = 1;
	else
		p->sx = -1;
	if (p->dy > 0)
		p->sy = 1;
	else
		p->sy = -1;
	if (p->abs_dx > p->abs_dy)
		p->err = p->abs_dx / 2;
	else
		p->err = -p->abs_dy / 2;
}

/*
Uses the Bresenham's algorithm, for drawing lines. It adjusts the x and y 
positions based on the error term to approximate the line between the start and 
end points. It calculates the position in the buffer to draw each pixel and 
continues this process until the end point is reached.
*/
void	draw_line(t_mlx data, t_point *s, t_point *e, t_map *map)
{
	t_lineparams	p;
	t_color			color;

	init_line_params(&p, s, e);
	p.dist = sqrt(pow(e->x - s->x, 2) + pow(e->y - s->y, 2));
	init_color(&color, s, e, map);
	while (true)
	{
		color.progress = sqrt(pow(p.x - s->x, 2) + pow(p.y - s->y, 2)) / p.dist;
		p.pos = p.y * data.line_bytes + p.x * (data.pixel_bits / 8);
		*(int *)(data.buffer + p.pos) = interpolate_color(&color);
		if (p.x == e->x && p.y == e->y)
			break ;
		p.e2 = p.err;
		if (p.e2 > -p.abs_dx)
		{
			p.err -= p.abs_dy;
			p.x += p.sx;
		}
		if (p.e2 < p.abs_dy)
		{
			p.err += p.abs_dx;
			p.y += p.sy;
		}
	}
}

/*
Draws each lines into the image while browsing the map structure.
*/
void	draw_pixels_to_image(t_mlx data, t_map *map)
{
	t_point	**temp_current;
	t_point	*temp_node;
	t_point	*under_node;
	int		i;

	temp_current = map->points;
	i = -1;
	while (++i < map->height)
	{
		temp_node = temp_current[i];
		under_node = NULL;
		if (i < map->height - 1)
			under_node = temp_current[i + 1];
		while (temp_node)
		{
			if (temp_node->next)
				draw_line(data, temp_node, temp_node->next, map);
			if (under_node)
			{
				draw_line(data, temp_node, under_node, map);
				under_node = under_node->next;
			}
			temp_node = temp_node->next;
		}
	}
}

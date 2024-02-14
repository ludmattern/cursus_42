/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 21:32:25 by lmattern          #+#    #+#             */
/*   Updated: 2024/01/14 21:34:33 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	browse_map_data(t_point *current_point, t_bounds *bounds, t_map **map)
{
	while (current_point != NULL)
	{
		if (current_point->x > bounds->max_x)
			bounds->max_x = current_point->x;
		if (current_point->y > bounds->max_y)
			bounds->max_y = current_point->y;
		if (current_point->x < bounds->min_x)
			bounds->min_x = current_point->x;
		if (current_point->y < bounds->min_y)
			bounds->min_y = current_point->y;
		if (current_point->z > (*map)->max_z)
			(*map)->max_z = current_point->z;
		if (current_point->z < (*map)->min_z)
			(*map)->min_z = current_point->z;
		current_point = current_point->next;
	}
}

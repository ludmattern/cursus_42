/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 11:13:40 by lmattern          #+#    #+#             */
/*   Updated: 2024/01/14 17:17:39 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

/*
Allocates the memory and fills point's values applying iso_projection() on x 
and y coordinates to create the isometric view.
*/
t_point	*create_point(int x, int y, long z)
{
	t_point	*new_point;

	if (z == LONG_MAX)
		return (NULL);
	new_point = (t_point *)malloc(sizeof(t_point));
	if (!new_point)
		return (NULL);
	iso_projection(&x, &y, z);
	new_point->x = x;
	new_point->y = y;
	new_point->z = (int)z;
	new_point->next = NULL;
	return (new_point);
}

/*
Deletes and frees a linked list of points.
*/
void	points_clear(t_point **points)
{
	t_point	*current;
	t_point	*temp;

	if (!points || !*points)
		return ;
	current = *points;
	while (current)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	*points = NULL;
}

/*
Deletes and frees map including the linked lists of points.
*/
void	map_clear(t_map **map)
{
	int	i;

	if (!map || !*map)
		return ;
	i = -1;
	while (++i < (*map)->height)
		if ((*map)->points[i])
			points_clear(&((*map)->points[i]));
	free((*map)->points);
	free(*map);
	*map = NULL;
}

/*
Returns the last point of the linked list.
*/
t_point	*points_last(t_point *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/*
Adds the given point to the end of the given linked list.
*/
void	points_add_back(t_point **points, t_point *new_point)
{
	t_point	*last_node;

	if (!new_point)
		return ;
	if (!*points)
		*points = new_point;
	else
	{
		last_node = points_last(*points);
		last_node->next = new_point;
	}
}

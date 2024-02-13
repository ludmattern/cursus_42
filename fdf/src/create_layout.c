/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_layout.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 11:11:55 by lmattern          #+#    #+#             */
/*   Updated: 2024/01/15 17:01:33 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

/*
Applies a calculation on coordinates to simulate 3D view on a 100 scale to 
minimize errors.
*/
void	iso_projection(int *x, int *y, int z)
{
	double	angle;
	int		scaled_x;
	int		scaled_y;

	angle = 26.155 * (M_PI / 180);
	scaled_x = *x * 100;
	scaled_y = *y * 100;
	*x = scaled_x * cos(angle) - scaled_y * sin(angle);
	*y = ((scaled_x * sin(angle) + scaled_y * cos(angle)) - z * 100);
}

/*
Fills and checks the width of the map.
*/
bool	check_map_width(t_map **map, int nb_tokens)
{
	if (nb_tokens > 500)
		return (false);
	(*map)->width = nb_tokens;
	return (true);
}

/*
Fills the map, its width and its list of points with the good values line per 
line.
*/
bool	generating_map(char **tokens, t_map **map, int y)
{
	t_point	*new_point;
	int		i;
	int		j;

	i = 0;
	while (tokens[i] && tokens[i][0] != '\n')
	{
		j = 0;
		if (tokens[i][j] != '-' && !ft_isdigit(tokens[i][j]))
			return (map_clear(map), false);
		if (tokens[i][j] == '-')
			j++;
		while (ft_isdigit(tokens[i][j]))
			j++;
		if (tokens[i][j] && tokens[i][j] != '\n')
			return (map_clear(map), false);
		new_point = create_point(i, y, ft_atoi(tokens[i]));
		if (!new_point)
			return (map_clear(map), false);
		points_add_back(&((*map)->points[y]), new_point);
		i++;
	}
	return (true);
}

/*
Creates and allocates the initial memory for the map and its inside list of 
points then fills its height.
*/
t_map	*map_new(int height)
{
	t_map	*new_map;
	int		i;

	if (height > 500)
		return (NULL);
	new_map = malloc(sizeof(t_map));
	if (!new_map)
		return (NULL);
	new_map->height = height;
	new_map->width = 0;
	new_map->min_z = INT_MAX;
	new_map->max_z = INT_MIN;
	new_map->points = malloc(height * sizeof(t_point *));
	if (!(*new_map).points)
		return (free(new_map), NULL);
	i = 0;
	while (i < height)
		new_map->points[i++] = NULL;
	return (new_map);
}

/*
Creates the structured layout of points from the 2D input list.
*/
void	create_layout(char ***tab, t_map **map)
{
	int			i;
	char		**tokens;
	int			nb_tokens;

	i = 0;
	*map = map_new(count_lines_in_tab(*tab, false));
	if (!*map)
		map_err("Error", NULL, tab, NULL);
	i = -1;
	while ((*tab)[++i])
	{
		tokens = ft_split((*tab)[i], ' ');
		if (!tokens)
			map_err("Error", &tokens, tab, map);
		nb_tokens = count_lines_in_tab(tokens, true);
		if (!check_map_width(map, nb_tokens))
			map_err("Error", &tokens, tab, map);
		if (!generating_map(tokens, map, i))
			map_err("Error", &tokens, tab, map);
		ft_free_array(&tokens);
	}
	ft_free_array(tab);
	adjust_scale_and_pos(map);
}

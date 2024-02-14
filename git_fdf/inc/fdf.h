/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 13:46:37 by lmattern          #+#    #+#             */
/*   Updated: 2024/01/14 21:33:58 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../lib/libft/inc/libft.h"
# include "../lib/libft/inc/get_next_line.h"
# include "../lib/minilibx_linux/mlx_int.h"
# include "../lib/minilibx_linux/mlx.h"
# include <math.h>

/*
map and points struct definitions
*/
typedef struct s_point
{
	int				x;
	int				y;
	int				z;
	struct s_point	*next;
}	t_point;

typedef struct s_map
{
	t_point	**points;
	int		width;
	int		height;
	int		min_z;
	int		max_z;
}	t_map;

typedef struct s_bounds
{
	int	min_x;
	int	min_y;
	int	max_x;
	int	max_y;
}	t_bounds;

typedef struct s_lineparams
{
	int		dx;
	int		dy;
	int		abs_dx;
	int		abs_dy;
	int		x;
	int		y;
	int		sx;
	int		sy;
	int		err;
	int		e2;
	float	dist;
	int		pos;
}	t_lineparams;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	char	*buffer;
	int		width;
	int		height;
}	t_mlx;

typedef struct s_colorparams
{
	int		red;
	int		green;
	int		blue;
	float	l_thld;
	float	m_thld;
	float	h_thld;
	float	t;
}	t_colorparams;

typedef struct s_color
{
	int		start_color;
	int		end_color;
	float	progress;
	int		red;
	int		green;
	int		blue;
}	t_color;

/*
core functions
*/
void	parse_input(char ***tab, const char *ground_file);
void	create_layout(char ***tab, t_map **map);
void	adjust_scale_and_pos(t_map **map);
void	draw_pixels_to_image(t_mlx data, t_map *map);
void	display_map(t_mlx *data, t_map **map);

/*
secondary functions
*/
void	iso_projection(int *x, int *y, int z);
void	browse_map_data(t_point *current_point, t_bounds *bounds, t_map **map);
int		altitude_to_color(int altitude, int z_min, int z_max);
void	init_color(t_color *color, t_point *s, t_point *e, t_map *map);
int		interpolation(int start, int end, float t);
int		interpolate_color(t_color *color);

/*
array management functions
*/
void	ft_free_array(char ***tokens);
int		count_lines_in_tab(char **tab, bool pass_spaces);

/*
linked lists management functions
*/
void	map_clear(t_map **map);
void	points_add_back(t_point **points, t_point *new_point);
t_point	*create_point(int x, int y, long z);

/*
errors management functions
*/
void	inpt_err(const char *msg, int fd, char ***tab, size_t tab_len);
void	map_err(const char *msg, char ***tab, char ***tkn, t_map **map);
void	mlx_err(const char *msg, t_mlx *data, t_map	**map);
#endif
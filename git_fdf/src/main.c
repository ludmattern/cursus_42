/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 13:46:34 by lmattern          #+#    #+#             */
/*   Updated: 2024/01/15 16:32:59 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

/*
The following rules must be followed inside the map file in order to make the 
program work correctly :
		- Existing file;
		- Only digits or numbers between -200 and 200;
		- Each altitude values must be separated by spaces;
		- Not more than 500 values in x and y axis;
		- No empty lines in file;
If this rules are not followed, an error message will be displayed.
*/
int	main(int argc, char **argv)
{
	char	**tab;
	t_map	*map;
	t_mlx	data;

	if (argc != 2)
		inpt_err("Error arguments", -1, NULL, 0);
	parse_input(&tab, argv[1]);
	create_layout(&tab, &map);
	display_map(&data, &map);
	return (0);
}

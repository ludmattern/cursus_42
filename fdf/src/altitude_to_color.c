/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   altitude_to_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 20:02:03 by lmattern          #+#    #+#             */
/*   Updated: 2024/01/15 14:50:57 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

/*
Gives the color between blue and white according to t being the current 
calculated position on the gradient.
*/
void	blue_to_white(t_colorparams *params, int alt, int z_min)
{
	params->t = (alt - z_min) / (params->l_thld - z_min);
	params->red = interpolation(0, 255, params->t);
	params->green = interpolation(0, 255, params->t);
	params->blue = 255;
}

/*
Gives the color between white and yellow according to t being the current 
calculated position on the gradient.
*/
void	white_to_yellow(t_colorparams *params, int alt)
{
	params->t = (alt - params->l_thld) / (params->m_thld - params->l_thld);
	params->red = 255;
	params->green = 255;
	params->blue = interpolation(255, 0, params->t);
}

/*
Gives the color between yellow and orange according to t being the current 
calculated position on the gradient.
*/
void	yellow_to_orange(t_colorparams *params, int alt)
{
	params->t = (alt - params->m_thld) / (params->h_thld - params->m_thld);
	params->red = 255;
	params->green = interpolation(255, 165, params->t);
	params->blue = 0;
}

/*
Gives the color between orange and red according to t being the current 
calculated position on the gradient.
*/
void	orange_to_red(t_colorparams *params, int alt, int z_max)
{
	params->t = (alt - params->h_thld) / (z_max - params->h_thld);
	params->red = 255;
	params->green = interpolation(165, 0, params->t);
	params->blue = 0;
}

/*
Gives the color according to altitude and thresholds
*/
int	altitude_to_color(int alt, int z_min, int z_max)
{
	t_colorparams	params;
	int				result;

	params.l_thld = z_min + (z_max - z_min) * 0.25;
	params.m_thld = z_min + (z_max - z_min) * 0.5;
	params.h_thld = z_min + (z_max - z_min) * 0.75;
	if (alt <= params.l_thld)
		blue_to_white(&params, alt, z_min);
	else if (alt <= params.m_thld)
		white_to_yellow(&params, alt);
	else if (alt <= params.h_thld)
		yellow_to_orange(&params, alt);
	else
		orange_to_red(&params, alt, z_max);
	result = (params.red << 16) | (params.green << 8) | params.blue;
	return (result);
}

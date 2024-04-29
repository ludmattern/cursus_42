/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_dinner_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:33:24 by lmattern          #+#    #+#             */
/*   Updated: 2024/04/26 14:37:00 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/*
This function swaps the indexes of the forks if the left index is greater than 
the right index.
*/
void	swap_index(int *left_index, int *right_index)
{
	int	temp;

	if (*left_index > *right_index)
	{
		temp = *left_index;
		*left_index = *right_index;
		*right_index = temp;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 11:13:40 by lmattern          #+#    #+#             */
/*   Updated: 2024/01/15 15:07:50 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

/*
Frees a 2D array and its content.
*/
void	ft_free_array(char ***tokens)
{
	size_t	i;

	i = 0;
	while ((*tokens)[i])
		free((*tokens)[i++]);
	free(*tokens);
}

/*
Returns the number of lines in a 2D array.
*/
int	count_lines_in_tab(char **tab, bool pass_spaces)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (tab[++i])
	{
		if (tab[i][0] == '\n' && tab[i][1] == '\0')
		{
			if (!pass_spaces)
				return (-1);
		}
		else
			count++;
	}
	return (count);
}

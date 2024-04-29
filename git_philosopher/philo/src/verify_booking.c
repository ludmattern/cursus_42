/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_booking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:33:24 by lmattern          #+#    #+#             */
/*   Updated: 2024/03/31 21:17:48 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/*
This function checks if the number of arguments is correct otherwise it
displays an error message and exits the program.
*/
void	verify_booking(int ac)
{
	if (ac < 5 || ac > 6)
	{
		ft_putstr_fd(ARG_ERR_MSG, STDERR_FILENO);
		ft_putstr_fd(INPUT_FMT_MSG, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}

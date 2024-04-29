/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:33:24 by lmattern          #+#    #+#             */
/*   Updated: 2024/04/01 14:04:50 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/*
nb_philo, time_to_die, time_to_eat, time_to_sleep, [nb_must_eat]
	1			2				3			4 			5
*/
int	main(int ac, char **av)
{
	t_table_plan	table;

	memset(&table, 0, sizeof(t_table_plan));
	verify_booking(ac);
	prepare_dinner(av, &table);
	have_dinner(&table);
	return (EXIT_SUCCESS);
}

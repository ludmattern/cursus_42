/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spectators_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:33:24 by lmattern          #+#    #+#             */
/*   Updated: 2024/04/25 13:38:03 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/*
This function checks if a philosopher is dead by comparing the last meal time
with the time to die of philosophers.
*/
bool	is_there_a_dead_philo(t_table_plan *table)
{
	int	i;

	i = 0;
	while (i < table->nb_philo)
	{
		if ((get_current_time() - protected_value_read(&table->p[i].\
			last_meal_time)) >= table->time_to_die)
		{
			protected_status_write(&table->having_dinner, false);
			end_narrator(&table->p[i], DIE_COMMENTARY, DEATH);
			return (true);
		}
		i++;
	}
	return (false);
}

/*
This function checks if all philosophers have eaten the required number of meals.
*/
bool	are_philo_satisfied(t_table_plan *table)
{
	int	i;

	i = 0;
	while (i < table->nb_philo)
	{
		if (protected_value_read(&table->p[i].\
			meals_eaten) < table->p[i].must_eat_count)
			return (false);
		i++;
	}
	return (true);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_behaviour.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:33:24 by lmattern          #+#    #+#             */
/*   Updated: 2024/04/26 14:16:24 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/*
This function displays the eat commentary and updates the last meal time.
*/
void	eat(t_philosopher *philo)
{
	narrator(philo, EAT_COMMENTARY);
	protected_value_write(&philo->last_meal_time, get_current_time());
	ft_usleep(philo->table->time_to_eat, &philo->table->having_dinner);
	protected_value_write(&philo->meals_eaten, (philo->meals_eaten.value) + 1);
}

/*
This function displays the think commentary.
*/
void	think(t_philosopher *philo)
{
	int	time_to_think;

	time_to_think = (philo->table->time_to_die - (get_current_time() - \
					protected_value_read(&philo->last_meal_time)) - \
					philo->table->time_to_eat) / 2;
	if (time_to_think < 0)
		time_to_think = 0;
	else if (time_to_think == 0)
		time_to_think = 1;
	else if (time_to_think > 600)
		time_to_think = 200;
	narrator(philo, THINK_COMMENTARY);
	ft_usleep(time_to_think, &philo->table->having_dinner);
}

/*
This function displays the sleep commentary then waits for the time to sleep.
*/
void	ft_sleep(t_philosopher *philo)
{
	if (protected_status_read(&philo->table->having_dinner))
	{
		narrator(philo, SLEEP_COMMENTARY);
		ft_usleep(philo->table->time_to_sleep, &philo->table->having_dinner);
	}
}

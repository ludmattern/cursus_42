/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   have_dinner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:33:24 by lmattern          #+#    #+#             */
/*   Updated: 2024/04/29 09:42:00 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/*
This function is handling the case where there is only one philosopher.
*/
void	handle_single_philosopher(t_philosopher *philo)
{
	narrator(philo, FORK_COMMENTARY);
	ft_usleep(philo->table->time_to_die, &philo->table->having_dinner);
}

/*
This function performs the actions of a philosopher.
*/
void	*philo_odd_behaviour(void *arg)
{
	t_philosopher	*philo;
	t_table_plan	*table;

	philo = (t_philosopher *)arg;
	table = philo->table;
	while (true)
	{
		if (protected_status_read(&table->ready_to_start))
			break ;
		usleep(100);
	}
	if (philo->table->nb_philo == 1)
		return (handle_single_philosopher(philo), NULL);
	while (true)
	{
		pick_up_forks(philo);
		eat(philo);
		drop_forks_if_held(philo);
		ft_sleep(philo);
		think(philo);
		if (!protected_status_read(&table->having_dinner))
			break ;
	}
	drop_forks_if_held(philo);
	return (NULL);
}

/*
This function launches the philosophers threads.
*/
void	launch_philosophers(t_table_plan *table)
{
	int	i;

	i = 0;
	while (i < table->nb_philo)
	{
		if (pthread_create(&(table->p[i].thread), NULL,
				&philo_odd_behaviour, &(table->p[i])) != 0)
		{
			ft_putstr_fd(THREAD_ERR_MSG, STDERR_FILENO);
			put_and_end_to_this_masquerade(table, EXIT_FAILURE);
		}
		table->nb_threads++;
		i++;
	}
}

/*
This function launches the death and hunger monitors.
*/
void	launch_monitors(t_table_plan *table)
{
	if (pthread_create(&table->death_monitor, NULL, &death_monitor, table) != 0)
	{
		ft_putstr_fd(DMONITOR_ERR_MSG, STDERR_FILENO);
		protected_status_write(&table->ready_to_start, true);
		wait_for_empty_plates(table);
		put_and_end_to_this_masquerade(table, EXIT_FAILURE);
	}
	if (table->p[0].must_eat_count != -1)
	{
		if (pthread_create(&table->hunger_monitor, NULL, &hunger_monitor,
				table) != 0)
		{
			ft_putstr_fd(HMONITOR_ERR_MSG, STDERR_FILENO);
			protected_status_write(&table->ready_to_start, true);
			wait_for_empty_plates(table);
			pthread_join(table->death_monitor, NULL);
			put_and_end_to_this_masquerade(table, EXIT_FAILURE);
		}
	}
}

/*
This function launches the philosophers and the monitors
then cleans up the program.
*/
void	have_dinner(t_table_plan *table)
{
	int	i;

	i = 0;
	table->nb_threads = 0;
	launch_philosophers(table);
	launch_monitors(table);
	protected_status_write(&table->having_dinner, true);
	table->start_time = get_current_time();
	while (i < table->nb_philo)
		table->p[i++].last_meal_time.value = table->start_time;
	protected_status_write(&table->ready_to_start, true);
	wait_for_empty_plates(table);
	pthread_join(table->death_monitor, NULL);
	if (table->p[0].must_eat_count != -1)
		pthread_join(table->hunger_monitor, NULL);
	put_and_end_to_this_masquerade(table, EXIT_SUCCESS);
}

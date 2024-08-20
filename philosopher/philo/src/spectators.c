/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spectators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:33:24 by lmattern          #+#    #+#             */
/*   Updated: 2024/04/26 14:37:09 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/*
This function securlly displays the commentary about the philosopher's status.
*/
void	narrator(t_philosopher *philo, char *commentary)
{
	long	elapsed_time;

	pthread_mutex_lock(&(philo->table->annoying_narration.mutex));
	if (!protected_status_read(&philo->table->having_dinner))
	{
		pthread_mutex_unlock(&(philo->table->annoying_narration.mutex));
		return ;
	}
	elapsed_time = get_elapsed_time(philo->table->start_time);
	printf("%ld %d %s", elapsed_time, philo->id, commentary);
	pthread_mutex_unlock(&(philo->table->annoying_narration.mutex));
}

/*
This function securlly displays the commentary about the dinner's end reason.
*/
void	end_narrator(t_philosopher *philo, char *commentary, t_end_cause cause)
{
	long	elapsed_time;

	elapsed_time = get_elapsed_time(philo->table->start_time);
	pthread_mutex_lock(&(philo->table->end_annoying_narration.mutex));
	pthread_mutex_lock(&(philo->table->annoying_narration.mutex));
	if (cause == DEATH)
		printf("%ld %d %s", elapsed_time, philo->id, commentary);
	else if (cause == SATISFIED)
		printf("%ld %s", elapsed_time, commentary);
	pthread_mutex_unlock(&(philo->table->annoying_narration.mutex));
	pthread_mutex_unlock(&(philo->table->end_annoying_narration.mutex));
}

/*
This function checks if a dead occured.
*/
void	*death_monitor(void *arg)
{
	t_table_plan	*table;

	table = (t_table_plan *)arg;
	while (true)
	{
		if (protected_status_read(&table->ready_to_start))
			break ;
		usleep(100);
	}
	while (protected_status_read(&table->having_dinner))
	{
		if (is_there_a_dead_philo(table))
			break ;
	}
	return (NULL);
}

/*
This function checks if every philosopher has eaten the good number of meals.
*/
void	*hunger_monitor(void *arg)
{
	t_table_plan	*table;
	bool			all_satisfied;

	table = (t_table_plan *)arg;
	all_satisfied = false;
	while (true)
	{
		if (protected_status_read(&table->ready_to_start))
			break ;
	}
	while (protected_status_read(&table->having_dinner))
	{
		all_satisfied = are_philo_satisfied(table);
		if (all_satisfied)
		{
			protected_status_write(&table->having_dinner, false);
			end_narrator(&table->p[0], SATISFIED_COMMENTARY, SATISFIED);
			break ;
		}
		ft_usleep(1, NULL);
	}
	return (NULL);
}

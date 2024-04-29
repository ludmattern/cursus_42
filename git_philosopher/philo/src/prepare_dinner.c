/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_dinner.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:33:24 by lmattern          #+#    #+#             */
/*   Updated: 2024/04/26 14:35:14 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/*
This function initializes the forks for each philosopher.
*/
bool	distribute_forks(t_table_plan *table)
{
	int	i;
	int	left_index;
	int	right_index;

	i = -1;
	while (++i < table->nb_philo)
	{
		table->p[i].id = i + 1;
		left_index = i;
		right_index = (i + 1) % table->nb_philo;
		swap_index(&left_index, &right_index);
		table->p[i].left_fork = &(table->forks[left_index]);
		table->forks[left_index].taken.value = false;
		table->p[i].right_fork = &(table->forks[right_index]);
		table->forks[right_index].taken.value = false;
		table->p[i].left_fork_taken = false;
		table->p[i].right_fork_taken = false;
		if (!protected_value_init(&(table->p[i].meals_eaten), 0))
			return (ft_putstr_fd(NARR_ALLOC_ERR_MSG, STDERR_FILENO), false);
		if (!protected_value_init(&(table->p[i].last_meal_time), 0))
			return (ft_putstr_fd(NARR_ALLOC_ERR_MSG, STDERR_FILENO), false);
	}
	return (true);
}

/*
this function initializes the forks mutexes and checks if the number of 
philosophers is valid
*/
bool	bring_forks_and_seat_guests(char **av, t_table_plan *table)
{
	int	i;

	if (!parse_long(av[1], &table->nb_philo, true))
		return (false);
	if (table->nb_philo < 1 || table->nb_philo > 200)
		return (ft_putstr_fd(NB_PHILO_ERR_MSG, STDERR_FILENO), false);
	table->forks = malloc(sizeof(t_fork) * table->nb_philo);
	if (!(table->forks))
		return (ft_putstr_fd(FORKS_ALLOC_ERR_MSG, STDERR_FILENO), false);
	i = -1;
	while (++i < table->nb_philo)
	{
		if (!protected_status_init(&(table->forks)[i].taken, false))
			return (ft_putstr_fd(FORKS_ALLOC_ERR_MSG, STDERR_FILENO), false);
		table->nb_forks++;
	}
	table->p = malloc(sizeof(t_philosopher) * table->nb_philo);
	if (!(table->p))
		return (ft_putstr_fd(PHILO_ALLOC_ERR_MSG, STDERR_FILENO), false);
	memset(table->p, 0, sizeof(t_philosopher) * table->nb_philo);
	if (!protected_status_init(&table->annoying_narration, false)
		|| !protected_status_init(&table->end_annoying_narration, false)
		|| !protected_status_init(&table->having_dinner, false))
		return (ft_putstr_fd(NARR_ALLOC_ERR_MSG, STDERR_FILENO), false);
	return (true);
}

/*
This function initializes the philosophers and the table.
*/
bool	take_orders(char **av, t_table_plan *table)
{
	int		i;
	long	must_eat_count;

	if (!parse_long(av[2], &table->time_to_die, false)
		|| !parse_long(av[3], &table->time_to_eat, false)
		|| !parse_long(av[4], &table->time_to_sleep, false))
		return (false);
	i = 0;
	must_eat_count = -1;
	if (av[5] && !parse_long(av[5], &must_eat_count, false))
		return (false);
	while (i < table->nb_philo)
	{
		table->p[i].table = table;
		table->p[i++].must_eat_count = must_eat_count;
	}
	return (true);
}

/*
This function frees the memory and exits the program.
*/
void	put_and_end_to_this_masquerade(t_table_plan *table, int status)
{
	int	i;

	i = 0;
	while (i < table->nb_forks)
		protected_status_destroy(&(table->forks)[i++].taken);
	protected_status_destroy(&table->annoying_narration);
	protected_status_destroy(&table->end_annoying_narration);
	protected_status_destroy(&table->having_dinner);
	protected_status_destroy(&table->ready_to_start);
	i = 0;
	while (i < table->nb_philo && &table->p[i])
	{
		protected_value_destroy(&table->p[i].last_meal_time);
		protected_value_destroy(&table->p[i].meals_eaten);
		i++;
	}
	if (table->forks)
		free(table->forks);
	if (table->p)
		free(table->p);
	exit(status);
}

/*
This function initializes the table and the philosophers.
*/
void	prepare_dinner(char **av, t_table_plan *table)
{
	table->p = NULL;
	table->forks = NULL;
	if (!bring_forks_and_seat_guests(av, table)
		|| !distribute_forks(table)
		|| !take_orders(av, table)
		|| !protected_status_init(&table->ready_to_start, false))
		put_and_end_to_this_masquerade(table, EXIT_FAILURE);
}

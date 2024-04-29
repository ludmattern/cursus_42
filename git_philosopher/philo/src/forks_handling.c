/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:33:24 by lmattern          #+#    #+#             */
/*   Updated: 2024/04/25 14:35:53 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	attempt_to_pick_up_forks(t_philosopher *philo)
{
	while (!philo->left_fork_taken && !philo->right_fork_taken)
	{
		pthread_mutex_lock(&(philo->left_fork->taken.mutex));
		pthread_mutex_lock(&(philo->right_fork->taken.mutex));
		if (!philo->left_fork->taken.value && !philo->right_fork->taken.value)
		{
			philo->left_fork->taken.value = true;
			pthread_mutex_unlock(&(philo->left_fork->taken.mutex));
			philo->right_fork->taken.value = true;
			pthread_mutex_unlock(&(philo->right_fork->taken.mutex));
			narrator(philo, FORK_COMMENTARY);
			narrator(philo, FORK_COMMENTARY);
			philo->left_fork_taken = true;
			philo->right_fork_taken = true;
			break ;
		}
		else
		{
			pthread_mutex_unlock(&(philo->left_fork->taken.mutex));
			pthread_mutex_unlock(&(philo->right_fork->taken.mutex));
		}
		usleep(1000);
	}
}

/*
This function unlocks the left fork and then the right fork if they are locked.
*/
void	drop_forks_if_held(t_philosopher *philo)
{
	if (philo->left_fork_taken)
	{
		protected_status_write(&philo->left_fork->taken, false);
		philo->left_fork_taken = false;
	}
	if (philo->right_fork_taken)
	{
		protected_status_write(&philo->right_fork->taken, false);
		philo->right_fork_taken = false;
	}
}

/*
This function is picking up the forks if the philosopher is still having dinner.
For the even philosophers, we add a small delay to avoid deadlocks.
*/
void	pick_up_forks(t_philosopher *philo)
{
	if (!protected_status_read(&philo->table->having_dinner))
		return ;
	if (philo->id % 2 == 0)
		ft_usleep(2, NULL);
	attempt_to_pick_up_forks(philo);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status_mutex_handling.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:33:24 by lmattern          #+#    #+#             */
/*   Updated: 2024/04/18 10:54:38 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/*
this function initializes the mutex and the value of the protected status
*/
bool	protected_status_init(t_protected_status *status, bool initial_state)
{
	status->value = initial_state;
	status->initialized = true;
	if (pthread_mutex_init(&(status->mutex), NULL) != 0)
		status->initialized = false;
	return (status->initialized);
}

/*
this function reads the value of the protected status
*/
bool	protected_status_read(t_protected_status *status)
{
	bool	value;

	if (!status)
		return (false);
	pthread_mutex_lock(&(status->mutex));
	value = status->value;
	pthread_mutex_unlock(&(status->mutex));
	return (value);
}

/*
this function writes a new value to the protected status
*/
void	protected_status_write(t_protected_status *status, bool new_state)
{
	pthread_mutex_lock(&(status->mutex));
	status->value = new_state;
	pthread_mutex_unlock(&(status->mutex));
}

/*
this function writes a new value to the protected status
*/
bool	take_fork(t_protected_status *status, bool new_state)
{
	pthread_mutex_lock(&(status->mutex));
	if (status->value == true)
	{
		pthread_mutex_unlock(&(status->mutex));
		return (false);
	}
	status->value = new_state;
	pthread_mutex_unlock(&(status->mutex));
	return (true);
}

/*
this function destroys the mutex of the protected status
*/
void	protected_status_destroy(t_protected_status *status)
{
	if (status->initialized)
	{
		pthread_mutex_destroy(&(status->mutex));
		status->initialized = false;
	}
}

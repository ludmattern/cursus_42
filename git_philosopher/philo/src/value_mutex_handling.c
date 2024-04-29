/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_mutex_handling.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:33:24 by lmattern          #+#    #+#             */
/*   Updated: 2024/04/01 15:59:48 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/*
this function initializes the mutex and the value of the protected value
*/
bool	protected_value_init(t_protected_value *value, long initial_value)
{
	value->value = initial_value;
	value->initialized = true;
	if (pthread_mutex_init(&(value->mutex), NULL) != 0)
		value->initialized = false;
	return (value->initialized);
}

/*
this function reads the value of the protected value
*/
long	protected_value_read(t_protected_value *value)
{
	long	read_value;

	pthread_mutex_lock(&(value->mutex));
	read_value = value->value;
	pthread_mutex_unlock(&(value->mutex));
	return (read_value);
}

/*
this function writes a new value to the protected value
*/
void	protected_value_write(t_protected_value *value, long new_value)
{
	pthread_mutex_lock(&(value->mutex));
	value->value = new_value;
	pthread_mutex_unlock(&(value->mutex));
}

/*
this function destroys the mutex of the protected value
*/
void	protected_value_destroy(t_protected_value *value)
{
	if (value->initialized)
	{
		pthread_mutex_destroy(&(value->mutex));
		value->initialized = false;
	}
}

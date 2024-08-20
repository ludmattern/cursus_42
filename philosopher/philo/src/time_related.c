/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_related.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:33:24 by lmattern          #+#    #+#             */
/*   Updated: 2024/04/18 10:59:54 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/*
This function waits for the specified time in milliseconds more
precisely than usleep.
*/
void	ft_usleep(long int time_in_ms, t_protected_status *having_dinner)
{
	long int	start_time;
	long int	elapsed_time;
	long int	remaining_time;
	long int	sleep_time_us;

	start_time = get_current_time();
	while (true)
	{
		elapsed_time = get_elapsed_time(start_time);
		remaining_time = time_in_ms - elapsed_time;
		if (remaining_time <= 0)
			break ;
		if (remaining_time > 1)
			sleep_time_us = 1 * 1000;
		else
			sleep_time_us = remaining_time * 1000;
		usleep(sleep_time_us);
		if (!protected_status_read(having_dinner))
			break ;
	}
}

/*
This function returns the current time in milliseconds.
*/
long	get_current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((long)(time.tv_sec) *1000L + (time.tv_usec / 1000));
}

/*
This function returns the elapsed time between the current time and the given
time in milliseconds.
*/
long	get_elapsed_time(long start_time)
{
	long	current_time;
	long	elapsed_time;

	current_time = get_current_time();
	elapsed_time = current_time - start_time;
	return (elapsed_time);
}

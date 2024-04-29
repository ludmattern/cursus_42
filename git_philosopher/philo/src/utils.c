/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:59:18 by lmattern          #+#    #+#             */
/*   Updated: 2024/04/26 14:38:00 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/*
This function waits for all threads to finish.
*/
void	wait_for_empty_plates(t_table_plan *table)
{
	int	i;

	i = 0;
	while (i < table->nb_threads)
		pthread_join(table->p[i++].thread, NULL);
}

/*
this function writes a string to a file descriptor
*/
void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, &(*s), ft_strlen(s));
}

/*
this function returns the length of a string
*/
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/*
this function converts a string into an int only if the input is valid
*/
long	ft_strtoi(const char *nptr, char **endptr)
{
	long	result;
	int		sign;
	int		digit;

	result = 0;
	sign = 1;
	while ((*nptr >= '\t' && *nptr <= '\r') || *nptr == ' ')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
		if (*nptr++ == '-')
			sign = -1;
	while (*nptr >= '0' && *nptr <= '9')
	{
		digit = *nptr++ - '0';
		if ((sign == 1 && result > (INT_MAX - digit) / 10) || \
				(sign == -1 && -(result) < (INT_MIN + digit) / 10))
			return (LONG_MAX);
		result = result * 10 + digit;
	}
	if (endptr)
		*endptr = (char *)nptr;
	return (result * sign);
}

/*
this function parses a string into an int and checks if the value is valid 
*/
bool	parse_long(const char *str, long *out_value, bool philo)
{
	char	*end;
	long	value;

	if (!str || !str[0] || !out_value)
		return (ft_putstr_fd(ARG_ERR_MSG, STDERR_FILENO), false);
	value = ft_strtoi(str, &end);
	if (philo && (value < 1 || value > 200))
		return (ft_putstr_fd(NB_PHILO_ERR_MSG, STDERR_FILENO), false);
	if (value == LONG_MAX || *end != '\0' || value < 0)
		return (ft_putstr_fd(ARG_ERR_MSG, STDERR_FILENO), false);
	*out_value = value;
	return (true);
}

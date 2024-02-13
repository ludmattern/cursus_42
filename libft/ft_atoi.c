/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:47:01 by lmattern          #+#    #+#             */
/*   Updated: 2023/11/16 14:35:47 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while ((*nptr >= '\t' && *nptr <= '\r') || *nptr == ' ')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		if (sign == 1 && (result > (LONG_MAX - (*nptr - '0')) / 10))
			return (-1);
		else if (sign == -1 && (-result < (LONG_MIN + (*nptr - '0')) / 10))
			return (0);
		result = result * 10 + (*nptr - '0');
		nptr++;
	}
	return ((int)(result * sign));
}

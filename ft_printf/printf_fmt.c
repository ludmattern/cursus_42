/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_fmt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:12:36 by lmattern          #+#    #+#             */
/*   Updated: 2023/11/21 10:37:36 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_num(unsigned int num, char fmt)
{
	char	*str;
	int		len;
	int		base;

	base = 10;
	if (fmt != 'u')
	{
		base = 16;
		if (fmt == 'X')
			base = 16;
		else
			base = -16;
	}
	str = itoa_printf(num, base);
	if (!str)
		return (-1);
	if (ft_putstr_fd(str, 1) < 0)
	{
		free(str);
		return (-1);
	}
	len = ft_strlen(str);
	free(str);
	return (len);
}

int	print_char(char c)
{
	if (ft_putchar_fd(c, 1) < 0)
		return (-1);
	return (1);
}

int	print_string(char *str)
{
	if (!str)
		str = "(null)";
	if (ft_putstr_fd(str, 1) < 0)
		return (-1);
	return (ft_strlen(str));
}

int	print_pointer(void *ptr)
{
	char	*str;
	int		len;

	if (!ptr)
	{
		if (ft_putstr_fd("(nil)", 1) < 0)
			return (-1);
		return (5);
	}
	str = itoa_printf((unsigned long long)ptr, -16);
	if (!str)
		return (-1);
	if (ft_putstr_fd("0x", 1) < 0 || ft_putstr_fd(str, 1) < 0)
	{
		free(str);
		return (-1);
	}
	len = ft_strlen(str) + 2;
	free(str);
	return (len);
}

int	print_int(int nbr)
{
	char	*str;
	int		len;

	str = ft_itoa(nbr);
	if (!str)
		return (-1);
	if (ft_putstr_fd(str, 1) < 0)
	{
		free(str);
		return (-1);
	}
	len = ft_strlen(str);
	free(str);
	return (len);
}

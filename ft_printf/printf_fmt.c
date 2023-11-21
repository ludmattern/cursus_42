/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_fmt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:12:36 by lmattern          #+#    #+#             */
/*   Updated: 2023/11/21 15:54:06 by lmattern         ###   ########.fr       */
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
		if (fmt == 'x')
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
	char	*full_str;
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
	len = ft_strlen(str) + 2;
	full_str = malloc(len + 1);
	if (!full_str)
		return (-1);
	ft_strlcpy(full_str, "0x", 3);
	ft_strlcat(full_str + 2, str, len + 1);
	if (ft_putstr_fd(full_str, 1) < 0)
		len = -1;
	free(str);
	free(full_str);
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

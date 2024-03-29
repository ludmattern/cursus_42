/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:09:08 by lmattern          #+#    #+#             */
/*   Updated: 2024/03/06 13:13:05 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/inc/libft.h"

int		ft_printf(const char *format, ...);
char	*itoa_printf(unsigned long long num, int base);
int		print_num_printf(unsigned int num, char fmt);
int		print_char_printf(char c);
int		print_string_printf(char *str);
int		print_pointer_printf(void *ptr, char *str, int len);
int		print_int_printf(int nbr);

#endif

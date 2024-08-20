/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:09:08 by lmattern          #+#    #+#             */
/*   Updated: 2023/11/21 16:27:02 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
char	*itoa_printf(unsigned long long num, int base);
int		print_num(unsigned int num, char fmt);
int		print_char(char c);
int		print_string(char *str);
int		print_pointer(void *ptr, char *str, int len);
int		print_int(int nbr);
size_t	ft_strlen(const char *s);
int		ft_putstr_fd(char *s, int fd);
int		ft_putchar_fd(char c, int fd);
char	*ft_itoa(int n);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

#endif

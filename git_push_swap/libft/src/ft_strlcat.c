/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:49:19 by lmattern          #+#    #+#             */
/*   Updated: 2023/12/14 13:31:17 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = dst_len;
	if (size <= dst_len)
		return (size + src_len);
	while (src[i - dst_len] && i < size - 1)
	{
		dst[i] = src[i - dst_len];
		i++;
	}
	dst[i] = '\0';
	return (dst_len + src_len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:03:09 by lmattern          #+#    #+#             */
/*   Updated: 2023/11/24 15:00:26 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s && (*s != (unsigned char)c))
		s++;
	if (*s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	if (size)
	{
		i = 0;
		while (src[i] && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		if (size > 0)
			dst[i] = '\0';
	}
	return (src_len);
}

char *ft_strjoin(char *s1, char *s2)
{
    char *str;
    char *original_s1;

	original_s1 = s1;
    if (!s1)
        s1 = ft_strdup("");
    if (!s1 || !s2)
    {
        if (original_s1 != s1)
            free(s1);
        return (NULL);
    }
    str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
    if (!str)
    {
        if (original_s1 != s1)
            free(s1);
        return (NULL);
    }
    ft_strlcpy(str, s1, ft_strlen(s1) + 1);
    ft_strlcpy(str + ft_strlen(s1), s2, ft_strlen(s2) + 1);
    if (original_s1 != s1)
        free(s1);
    return (str);
}

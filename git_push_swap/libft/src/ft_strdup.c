/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:55:49 by lmattern          #+#    #+#             */
/*   Updated: 2023/12/14 13:31:08 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	char	*original;
	size_t	length;

	length = 0;
	while (s[length])
		length++;
	str = ft_calloc((length + 1), sizeof(char));
	if (str == NULL)
		return (NULL);
	original = str;
	while (*s)
		*str++ = *s++;
	return (original);
}

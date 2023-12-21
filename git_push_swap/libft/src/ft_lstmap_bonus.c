/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 19:25:33 by lmattern          #+#    #+#             */
/*   Updated: 2023/12/14 13:30:27 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

t_stack_node	*ft_lstmap(t_stack_node *lst)
{
	t_stack_node	*new_list;
	t_stack_node	*new_elem;
	int				temp;

	if (!lst)
		return (NULL);
	new_list = NULL;
	new_elem = NULL;
	temp = 0;
	while (lst)
	{
		new_elem = ft_lstnew(temp);
		if (!new_elem)
		{
			ft_lstclear(&new_list);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_elem);
		lst = lst->next;
	}
	return (new_list);
}

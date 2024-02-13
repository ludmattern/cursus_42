/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:49:24 by lmattern          #+#    #+#             */
/*   Updated: 2023/12/14 13:30:14 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_lstclear(t_stack_node **lst)
{
	t_stack_node	*current;
	t_stack_node	*temp;

	if (!lst || !*lst)
		return ;
	current = *lst;
	while (current)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	*lst = NULL;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 19:25:33 by lmattern          #+#    #+#             */
/*   Updated: 2023/12/14 13:30:21 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_lstiter(t_stack_node *lst)
{
	t_stack_node	*current;

	if (!lst)
		return ;
	current = lst;
	while (current)
		current = current->next;
}

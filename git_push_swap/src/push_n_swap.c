/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_n_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 09:30:06 by lmattern          #+#    #+#             */
/*   Updated: 2023/12/15 17:40:53 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
this function performs the push action on a stack
*/
void	push(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*first_b;

	if (!*b)
		return ;
	first_b = *b;
	*b = first_b->next;
	if (*b)
		(*b)->prev = NULL;
	first_b->next = *a;
	if (*a)
		(*a)->prev = first_b;
	*a = first_b;
	first_b->prev = NULL;
}

/*
this function calls the push function on a given stack
*/
void	push_stack(t_stack_node **a, t_stack_node **b, const char action)
{
	if (action == 'a')
	{
		push(a, b);
		ft_putstr_fd("pa\n", 1);
	}
	else if (action == 'b')
	{
		push(b, a);
		ft_putstr_fd("pb\n", 1);
	}
}

/*
this function performs the swap action on a stack
*/
void	swap(t_stack_node **stack)
{
	int	temp_content;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	temp_content = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = temp_content;
}

/*
this function calls the swap function on a given stack
*/
void	swap_stack(t_stack_node **a, t_stack_node **b, const char action)
{
	if (action == 'a')
	{
		swap(a);
		ft_putstr_fd("sa\n", 1);
	}
	else if (action == 'b')
	{
		swap(b);
		ft_putstr_fd("sb\n", 1);
	}
	else if (action == 's')
	{
		swap(a);
		swap(b);
		ft_putstr_fd("ss\n", 1);
	}
}

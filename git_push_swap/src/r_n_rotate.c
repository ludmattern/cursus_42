/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_n_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 09:30:06 by lmattern          #+#    #+#             */
/*   Updated: 2023/12/15 17:41:10 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
this function performs the reverse rotate action on a stack
*/
void	r_rotate(t_stack_node **stack)
{
	t_stack_node	*last;
	t_stack_node	*second_last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	last = *stack;
	second_last = NULL;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	if (second_last)
		second_last->next = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	last->prev = NULL;
	*stack = last;
}

/*
this function calls the reverse rotate function on a given stack
*/
void	r_rotate_stack(t_stack_node **a, t_stack_node **b, const char action)
{
	if (action == 'a')
	{
		r_rotate(a);
		ft_putstr_fd("rra\n", 1);
	}
	else if (action == 'b')
	{
		r_rotate(b);
		ft_putstr_fd("rrb\n", 1);
	}
	else if (action == 'r')
	{
		r_rotate(a);
		r_rotate(b);
		ft_putstr_fd("rrr\n", 1);
	}
}

/*
this function performs the rotate action on a stack
*/
void	rotate(t_stack_node **stack)
{
	t_stack_node	*first;
	t_stack_node	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	*stack = first->next;
	(*stack)->prev = NULL;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

/*
this function calls the rotate function on a given stack
*/
void	rotate_stack(t_stack_node **a, t_stack_node **b, const char action)
{
	if (action == 'a')
	{
		rotate(a);
		ft_putstr_fd("ra\n", 1);
	}
	else if (action == 'b')
	{
		rotate(b);
		ft_putstr_fd("rb\n", 1);
	}
	else if (action == 'r')
	{
		rotate(a);
		rotate(b);
		ft_putstr_fd("rr\n", 1);
	}
}

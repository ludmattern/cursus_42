/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 09:30:06 by lmattern          #+#    #+#             */
/*   Updated: 2023/12/21 15:13:28 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
this function returns the the smallest node's position in the stack
*/
size_t	find_smallest(t_stack_node *a)
{
	size_t			position;
	size_t			smallest_pos;
	int				smallest_val;
	t_stack_node	*current;

	position = 0;
	smallest_pos = 0;
	smallest_val = INT_MAX;
	current = a;
	while (current)
	{
		if (current->content < smallest_val)
		{
			smallest_val = current->content;
			smallest_pos = position;
		}
		position++;
		current = current->next;
	}
	return (smallest_pos);
}

/*
this function returns the the max number of bits of the 
biggest value in the stack
*/
int	find_biggest(t_stack_node **a)
{
	int				bit_value;
	int				biggest_value;
	t_stack_node	*current;

	biggest_value = 0;
	bit_value = 0;
	current = *a;
	while (current)
	{
		if (current->content > biggest_value)
			biggest_value = current->content;
		current = current->next;
	}
	while (biggest_value != 0)
	{
		biggest_value >>= 1;
		bit_value++;
	}
	return (bit_value);
}

/*
this function sorts the three first nodes in a given stack
*/
void	sort_three(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*last;

	last = *a;
	while (last && last->next)
		last = last->next;
	if ((*a)->content > (*a)->next->content)
	{
		swap_stack(a, b, 'a');
	}
	if ((*a)->next->content > last->content)
	{
		r_rotate_stack(a, b, 'a');
	}
	if ((*a)->content > (*a)->next->content)
	{
		swap_stack(a, b, 'a');
	}
}

/*
this function sorts the five first nodes in a given stack
first it pushes the two smallest nodes onto b stack
then it sorts the three remainings nodes in a stack
finally it pushes the two smallest back onto a stack
*/
void	sort_five(t_stack_node **a, t_stack_node **b, size_t stack_size)
{
	size_t	i;
	size_t	in_b;
	size_t	smallest_pos;

	i = -1;
	in_b = 0;
	while (++i < 2)
	{
		smallest_pos = find_smallest(*a);
		if (smallest_pos <= ((stack_size / 2) - i))
			while (smallest_pos--)
				rotate_stack(a, b, 'a');
		else
			while (smallest_pos++ < (stack_size - i))
				r_rotate_stack(a, b, 'a');
		if (is_sorted(*a))
			break ;
		push_stack(a, b, 'b');
		in_b++;
	}
	sort_three(a, b);
	while (in_b-- > 0)
		push_stack(a, b, 'a');
}

/*
this function sorts the nodes in a given stack comparing 
bits of the numbers
*/
void	sort_further(t_stack_node **a, t_stack_node **b, size_t stack_size)
{
	int				max_bits;
	int				i;
	size_t			j;
	t_stack_node	*current;

	max_bits = find_biggest(a);
	current = *a;
	i = 0;
	while (i < max_bits)
	{
		j = -1;
		while (++j != stack_size)
		{
			current = *a;
			if (((current->content >> i) & 1) == 1)
				rotate_stack(a, b, 'a');
			else
				push_stack(a, b, 'b');
		}
		while (ft_lstsize(*b))
			push_stack(a, b, 'a');
		i++;
	}
}

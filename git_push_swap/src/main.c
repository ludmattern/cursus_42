/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:19:56 by lmattern          #+#    #+#             */
/*   Updated: 2023/12/21 14:30:13 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
this function check if the stack is sorted in ascending order
*/
bool	is_sorted(t_stack_node *stack)
{
	while (stack && stack->next)
	{
		if (stack->content > stack->next->content)
			return (false);
		stack = stack->next;
	}
	return (true);
}

/*
this function calls the sorting function according to the size of the stack
*/
void	sort_stack(t_stack_node **a, t_stack_node **b, size_t stack_size)
{
	if (stack_size > 5)
		sort_further(a, b, stack_size);
	else if (stack_size > 3)
		sort_five(a, b, stack_size);
	else
		sort_three(a, NULL);
}

/*
this function calls functions to converts arguments wich check both for 
duplicates and if stack is sorted
*/
bool	init_stack(t_stack_node **a, int argc, char **argv, size_t *a_size)
{
	size_t	i;
	bool	is_sorted;

	is_sorted = true;
	i = 1;
	*a = NULL;
	*a_size = 0;
	while ((int)i < argc)
		process_argument(argv[i++], a, a_size);
	if (!check_stack_rules(*a, &is_sorted))
		handle_error(a, NULL);
	if (is_sorted)
		return (true);
	return (false);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	size_t			a_size;

	a = NULL;
	b = NULL;
	a_size = 0;
	if (!init_stack(&a, argc, argv, &a_size))
	{
		secret_sort(&a, a_size);
		sort_stack(&a, &b, a_size);
	}
	ft_lstclear(&a);
	ft_lstclear(&b);
	return (0);
}

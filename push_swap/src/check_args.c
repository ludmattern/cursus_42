/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 09:30:06 by lmattern          #+#    #+#             */
/*   Updated: 2023/12/14 13:28:59 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
this function handles errors cases for the init_stack function
*/
void	handle_error(t_stack_node **stack, char ***tokens)
{
	if (tokens && *tokens)
	{
		ft_free_array(*tokens);
	}
	if (stack && *stack)
		ft_lstclear(stack);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

/*
this function converts a string into an int
*/
long	ft_strtoi(const char *nptr, char **endptr)
{
	long	result;
	int		sign;
	int		digit;

	result = 0;
	sign = 1;
	while ((*nptr >= '\t' && *nptr <= '\r') || *nptr == ' ')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
		if (*nptr++ == '-')
			sign = -1;
	while (*nptr >= '0' && *nptr <= '9')
	{
		digit = *nptr++ - '0';
		if ((sign == 1 && result > (INT_MAX - digit) / 10) || \
				(sign == -1 && -(result) < (INT_MIN + digit) / 10))
			return (LONG_MAX);
		result = result * 10 + digit;
	}
	if (endptr)
		*endptr = (char *)nptr;
	return (result * sign);
}

/*
this function converts arguments into a linked list of int numbers
*/
void	process_argument(char *arg, t_stack_node **a, size_t *a_size)
{
	t_stack_node	*new_node;
	char			**tokens;
	char			*endptr;
	long			val;
	size_t			i;

	tokens = ft_split(arg, ' ');
	if (!tokens || !tokens[0])
		handle_error(a, &tokens);
	i = -1;
	while (tokens[++i])
	{
		if (tokens[i][0] == '-' || tokens[i][0] == '+')
			if (tokens[i][1] == '\0')
				handle_error(a, &tokens);
		val = ft_strtoi(tokens[i], &endptr);
		if (val == LONG_MAX || *endptr)
			handle_error(a, &tokens);
		new_node = ft_lstnew((int)val);
		if (!new_node)
			handle_error(a, &tokens);
		ft_lstadd_back(a, new_node);
		(*a_size)++;
	}
	ft_free_array(tokens);
}

/*
this function check for duplicates int numbers into a linked list and 
if the list is sorted
*/
bool	check_stack_rules(t_stack_node *a, bool *is_sorted)
{
	t_stack_node	*current;
	t_stack_node	*compare;

	current = a;
	while (current && current->next)
	{
		compare = current->next;
		while (compare)
		{
			if (current->content == compare->content)
				return (false);
			compare = compare->next;
		}
		if (*is_sorted && current->content > current->next->content)
			*is_sorted = false;
		current = current->next;
	}
	return (true);
}

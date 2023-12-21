/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 09:30:13 by lmattern          #+#    #+#             */
/*   Updated: 2023/12/21 14:31:26 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <string.h>
# include <stdbool.h>
# include "../libft/inc/libft.h"

/*
initialization and checking functions
*/
bool	is_sorted(t_stack_node *stack);
void	handle_error(t_stack_node **stack, char ***tokens);
bool	check_stack_rules(t_stack_node *a, bool *is_sorted);
void	process_argument(char *arg, t_stack_node **a, size_t *a_size);

/*
push swap operations functions
*/
void	push_stack(t_stack_node **a, t_stack_node **b, const char action);
void	r_rotate_stack(t_stack_node **a, t_stack_node **b, const char action);
void	rotate_stack(t_stack_node **a, t_stack_node **b, const char action);
void	swap_stack(t_stack_node **a, t_stack_node **b, const char action);

/*
sorting functions
*/
void	sort_three(t_stack_node **a, t_stack_node **b);
void	sort_five(t_stack_node **a, t_stack_node **b, size_t stack_size);
void	sort_further(t_stack_node **a, t_stack_node **b, size_t stack_size);
void	secret_sort(t_stack_node **a, size_t a_size);

/*
useful function
*/
int		find_biggest(t_stack_node **a);

#endif
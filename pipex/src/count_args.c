/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:00:32 by lmattern          #+#    #+#             */
/*   Updated: 2024/02/17 20:09:35 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

bool	toggle_quotes_status(bool in_quotes, char current_char)
{
	if (current_char == '\'')
		return (!in_quotes);
	return (in_quotes);
}

void	counting_args(const char *p, int *args_count)
{
	bool	in_quotes;
	bool	is_arg;

	in_quotes = false;
	is_arg = false;
	while (*p)
	{
		in_quotes = toggle_quotes_status(in_quotes, *p);
		if (!in_quotes && *p == ' ')
		{
			if (is_arg)
			{
				(*args_count)++;
				is_arg = false;
			}
			while (*p == ' ')
				p++;
			continue ;
		}
		is_arg = true;
		p++;
	}
	if (is_arg)
		(*args_count)++;
}

int	count_args(const char *cmd_str)
{
	int			args_count;
	const char	*p;

	args_count = 0;
	p = cmd_str;
	while (*p == ' ')
		p++;
	counting_args(p, &args_count);
	return (args_count);
}

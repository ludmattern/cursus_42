/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmattern <lmattern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:00:32 by lmattern          #+#    #+#             */
/*   Updated: 2024/02/16 14:26:30 by lmattern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	init_parser(t_parser *parser, const char **p, const char *cmd_str)
{
	*p = cmd_str;
	parser->arg_index = 0;
	parser->in_quotes = false;
	parser->arg_start = NULL;
	parser->args = NULL;
	parser->args = malloc((count_args(cmd_str) + 1) * sizeof(char *));
	if (!parser->args)
		return (-1);
	return (0);
}

static int	add_argument(t_parser *parser, int length)
{
	parser->args[parser->arg_index] = ft_strndup(parser->arg_start, length);
	if (parser->args[parser->arg_index] == NULL)
		return (free_array(&parser->args), -1);
	parser->arg_index++;
	parser->arg_start = NULL;
	return (0);
}

int	handle_quote(t_parser *parser, const char *p)
{
	parser->in_quotes = !parser->in_quotes;
	if (!parser->in_quotes)
	{
		if (add_argument(parser, p - parser->arg_start) == -1)
			return (-1);
	}
	else
		parser->arg_start = p + 1;
	return (0);
}

int	add_argument_if_needed(t_parser *parser, const char *p)
{
	int	length;

	if (parser->arg_start)
	{
		length = p - parser->arg_start;
		if (*(p + 1) == '\0')
			length += 1;
		if (add_argument(parser, length) == -1)
			return (-1);
	}
	return (0);
}

char	**parse_cmd(const char *cmd_str, t_data *data)
{
	t_parser	parser;
	const char	*p;

	if (init_parser(&parser, &p, cmd_str) == -1)
		return (NULL);
	while (*p)
	{
		if (*p == '\'')
		{
			if (handle_quote(&parser, p) == -1)
				return (NULL);
		}
		else if (!parser.in_quotes && (*p == ' ' || *(p + 1) == '\0'))
		{
			if (add_argument_if_needed(&parser, p) == -1)
				return (NULL);
		}
		else if (!parser.in_quotes && *p != ' ' && !parser.arg_start)
			parser.arg_start = p;
		p++;
	}
	parser.args[parser.arg_index] = NULL;
	if (parser.args == NULL)
		handle_cmd_err(NULL, data, NULL, NULL);
	return (parser.args);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long	ft_strtol(const char *nptr, char **endptr)
{
    long	result;
    int		sign;
	int		digit;

    result = 0;
    sign = 1;
    while ((*nptr >= '\t' && *nptr <= '\r') || *nptr == ' ')
        nptr++;
    if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
    while (*nptr >= '0' && *nptr <= '9')
	{
        digit = *nptr - '0';
        if ((sign == 1 && result > (INT_MAX - digit) / 10) || (sign == -1 && -result < (INT_MIN + digit) / 10))
            return (LONG_MAX);
        result = result * 10 + digit;
        nptr++;
    }
    if (endptr)
        *endptr = (char *)nptr;
    return (result * sign);
}

size_t	ft_count_wrds(char const *s, char c)
{
	size_t	nb_wrd;
	int		in_wrd;

	nb_wrd = 0;
	in_wrd = 0;
	while (*s)
	{
		if (*s != c && !in_wrd)
		{
			in_wrd = 1;
			nb_wrd++;
		}
		else if (*s == c && in_wrd)
			in_wrd = 0;
		s++;
	}
	return (nb_wrd);
}

char	**ft_free_array(char **array, size_t nb_wrd)
{
	char	**current;

	current = array;
	while (nb_wrd--)
	{
		free(*current);
		*current = NULL;
		current++;
	}
	free(array);
	return (NULL);
}

void    process_argument(char *arg, long *a, size_t *count)
{
	char	**tokens;
	char	*endptr;
	long	val;
	size_t	i;

	i = 0;
	// Gestion des arguments avec espaces
	tokens = ft_split(arg, " ");
	if (!tokens || !tokens[0])
	{
		if (tokens)
			ft_free_array(tokens, i);
		exit(ft_printf("%s", "Error\n"));
	}

	i = 0;
	while (tokens[i])
	{
		val = ft_strtol(tokens[i], &endptr);
		if (*endptr || val == LONG_MAX)
            exit(ft_free_array(tokens, i), ft_printf("%s", "Error\n"));
		a[*(count)++] = val;
		i++;
	}
	ft_free_array(tokens, i);
}

void	init_stack(long **a, int argc, char **argv)
{
	size_t	stack_size;
	size_t	count;
	size_t	i;

	stack_size = 0;
	count = 0;
	i = 1;
	while (i < argc)
		stack_size += ft_count_wrds(argv[i++], ' ');
	*a = malloc(stack_size * sizeof(long));
	if (*a == NULL)
		exit (ft_printf("%s", "Error\n"));
	i = 1;
	while (i < argc)
		process_argument(argv[i++], *a, &count);
}

int	main(int argc, char **argv)
{
	long *a;
	long *b;
	size_t	a_len;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (ft_printf("%s", "Error\n"), 1);
	init_stack(&a, argc, argv);
	if (!stack_sorted(a))
	{
		a_len = stack_len(a);
		if (a_len == 2)
			sa(&a, false);
		else if (a_len == 3)
			sort_three(&a);
		else
			sort_stack(&a, &b);
	}
	free_stack(&a);
	return 0;
}

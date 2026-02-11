/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_multiple.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhouzim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 14:28:05 by hkhouzim          #+#    #+#             */
/*   Updated: 2026/02/09 14:20:43 by hkhouzim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_duplicate_argv(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_strcmp(argv[i], argv[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static long	*convert_argv_to_long(char **argv, int ec)
{
	long	*arr;
	int		i;

	arr = malloc(sizeof(long) * ec);
	if (!arr)
		return (NULL);
	i = 0;
	while (i < ec)
	{
		arr[i] = ft_atoll(argv[i + 1]);
		i++;
	}
	return (arr);
}

static void	fill_stack(Stack **a, long *values, int ec)
{
	Stack	*tmp;
	int		i;

	tmp = *a;
	i = 0;
	while (tmp && i < ec)
	{
		tmp->value = values[i];
		tmp = tmp->next;
		i++;
	}
}

int	parse_multiple(Stack **a, char **argv, int argc)
{
	long	*values;
	int		ec;

	if (argc < 2)
		return (0);
	if (!valid_input_argv(argv))
		return (0);
	if (check_duplicate_argv(argv))
		return (0);
	ec = argc - 1;
	values = convert_argv_to_long(argv, ec);
	if (!values)
		return (0);
	fill_stack(a, values, ec);
	free(values);
	return (1);
}

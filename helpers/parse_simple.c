/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_simple.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhouzim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 14:26:51 by hkhouzim          #+#    #+#             */
/*   Updated: 2026/02/09 14:31:48 by hkhouzim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_duplicate(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (ft_strcmp(str[i], str[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
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

static void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static long	*convert_to_long_array(char **str_elements, int ec)
{
	long	*arr;
	int		i;

	arr = malloc(sizeof(long) * ec);
	if (!arr)
		return (NULL);
	i = 0;
	while (str_elements[i])
	{
		arr[i] = ft_atoll(str_elements[i]);
		i++;
	}
	return (arr);
}

int	parse_simple(Stack **a, char **argv)
{
	int		ec;
	char	**str_elements;
	long	*int_elements;

	ec = count_elements(argv[1]);
	str_elements = ft_split(argv[1], ' ');
	if (!str_elements)
		return (0);
	if (check_duplicate(str_elements))
		return (free_split(str_elements), 0);
	int_elements = convert_to_long_array(str_elements, ec);
	if (!int_elements)
		return (free_split(str_elements), 0);
	fill_stack(a, int_elements, ec);
	free_split(str_elements);
	free(int_elements);
	return (1);
}

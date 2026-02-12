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





int	parse_simple(Stack **a, char *str)
{
	char	**str_elements;
	Stack	*tmp;
	long	*values;
	int		ec;
	int		i;

	if (!valid_input_string(str))
		return (0);
	str_elements = ft_split(str, ' ');
	if (!str_elements)
		return (0);
	ec = 0;
	while (str_elements[ec])
		ec++;
	if (check_duplicate(str_elements))
		return (free_split(str_elements), 0);
	values = malloc(sizeof(long) * ec);
	if (!values)
		return (free_split(str_elements), 0);
	i = 0;
	while (i < ec)
	{
		values[i] = ft_atoll(str_elements[i]);
		i++;
	}
	tmp = *a;
	i = 0;
	while (tmp && i < ec)
	{
		tmp->value = values[i];
		tmp = tmp->next;
		i++;
	}
	free(values);
	free_split(str_elements);
	return (1);
}







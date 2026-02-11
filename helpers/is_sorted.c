/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhouzim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:53:23 by hkhouzim          #+#    #+#             */
/*   Updated: 2026/02/11 17:18:48 by hkhouzim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(Stack *stk)
{
	long long	*arr;
	int	i;
	int	size;

	arr = stack_to_array(stk);
	if (!arr)
		return (0);
	i = 0;
	size = ft_lstsize(stk);
	while (i < size - 1)
	{
		if (arr[i + 1] < arr[i])
		{
			free (arr);
			return (0);
		}
		i++;
	}
	free(arr);
	return (1);
}

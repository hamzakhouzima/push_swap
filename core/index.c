/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhouzim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 18:02:02 by hkhouzim          #+#    #+#             */
/*   Updated: 2026/02/12 15:47:14 by hkhouzim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	searh_element_in_arr(long long	*arr, long long elem, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == elem)
			return (i);
		i++;
	}
	return (-1);
}

void	index_stack(Stack *stk)
{
	long long	*arr;
	int	size;
	Stack	*tmp;

	size = ft_lstsize(stk);
	arr = stack_to_array(stk);
	if (!arr)
		return ;
	sort_arr(arr, size);
	tmp = stk;
	while (tmp)
	{
		tmp->index = searh_element_in_arr(arr, tmp->value, size);
		tmp = stk->next;
	}
	free (arr);
}

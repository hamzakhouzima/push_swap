/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_to_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhouzim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 15:56:26 by hkhouzim          #+#    #+#             */
/*   Updated: 2026/02/11 17:09:18 by hkhouzim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_stack_elements(Stack *stk)
{
	int	i;

	i = 0;
	while (stk)
	{
		i++;
		stk = stk->next;
	}
	return (i);
}

long long	*stack_to_array(Stack *stk)
{
	Stack		*tmp;
	int			arr_size;
	int			i;
	long long	*sort_arr;

	i = 0;
	arr_size = count_stack_elements(stk);
	sort_arr = malloc(arr_size * sizeof(long long));
	if (!sort_arr)
		return (NULL);
	tmp = stk;
	while (tmp)
	{
		sort_arr[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	return (sort_arr);
}

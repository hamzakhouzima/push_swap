/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhouzim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 16:41:41 by hkhouzim          #+#    #+#             */
/*   Updated: 2026/02/12 16:42:42 by hkhouzim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(Stack **a, Stack **b)
{
	int	size;

	size = ft_lstsize(*a);
	if (is_sorted(*a))
		return ;
	if (size == 2)
		sort_2(a);
	else if (size == 3)
		sort_3(a);
	else if (size <= 5)
		sort_5(a, b);
	else
		radix_sort(a, b);
}

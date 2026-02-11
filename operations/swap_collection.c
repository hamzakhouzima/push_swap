/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_collection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhouzim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 18:49:14 by hkhouzim          #+#    #+#             */
/*   Updated: 2026/02/11 18:49:37 by hkhouzim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(Stack **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(Stack **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(Stack **a, Stack **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}

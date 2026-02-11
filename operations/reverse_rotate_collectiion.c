/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_collectiion.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhouzim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 18:51:18 by hkhouzim          #+#    #+#             */
/*   Updated: 2026/02/11 18:51:38 by hkhouzim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(Stack **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(Stack **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(Stack **a, Stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}

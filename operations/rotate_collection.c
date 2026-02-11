/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_collection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhouzim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 18:50:37 by hkhouzim          #+#    #+#             */
/*   Updated: 2026/02/11 18:50:56 by hkhouzim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(Stack **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(Stack **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(Stack **a, Stack **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}

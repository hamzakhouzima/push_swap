/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_collection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhouzim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 18:49:58 by hkhouzim          #+#    #+#             */
/*   Updated: 2026/02/11 18:50:22 by hkhouzim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pa(Stack **a, Stack **b)
{
    Stack *tmp;

    if (!*b)
        return;
    tmp = *b;
    *b = (*b)->next;   // move head of b
    tmp->next = *a;    // attach it to a
    *a = tmp;          // update head of a
    write(1, "pa\n", 3);
}


void pb(Stack **a, Stack **b)
{
    Stack *tmp;

    if (!*a)
        return;
    tmp = *a;
    *a = (*a)->next;   // move head of a
    tmp->next = *b;    // attach it to b
    *b = tmp;          // update head of b
    write(1, "pb\n", 3);
}

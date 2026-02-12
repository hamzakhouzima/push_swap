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

int is_sorted(Stack *stk)
{
    Stack *tmp = stk;
    while (tmp && tmp->next)
    {
        if (tmp->index > tmp->next->index)
            return 0; // not sorted
        tmp = tmp->next;
    }
    return 1; // sorted
}


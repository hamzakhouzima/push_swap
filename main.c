/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhouzim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 16:00:00 by hkhouzim          #+#    #+#             */
/*   Updated: 2026/02/12 16:30:00 by hkhouzim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    Stack  *a;
    Stack  *b;
    int     size;
    Stack *tmp;

    a = NULL;
    b = NULL;
    if (!init_stack(&a, argc, argv))
    {
        error_exit(&a);
        return (1);
    }
    index_stack(a);
    if (is_sorted(a))
    {
        free_stack(&a);
        return (0);
    }
    size = ft_lstsize(a);
    if (size == 2)
        sa(&a);
    else if (size == 3)
        sort_three(&a);
    else
        radix_sort(&a, &b);

    tmp = a;
    while (tmp)
    {        printf("Value: %lld, Index: %d\n", tmp->value, tmp->index);
            tmp = tmp->next;
    }

    free_stack(&a);
    return (0);
}

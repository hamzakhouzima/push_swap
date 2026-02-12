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

int main(int argc, char **argv)
{
    Stack  *a;
    Stack  *b;
    int     size;

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
    free_stack(&a);
    return (0);
}

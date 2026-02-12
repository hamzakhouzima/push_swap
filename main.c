/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhouzim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 15:44:14 by hkhouzim          #+#    #+#             */
/*   Updated: 2026/02/09 15:11:23 by hkhouzim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

#include "push_swap.h"

#include <stdio.h>  // For debug prints

int main(int argc, char **argv)
{
    Stack *a = NULL;
    Stack *b = NULL;

    // Initialize the stack
    if (!init_stack(&a, argc, argv)){
        error_exit(&a);
		return 1;
	}

    // Debug: print original stack
    printf("Initial stack:\n");
    Stack *tmp = a;
    while (tmp)
    {
        printf("value: %lld\n", tmp->value);
        tmp = tmp->next;
    }

    // Index the stack
    index_stack(a);

    // Debug: print indexed stack
    printf("Indexed stack:\n");
    tmp = a;
    while (tmp)
    {
        printf("value: %lld, index: %d\n", tmp->value, tmp->index);
        tmp = tmp->next;
    }

    // Check if already sorted
    if (is_sorted(a))
    {
        printf("Stack already sorted, nothing to do.\n");
        free_stack(&a);
        return (0);
    }

    int size = ft_lstsize(a);

    // Choose sorting method
    if (size == 2)
        sa(&a);  // Swap if needed
    else if (size == 3)
        sort_three(&a);
    else
        radix_sort(&a, &b);

    // Debug: print final stack
    printf("Final stack:\n");
    tmp = a;
    while (tmp)
    {
        printf("value: %lld, index: %d\n", tmp->value, tmp->index);
        tmp = tmp->next;
    }

    free_stack(&a);
    return (0);
}

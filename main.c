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



int main(int argc, char **argv)
{
    Stack *a;
    Stack *b;
    int size;

    a  = NULL;
    b  = NULL;
    if (!init_stack(&a, argc, argv)){
        error_exit(&a);
		return 1;
	}


    Stack *tmp = a;
    while (tmp)
    {
        tmp = tmp->next;
    }

    index_stack(a);


    tmp = a;
    while (tmp)
    {
        tmp = tmp->next;
    }

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
    {
        tmp = tmp->next;
    }
    free_stack(&a);
    return (0);
}

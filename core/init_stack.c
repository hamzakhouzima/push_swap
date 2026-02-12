/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhouzim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 15:12:38 by hkhouzim          #+#    #+#             */
/*   Updated: 2026/02/01 14:16:44 by hkhouzim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static Stack *create_stack(long size)
{
    Stack *head = NULL;
    Stack *new_node;
    long counter = 0;

    while (counter < size)
    {
        new_node = ft_lstnew(0); // initialize value to 0
        if (!new_node)
        {
            free_stack(&head); // free already allocated nodes
            return NULL;
        }
        ft_lstadd_back(&head, new_node); // maintain argv order
        counter++;
    }
    return head;
}

int init_stack(Stack **a, int argc, char **argv)
{
	int ec;

	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		ec = count_elements(argv[1]);
		*a = create_stack(ec);
		if (!*a)
			return (0);
		if (!parse_simple(a, argv[1]))
			return (free_stack(a), 0);
	}
	else
	{
		ec = argc - 1;
		*a = create_stack(ec);
		if (!*a)
			return (0);
		if (!parse_multiple(a, argv, argc))
			return (free_stack(a), 0);
	}
	return (1);
}




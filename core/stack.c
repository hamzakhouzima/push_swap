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

Stack	*create_stack(long size)
{
	Stack	*head;
	Stack	*new_node;
	long	counter;

	counter = size;
	head = NULL;
	while (counter > 0)
	{
		new_node = ft_lstnew(counter);
		if (!new_node)
			return (NULL);
		ft_lstadd_front(&head, new_node);
		counter--;
	}
	return (head);
}

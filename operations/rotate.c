/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhouzim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:25:02 by hkhouzim          #+#    #+#             */
/*   Updated: 2026/02/11 16:25:24 by hkhouzim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rotate(Stack **s)
{
	Stack	*first;
	Stack	*last;

	if (!*s || !(*s)->next)
		return ;
	first = *s;
	*s = first->next;
	first->next = NULL;
	last = *s;
	while (last->next)
		last = last->next;
	last->next = first;
}

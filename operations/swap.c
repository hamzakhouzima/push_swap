/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhouzim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:24:17 by hkhouzim          #+#    #+#             */
/*   Updated: 2026/02/11 16:24:41 by hkhouzim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(Stack **s)
{
	Stack	*first;
	Stack	*second;

	if (!*s || !(*s)->next)
		return ;
	first = *s;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*s = second;
}

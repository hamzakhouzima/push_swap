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
#include <stdio.h>



int	main(int argc, char **argv)
{
	Stack	*stk;

	stk = NULL;
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		if (!parse_simple(&stk, argv))
		{
			write(2, "Error\n", 6);
		//	free_stack(&stk);
			return (1);
		}
	}
	else if (!parse_multiple(&stk, argv, argc))
	{
		write(2, "Error\n", 6);
		//free_stack(&stk);
		return (1);
	}
	// print_stack(stk); // Optional: for debugging
	//free_stack(&stk);
	return (0);
}

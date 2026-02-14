/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhouzim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 10:31:27 by hkhouzim          #+#    #+#             */
/*   Updated: 2026/02/09 14:18:04 by hkhouzim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

long long ft_atoll(const char *str, Stack *stack, void (*cleanup)(char **), char **str_elements, long *arr, long *values)   
{
	long long	i;
	long long	sign;
	long long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (sign == 1 && (result > 922337203685477580LL || \
			(result == 922337203685477580LL && (str[i] - '0') > 7)))
			{
				if (arr)
					free(arr);
				if (str_elements)
					cleanup(str_elements);
				if (values)
					free(values);
				error_exit(&stack);
				// return (error_exit(&stk));
			}
			
		if (sign == -1 && (result > 922337203685477580LL || \
			(result == 922337203685477580LL && (str[i] - '0') > 8)))
			{
				free(arr);
				cleanup(str_elements);
				error_exit(&stack);
			}
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

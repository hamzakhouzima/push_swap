/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhouzim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 10:05:43 by hkhouzim          #+#    #+#             */
/*   Updated: 2026/01/29 17:22:19 by hkhouzim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strdup(const char *str)
{
	int		i;
	char	*duplicate;

	if (!str)
		return (NULL);
	duplicate = (char *)malloc(ft_strlen(str) + 1 * sizeof(char));
	i = 0;
	while (str[i])
	{
		duplicate[i] = str[i];
		i++;
	}
	return (duplicate);
}

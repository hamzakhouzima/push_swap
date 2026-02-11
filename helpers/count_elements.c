/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhouzim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 16:55:35 by hkhouzim          #+#    #+#             */
/*   Updated: 2026/02/02 14:51:48 by hkhouzim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	count_elements(char *input)
{
	int	i;
	int	in_element;
	int	count;

	i = 0;
	in_element = 0;
	count = 0;
	while (input[i])
	{
		if (input[i] != ' ' && in_element == 0)
		{
			in_element = 1;
			count++;
		}
		else if (input[i] == ' ' && in_element == 1)
		{
			in_element = 0;
		}
		i++;
	}
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhouzim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 16:45:08 by hkhouzim          #+#    #+#             */
/*   Updated: 2026/02/03 15:44:06 by hkhouzim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	word_count(char *str, int c)
{
	int	i;
	int	inside_word;
	int	count;

	i = 0;
	count = 0;
	inside_word = 0;
	while (str[i] == c)
		i++;
	while (str[i])
	{
		if (str[i] != c && inside_word == 0)
		{
			inside_word = 1;
			count++;
		}
		else if (str[i] == c && inside_word == 1)
		{
			inside_word = 0;
		}
		i++;
	}
	return (count);
}

char	*ft_strdup(char *str, int c)
{
	int		i;
	int		start;
	int		j;
	char	*duplicate;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] == c)
		i++;
	start = i;
	while (str[i] && str[i] != c)
		i++;
	duplicate = malloc((i - start) + 1);
	if (!duplicate)
		return (NULL);
	j = 0;
	while (j < (i - start))
	{
		duplicate[j] = str[start + j];
		j++;
	}
	duplicate[j] = '\0';
	return (duplicate);
}

char	**ft_split(char *s, int c)
{
	int		i;
	int		wc;
	char	**container;

	i = 0;
	wc = word_count(s, c);
	container = malloc((wc + 1) * sizeof(char *));
	if (!container)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			container[i] = ft_strdup(s, c);
			i++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	container[i] = NULL;
	return (container);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 00:59:01 by ajeannin          #+#    #+#             */
/*   Updated: 2021/12/09 06:34:29 by ajeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	count_words(const char *str, char c)
{
	int	i;
	int	breaking_point;

	i = 0;
	breaking_point = 0;
	while (*str)
	{
		if (*str != c && breaking_point == 0)
		{
			breaking_point = 1;
			i++;
		}
		else if (*str == c)
			breaking_point = 0;
		str++;
	}
	return (i);
}

static	char	*word_dup(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

static	char	**helpsplit(int index, char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**new;

	i = 0;
	j = 0;
	new = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!new)
		return (0);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			new[j++] = word_dup(s, index, i);
			index = -1;
		}
		i++;
	}
	new[j] = 0;
	return (new);
}

char	**ft_split(char const *s, char c)
{
	int	index;

	index = -1;
	if (!s)
		return (0);
	return (helpsplit(index, s, c));
}

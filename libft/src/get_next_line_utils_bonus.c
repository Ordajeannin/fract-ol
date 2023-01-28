/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:46:13 by ajeannin          #+#    #+#             */
/*   Updated: 2022/11/07 18:43:33 by ajeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen2(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
		i++;
	return (i);
}

char	*ft_is_newline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (&str[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin2(char *stash, char *buffer)
{
	int		i;
	int		j;
	char	*str;

	if (!stash)
	{
		stash = malloc(sizeof(char) * 1);
		stash[0] = '\0';
	}
	if (!stash || !buffer)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen2(stash) + ft_strlen2(buffer)) + 1));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	if (stash)
		while (stash[++i] != '\0')
			str[i] = stash[i];
	while (buffer[j] != '\0')
		str[i++] = buffer[j++];
	str[ft_strlen2(stash) + ft_strlen2(buffer)] = '\0';
	free(stash);
	return (str);
}

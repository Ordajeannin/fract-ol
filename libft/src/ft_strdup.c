/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:51:02 by ajeannin          #+#    #+#             */
/*   Updated: 2021/12/08 18:00:36 by ajeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dup;

	i = ft_strlen(s) + 1;
	dup = malloc(sizeof(char) * i);
	if (dup == NULL)
		return (NULL);
	ft_memcpy(dup, s, i);
	return (dup);
}

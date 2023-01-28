/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 16:15:18 by ajeannin          #+#    #+#             */
/*   Updated: 2021/11/26 16:42:26 by ajeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *ocean, const char *pearl, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!pearl[0])
		return ((char *)ocean);
	while (ocean[i] && i < len)
	{
		while (ocean[i + j] && pearl[j]
			&& i + j < len && ocean[i + j] == pearl[j])
			j++;
		if (!pearl[j])
			return ((char *)ocean + i);
		i++;
		j = 0;
	}
	return (NULL);
}

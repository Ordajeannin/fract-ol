/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 18:11:01 by ajeannin          #+#    #+#             */
/*   Updated: 2021/11/26 15:24:32 by ajeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;
	size_t	i;

	if (!dest && !src)
		return (NULL);
	d = (char *)dest;
	s = (char *)src;
	i = 0;
	if (s < d)
		while (n-- > 0)
			d[n] = s[n];
	else
	{	
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}

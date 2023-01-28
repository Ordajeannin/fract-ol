/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 19:09:36 by ajeannin          #+#    #+#             */
/*   Updated: 2022/03/27 16:22:20 by ajeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	c2;

	ptr = (unsigned char *)s;
	c2 = (unsigned char)c;
	while (n--)
	{
		if (*ptr == c2)
			return (ptr);
		else
			ptr++;
	}
	return (NULL);
}

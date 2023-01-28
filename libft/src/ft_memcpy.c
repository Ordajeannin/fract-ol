/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:02:19 by ajeannin          #+#    #+#             */
/*   Updated: 2022/03/27 16:16:21 by ajeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	const char	*src2;
	char		*dst2;

	if (!dst && !src)
		return (NULL);
	i = 0;
	src2 = (const char *)src;
	dst2 = (char *)dst;
	while (i < n)
	{
		dst2[i] = src2[i];
		i++;
	}
	return (dst);
}

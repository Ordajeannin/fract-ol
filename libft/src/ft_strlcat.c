/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 13:16:24 by ajeannin          #+#    #+#             */
/*   Updated: 2022/03/27 16:08:34 by ajeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*d;
	const char	*s;
	size_t		n;
	size_t		dstlen;

	d = dst;
	s = src;
	n = size;
	dstlen = 0;
	while (n-- != 0 && *d != '\0')
		d++;
	dstlen = d - dst;
	n = size - dstlen;
	if (n-- == 0)
		return (dstlen + ft_strlen(s));
	while (*s && n != 0)
	{
		*d++ = *s;
		n--;
		s++;
	}
	*d = '\0';
	return (dstlen + ft_strlen(src));
}

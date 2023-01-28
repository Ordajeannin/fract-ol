/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:26:59 by ajeannin          #+#    #+#             */
/*   Updated: 2022/11/04 19:13:41 by ajeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*dst;

	if (count == SIZE_MAX && size == SIZE_MAX)
		return (0);
	dst = (void *)malloc(count * size);
	if (!dst)
		return (0);
	ft_bzero(dst, count * size);
	return (dst);
}

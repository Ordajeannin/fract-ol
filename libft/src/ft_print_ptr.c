/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:55:21 by ajeannin          #+#    #+#             */
/*   Updated: 2022/11/07 18:22:00 by ajeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_reput_ptrvalue_in_hexa(unsigned long int nbr)
{
	int		i;
	int		len;
	char	address[20];
	char	*hexa;

	i = 0;
	len = 0;
	ft_memset(address, 'z', 21);
	hexa = "0123456789abcdef";
	while (nbr >= 16)
	{
		address[i] = hexa[nbr % 16];
		nbr = nbr / 16;
		i++;
	}
	address[i] = hexa[nbr];
	len = i + 1;
	while (i >= 0)
	{
		write (1, &address[i], 1);
		i--;
	}
	return (len);
}

int	ft_print_ptr(unsigned long int ptr)
{
	int	print_length;

	print_length = 0;
	if (ptr == 0)
	{
		print_length += write(1, "(nil)", 5);
		return (print_length);
	}
	print_length = write(1, "0x", 2);
	print_length += ft_reput_ptrvalue_in_hexa(ptr);
	return (print_length);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:57:47 by ajeannin          #+#    #+#             */
/*   Updated: 2022/11/07 18:21:25 by ajeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_put_in_hexa(unsigned long int nbr, char *hexa)
{
	int		i;
	int		len;
	char	res[20];

	i = 0;
	len = 0;
	ft_memset(res, 'x', 21);
	while (nbr >= 16)
	{
		res[i] = hexa[nbr % 16];
		nbr = nbr / 16;
		i++;
	}
	res[i] = hexa[nbr];
	len = i + 1;
	while (i >= 0)
	{
		write(1, &res[i], 1);
		i--;
	}
	return (len);
}

int	ft_print_hexa(unsigned long int nbr, const char conv)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	if (nbr == 0)
		return (write(1, "0", 1));
	else
	{
		if (conv == 'x')
			return (ft_put_in_hexa(nbr, hexa));
		else if (conv == 'X')
		{
			hexa = "0123456789ABCDEF";
			return (ft_put_in_hexa(nbr, hexa));
		}
	}
	return (0);
}

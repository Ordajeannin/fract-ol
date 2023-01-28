/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:36:02 by ajeannin          #+#    #+#             */
/*   Updated: 2022/11/07 18:21:12 by ajeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_formats(va_list args, const char conv)
{
	int	print_length;

	print_length = 0;
	if (conv == 'c')
		print_length += ft_print_char(va_arg(args, int));
	else if (conv == 's')
		print_length += ft_print_str(va_arg(args, char *));
	else if (conv == 'p')
		print_length += ft_print_ptr(va_arg(args, unsigned long int));
	else if (conv == 'd' || conv == 'i')
		print_length += ft_print_nbr(va_arg(args, int));
	else if (conv == 'u')
		print_length += ft_print_unsigned(va_arg(args, unsigned long int));
	else if (conv == 'x' || conv == 'X')
		print_length += ft_print_hexa(va_arg(args, unsigned int), conv);
	else if (conv == '%')
		print_length += ft_print_percent();
	return (print_length);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		print_length;

	i = 0;
	print_length = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			print_length += ft_formats(args, str[i + 1]);
			i++;
		}
		else
			print_length += ft_print_char(str[i]);
		i++;
	}
	va_end(args);
	return (print_length);
}

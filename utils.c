/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannin <ajeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:46:07 by ajeannin          #+#    #+#             */
/*   Updated: 2023/02/03 13:51:40 by ajeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_error(t_data *data)
{
	ft_printf("\nuse ./aout | mandelbrot | julia <options>\n\n");
	ft_printf("-	<options> are real and imaginary part of julia :  -2 <= r|i <= 2\n");
	ft_printf("-	'g' display a graph\n");
	ft_printf("-	'+'/'-' to surf on this graph. 'r'/'i' to switch axe\n");
	ft_printf("-	'1'->'9' to change change the step, biggest to lowest\n");
	ft_printf("\n                   and... enjoy :)\n\n");
	return (1);
}

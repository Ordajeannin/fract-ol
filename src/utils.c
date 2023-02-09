/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannin <ajeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:46:07 by ajeannin          #+#    #+#             */
/*   Updated: 2023/02/09 22:19:37 by ajeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_error(void)
{
	ft_printf("\n                      DOESN'T WORK?\n");
	ft_printf("--------------------------------------------------------\n\n");
	ft_printf("use ./fractol | mandelbrot | julia <options> | ");
	ft_printf("burningship\n\n");
	ft_printf("-	<options> are real and imaginary part of julia :  ");
	ft_printf("-2 <= r|i <= 2\n");
	ft_printf("-	on julia? click wherever you want!\n\n");
	ft_printf("--------------------------------------------------------\n\n");
	ft_printf("     AND NOW... YOUR KEYBOARD IS YOUR NEW BEST FRIEND :)\n\n");
	ft_printf("-	'g' display a graph\n");
	ft_printf("-	'+'/'-' to surf on this graph. 'r'/'i' to switch axe\n");
	ft_printf("-	'1'->'9' to change the step, biggest to lowest\n");
	ft_printf("-	'Spacebar' to change colors\n");
	ft_printf("-	zoom with mouse's wheel\n");
	ft_printf("-	increase 'IT_MAX' in the makefile to improve details\n");
	ft_printf("\n\n\nenjoy!\n\n");
	return (1);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*pixel;
	int		index;

	index = (y * data->ll + x * (data->bpp / 8));
	pixel = data->img_addr + index;
	*(unsigned int *) pixel = color;
}

double	ft_abs(t_complex z)
{
	double	x;
	double	y;
	double	value;

	x = z.r;
	y = z.i;
	value = sqrt(x * x + y * y);
	return (value);
}

int	render(t_data *data)
{
	if (data->win == NULL)
		return (1);
	if (data->fract == 0)
	{
		mandelbrot(data);
	}
	if (data->fract == 1)
	{
		julia(data);
	}
	if (data->fract == 2)
	{
		burningship(data);
	}
	if (data->graph == 1)
		graph_draw(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}

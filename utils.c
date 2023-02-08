/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannin <ajeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:46:07 by ajeannin          #+#    #+#             */
/*   Updated: 2023/02/08 20:53:19 by ajeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_error(t_data *data)
{
	ft_printf("\nuse ./aout | mandelbrot | julia <options>\n\n");
	ft_printf("-	<options> are real and imaginary part of julia :  ");
	ft_printf("-2 <= r|i <= 2\n");
	ft_printf("-	'g' display a graph\n");
	ft_printf("-	'+'/'-' to surf on this graph. 'r'/'i' to switch axe\n");
	ft_printf("-	'1'->'9' to change change the step, biggest to lowest\n");
	ft_printf("\n                   and... enjoy :)\n\n");
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

int	ft_abs(t_complex z)
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

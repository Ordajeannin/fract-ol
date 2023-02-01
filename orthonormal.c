/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orthonormal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannin <ajeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:46:00 by ajeannin          #+#    #+#             */
/*   Updated: 2023/02/01 18:51:31 by ajeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	julia_graph(t_data *data, double x, double y)
{
	int	dot;

	dot = 0;
	if (x <= ((WIDTH / 2) + 2) && x >= ((WIDTH / 2) - 2))
		my_mlx_pixel_put(data, (int)x, (int)y, RED);
	if (y <= ((HEIGHT / 2) + 2) && y >= ((WIDTH / 2) - 2))
		my_mlx_pixel_put(data, (int)x, (int)y, RED);
	if (x <= get_pos_x(data) + 4 && x >= get_pos_x(data) - 4)
		dot = 1;
	if (dot == 1 && y <= get_pos_y(data) + 4 && y >= get_pos_y(data) - 4)
		my_mlx_pixel_put(data, (int)x, (int)y, RED);
}

static void	mandelbrot_graph(t_data *data, double x, double y)
{
	if (x <= (((WIDTH * 2) / 3) + 2) && (x >= (((WIDTH * 2) / 3) - 2)))
		my_mlx_pixel_put(data, (int)x, (int)y, RED);
	if (y <= ((HEIGHT / 2) + 2) && y >= ((HEIGHT / 2) - 2))
		my_mlx_pixel_put(data, (int)x, (int)y, RED);
}

void	graph_draw(t_data *data)
{
	int		x;
	int		y;
	double	pos_r;
	double	pos_i;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			if (data->fract == 0)
				mandelbrot_graph(data, (double)x, (double)y);
			if (data->fract == 1)
				julia_graph(data, (double)x, (double)y);
		}
	}
}

void	graph_switch(t_data *data)
{
	ft_printf("graph_switch\n");
	if (data->graph == 0)
		data->graph = 1;
	else if (data->graph == 1)
		data->graph = 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannin <ajeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:45:44 by ajeannin          #+#    #+#             */
/*   Updated: 2023/02/01 19:13:59 by ajeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*pixel;
	int		index;

	index = (y * data->ll + x * (data->bpp / 8));
	pixel = data->img_addr + index;
	*(unsigned int *) pixel = color;
}

// static int	calculate_fractal(t_data *data, double zr, double zi)
// {
// 	int		n;
// 	double	tmp;
// 	double complex	z;

// 	n = 0;
// 	while (n < IT_MAX)
// 	{
// 		if ((zi * zi + zr * zr) > 4.0)
// 			break ;
// 		tmp = 2 * zr * zi + data->ji;
// 		zr = zr * zr - zi * zi + data->jr;
// 		zi = tmp;
// 		n++;
// 	}
// 	z = zr + zi * I;
// 	if (n == IT_MAX)
// 		return (n);
// 	else
// 		return (n - log(log2(abs(z))));
// 	return (n);
// }

static int	calculate_fractal(t_data *data, double zr, double zi)
{
	int		n;
	double	tmp;

	n = 0;
	while (n < IT_MAX)
	{
		if ((zi * zi + zr * zr) > 4.0)
			break ;
		tmp = 2 * zr * zi + data->ji;
		zr = zr * zr - zi * zi + data->jr;
		zi = tmp;
		n++;
	}
	return (n);
}

void	julia(t_data *data)
{
	int		x;
	int		y;
	double	pos_r;
	double	pos_i;
	int		nb_iter;

	mlx_clear_window(data->mlx, data->win);
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			pos_r = get_pos_r(data, (double)x);
			pos_i = get_pos_i(data, (double)y);
			nb_iter = calculate_fractal(data, pos_r, pos_i);
			if (nb_iter == IT_MAX)
				my_mlx_pixel_put(data, x, y, 0x00000000);
			else
				my_mlx_pixel_put(data, x, y,
					encode_trgb(255, nb_iter * 5, nb_iter * 10, nb_iter * 20));
		}
	}
}

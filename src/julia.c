/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannin <ajeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:45:44 by ajeannin          #+#    #+#             */
/*   Updated: 2023/02/14 17:19:40 by ajeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

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

static double	calculate_multifract(t_data *data, double zr, double zi)
{
	int			n;
	double		tmp;
	t_complex	j;
	t_complex	z;

	j.r = data->jr;
	j.i = data->ji;
	z.r = zr;
	z.i = zi;
	n = 0;
	while (n < IT_MAX && ft_abs(z) <= 2)
	{
		tmp = pow((z.r * z.r + z.i * z.i), (POW / 2))
			* cos(POW * atan2(z.i, z.r)) + j.r;
		z.i = pow((z.r * z.r + z.i * z.i), (POW / 2))
			* sin(POW * atan2(z.i, z.r)) + j.i;
		z.r = tmp;
		n++;
	}
	if (n == IT_MAX)
		return (n);
	else
		return (n + 1 - log(log2(ft_abs(z))));
}

// /*
// Z0 = j
// Zn+1 = 
// */
static double	calculate_fractal(t_data *data, double zr, double zi)
{
	int			n;
	double		tmp;
	t_complex	j;
	t_complex	z;

	if (data->pow == 1)
		return (calculate_multifract(data, zr, zi));
	j.r = data->jr;
	j.i = data->ji;
	z.r = zr;
	z.i = zi;
	n = 0;
	while (n < IT_MAX && ft_abs(z) <= 2)
	{
		tmp = z.r * z.r - z.i * z.i;
		z.i = 2 * z.r * z.i + j.i;
		z.r = tmp + j.r;
		n++;
	}
	if (n == IT_MAX)
		return (n);
	else
		return (n + 1 - log(log2(ft_abs(z))));
}

/*
Determine the position of each pixel on the complex plan,
compute them, and apply the color.
*/
void	julia(t_data *data)
{
	int		x;
	int		y;
	double	pos_r;
	double	pos_i;
	double	nb_iter;

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
				apply_color(data, x, y, nb_iter);
		}
	}
}

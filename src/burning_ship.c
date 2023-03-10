/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannin <ajeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 20:42:32 by ajeannin          #+#    #+#             */
/*   Updated: 2023/02/14 18:12:14 by ajeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

//Z0 = 0
//Zn+1 = |Zn|^2 + c
static double	calculate_fractal(double cr, double ci)
{
	int			n;
	double		tmp;
	t_complex	c;
	t_complex	z;

	c.r = cr;
	c.i = ci;
	z.r = 0;
	z.i = 0;
	n = 0;
	while (n < IT_MAX && ft_abs(z) <= 2)
	{
		z.r = fabs(z.r);
		z.i = fabs(z.i);
		tmp = 2 * z.r * z.i + c.i;
		z.r = z.r * z.r - z.i * z.i + c.r;
		z.i = tmp;
		n++;
	}
	if (n == IT_MAX)
		return (n);
	else
		return (n + 1 - log(log2(ft_abs(z))));
}

void	burningship(t_data *data)
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
			nb_iter = calculate_fractal(pos_r, pos_i);
			if (nb_iter == IT_MAX)
				my_mlx_pixel_put(data, x, y, 0x00000000);
			else
				apply_color(data, x, y, nb_iter);
		}
	}
}

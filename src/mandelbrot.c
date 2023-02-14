/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannin <ajeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:45:57 by ajeannin          #+#    #+#             */
/*   Updated: 2023/02/14 17:09:06 by ajeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

// static	double	calculate_fractal(t_data *data, double cr, double ci)
// {
// 	double			zr;
// 	double			zi;
// 	double			tmp;
// 	double complex	z;

// 	zr = 0;
// 	zi = 0;
// 	data->it = 0;
// 	while (data->it < IT_MAX)
// 	{
// 		if ((zr * zr + zi * zi) > 4.0)
// 			break ;
// 		tmp = 2 * zr * zi + ci;
// 		zr = zr * zr - zi * zi + cr;
// 		zi = tmp;
// 		data->it++;
// 	}
// 	z = zr + zi * I;
// 	if (data->it == IT_MAX)
// 		return (data->it);
// 	else
// 		return (data->it + 1 - log(log2(abs(z))));
// 	// else
// 	// 	return (data->it);
// }

// A black pixel went to IT_MAX, so the more you have black one a picture
// the slower is the generation. so we want to optimize it!
// For exemple, in mandelbrot set, we already know coordonates
// of points who belong to the "cardioid" part,
// and the main "bulb" to. so no need to compute them!
// if x < p - 2(p^2) + 1/4, with p = sqrt((x -1/4)^2 + y^2)
// 	-> point belong to the cardioid, black pixel
// if (x + 1)^2 + y^2 < 1/16
// 	-> point belong to the main bulb, black pixel
static int	opti_fractal(double x, double y)
{
	double	p;
	double	p2;

	p = sqrt(((x - 0.25) * (x - 0.25)) + (y * y));
	p2 = (x - 0.25) * (x - 0.25) + (y * y);
	if (x < (p - (2 * p2) + 0.25))
		return (0);
	if ((((x + 1) * (x + 1)) + (y * y)) < 0.0625)
		return (0);
	return (42);
}

/*
mandelbrot :  
Z0 = 0
Zn+1 = Zn^2 + c

c/z are points on the complex plan, so c(cr, ci) and z(zr, zi)
*/
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
	if (opti_fractal(cr, ci) == 0)
		return (0);
	while (n < IT_MAX && ft_abs(z) <= 2)
	{
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

/*
Determine the position of each pixel on the complex plan,
compute them, and apply the color.
"#pragma omp parallel for" multithreading?
	didn't tryed, just saw that on StackOverflow, maybe for later
*/
void	mandelbrot(t_data *data)
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

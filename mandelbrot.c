#include "fractol.h"

double ft_abs(double zr, double zi)
{
	double z;

	z = sqrt((zr * zr) + (zi * zi));
	return z;
}

// static int  calculate_fractal(t_data *data, double cr, double ci)
// {
// 	double	zr;
// 	double	zi;
// 	double	tmp;
// 	double escape_radius = 2100.0;
// 	double modulus;

// 	zr = 0;
// 	zi = 0;
//     data->it = 0;
// 	while (data->it < IT_MAX && (modulus = sqrt(zr*zr + zi + zi)) < escape_radius)
// 	{
// 		if ((zr * zr + zi * zi) > 4.0)
// 			break ;
// 		tmp = 2 * zr * zi + ci;
// 		zr = zr * zr - zi * zi + cr;
// 		zi = tmp;
// 		data->it++;
// 	}
// 		tmp = 2 * zr * zi + ci;
// 		zr = zr * zr - zi * zi + cr;
// 		zi = tmp;
// 		data->it++;
// 		tmp = 2 * zr * zi + ci;
// 		zr = zr * zr - zi * zi + cr;
// 		zi = tmp;
// 		data->it++;
// 	modulus = sqrt(zr * zr + zi * zi);
// 	double mu = data->it - (log(log(modulus)))/log(2.0);
// 	double complex z = zr + zi * I;
// 	if (data->it == IT_MAX)
// 		return (data->it);
// 	else
// 		return (mu);
// 	// else
// 	// 	return (data->it + 1 - log(log2(abs(z))));
// }

static int  calculate_fractal(t_data *data, double cr, double ci)
{
	double	zr;
	double	zi;
	double	tmp;

	zr = 0;
	zi = 0;
    data->it = 0;
	while (data->it < IT_MAX)
	{
		if ((zr * zr + zi * zi) > 4.0)
			break ;
		tmp = 2 * zr * zi + ci;
		zr = zr * zr - zi * zi + cr;
		zi = tmp;
		data->it++;
	}
	// return (data->it);
	// return (data->it + 1 - log(log2(abs(cmplx(zr, zi)))));
	double complex z = zr + zi * I;
	// t_complex z = { zr, zi};
	if (data->it == IT_MAX)
		return (data->it);
	// else
	// 	return (data->it + 1 - log(log2(ft_abs(zr, zi))));
	else
		return (data->it + 1 - log(log2(abs(z))));
}

void mandelbrot(t_data *data)
{
    int		x;
	int		y;
	double	pr;
	double	pi;
	int		nb_iter;

	mlx_clear_window(data->mlx, data->win);
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			pr = data->min_r + ((double)x / WIDTH) * (data->max_r - data->min_r);
			pi = data->max_i + ((double)y / HEIGHT) * (data->min_i - data->max_i);
			nb_iter = calculate_fractal(data, pr, pi);
            if (nb_iter == IT_MAX)
			    my_mlx_pixel_put(data, x, y, 0x00000000);
            else
                my_mlx_pixel_put(data, x, y, encode_trgb(255, nb_iter * 5, nb_iter * 10, nb_iter * 20));
			// else
			// 	my_mlx_pixel_put(data, x, y, encode_trgb(255, (255/IT_MAX) * nb_iter, 255 - nb_iter, 255 - nb_iter));
		}
	}
	// mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

/*smooth coloring : 
to remove bands, use a fractionnal escape count -> "normalized iteration count"
with n = nb_iter and z last computed complex value

n + 1 - log(log2(abs(cmplx(zr))))

linear interpolation : color1, color2, t

return color1 * (1 - t) + color2 * t

*/

// double ft_abs(double zr, double zi)
// {
// 	double z;

// 	z = sqrt((zr * zr) + (zi * zi));
// 	return z;
// }

int render(t_data *data)
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
    // mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	if (data->graph == 1)
		graph_draw(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
    return (0);
}
#include "fractol.h"

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *pixel;
    int index;

    index = (y * data->ll + x * (data->bpp / 8));
    pixel = data->img_addr + index;
    *(unsigned int*) pixel = color;
}

static int	calculate_fractal(t_data *data, double zr, double zi)
{
	int		n;
	double	tmp;

	// data->jr = 0.285;
	// data->ji = 0.01;
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
			pos_r = data->min_r + (double)x * (data->max_r - data->min_r) / WIDTH;
			pos_i = data->max_i + (double)y * (data->min_i - data->max_i) / HEIGHT;
			nb_iter = calculate_fractal(data, pos_r, pos_i);
            if (nb_iter == IT_MAX)
			    my_mlx_pixel_put(data, x, y, 0x00000000);
            else
                my_mlx_pixel_put(data, x, y, encode_trgb(255, nb_iter * 5, nb_iter * 10, nb_iter * 20));
			// if (nb_iter < IT_MAX)
			// 	my_mlx_pixel_put(data, x, y, encode_trgb(255,  nb_iter * 170 % 255, 255, 255));
			// else
			// 	my_mlx_pixel_put(data, x, y, 0x00000000);
		}
	}
	// mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
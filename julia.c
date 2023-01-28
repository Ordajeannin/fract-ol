#include "fractol.h"

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *pixel;
    int index;

    index = (y * data->ll + x * (data->bpp / 8));
    pixel = data->img_addr + index;
    *(unsigned int*) pixel = color;
}

static int	calculate_fractal(t_data *f, double zr, double zi)
{
	int		n;
	double	tmp;

	f->jr = 0.285;
	f->ji = 0.01;
	n = 0;
	while (n < IT_MAX)
	{
		if ((zi * zi + zr * zr) > 4.0)
			break ;
		tmp = 2 * zr * zi + f->ji;
		zr = zr * zr - zi * zi + f->jr;
		zi = tmp;
		n++;
	}
	return (n);
}

void	julia(t_data *f)
{
	int		x;
	int		y;
	double	pr;
	double	pi;
	int		nb_iter;

	mlx_clear_window(f->mlx, f->win);
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			pr = f->min_r + (double)x * (f->max_r - f->min_r) / WIDTH;
			pi = f->max_i + (double)y * (f->min_i - f->max_i) / HEIGHT;
			nb_iter = calculate_fractal(f, pr, pi);
			if (nb_iter < IT_MAX)
				my_mlx_pixel_put(f, x, y, encode_trgb(255,  nb_iter * 170 % 255, 255, 255));
			else
				my_mlx_pixel_put(f, x, y, 0x00000000);
		}
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}
#include "fractol.h"

int	handle_keypress(int keycode, t_data *data)
{
    
	if (keycode == XK_Escape)
	{
		mlx_destroy_window(data->mlx, data->win);
		data->win = NULL;
        mlx_destroy_image(data->mlx, data->img);
        // mlx_destroy_display(data->mlx);
        // free(data->mlx);
	}
    if (keycode == 65361) // left arrow

    if (keycode == 65362) // up arrow

    if (keycode == 65363) // right arrow

    if (keycode == 65364) // down arrow
	return (0);
}

int handle_close(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	data->win = NULL;
    mlx_destroy_image(data->mlx, data->img);
	return (0);
}

static void	zoom(t_data *f, double zoom)
{
	double	center_r;
	double	center_i;

	center_r = f->min_r - f->max_r;
	center_i = f->max_i - f->min_i;
	f->max_r = f->max_r + (center_r - zoom * center_r) / 2;
	f->min_r = f->max_r + zoom * center_r;
	f->min_i = f->min_i + (center_i - zoom * center_i) / 2;
	f->max_i = f->min_i + zoom * center_i;
}

static void	move(t_data *f, double distance, char direction)
{
	double	center_r;
	double	center_i;

	center_r = f->max_r - f->min_r;
	center_i = f->max_i - f->min_i;
	if (direction == 'R')
	{
		f->min_r += center_r * distance;
		f->max_r += center_r * distance;
	}
	else if (direction == 'L')
	{
		f->min_r -= center_r * distance;
		f->max_r -= center_r * distance;
	}
	else if (direction == 'D')
	{
		f->min_i -= center_i * distance;
		f->max_i -= center_i * distance;
	}
	else if (direction == 'U')
	{
		f->min_i += center_i * distance;
		f->max_i += center_i * distance;
	}
}


int	handle_mouse(int keycode, int x, int y, t_data *mlx)
{
	if (keycode == 4)
	{
		zoom(mlx, 0.5);
		x -= WIDTH / 2;
		y -= HEIGHT / 2;
		if (x < 0)
			move(mlx, (double)x * -1 / WIDTH, 'L');
		else if (x > 0)
			move(mlx, (double)x / WIDTH, 'R');
		if (y < 0)
			move(mlx, (double)y * -1 / HEIGHT, 'U');
		else if (y > 0)
			move (mlx, (double)y / HEIGHT, 'D');
	}
	else if (keycode == 5)
		zoom(mlx, 2);
	else if (keycode == 3)
	{
		if (mlx->fract == 1)
		{
			mlx->jr = mlx->min_r + (double)x * (mlx->max_r - mlx->min_r) / WIDTH;
			mlx->ji = mlx->max_i + (double)y * (mlx->min_i - mlx->max_i) / HEIGHT;
		}
	}
	else
		return (0);
	render(mlx);
	return (0);
}
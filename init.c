#include "fractol.h"

static void scop_init(t_data *data)
{
    if (data->fract == 0 || data->fract == 2)
    {
	    data->min_r = -2.0;
		data->max_r = 1.0;
        data->min_i = 1.5;
		data->max_i = -1.5;
    }
    if (data->fract == 1)
    {
        data->min_r = -2.0;
		data->max_r = 2.0;
		data->min_i = -2.0;
        data->max_i = 2.0;
    }
}

void    data_init(t_data *data)
{
    data->mlx = NULL;
    data->win = NULL;
    data->img = NULL;
    data->img_addr = NULL;
    
    data->endian = 0;
    data->ll = 0;
    data->bpp = 0;

    // data->min_r = -2.0;
    // data->max_r = 1.0;
    // data->min_i = -1.0;
    // data->max_i = 1.0;
    scop_init(data);
    data->sx = 2.0;
    data->rx = 0.5;
    data->fx = 1.0;

    data->zoom = 200;
    data->it_max = 50;
    data->axe = 'r';
    data->step = 0.01;
    data->graph = 0;
}

int    data_set(t_data *data)
{
    data->mlx = mlx_init();
    if (data->mlx == NULL)
    {
        return (ft_error(data));
    }

    data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "fractol");
    if (data->win == NULL)
    {
        free(data->mlx);
        return (ft_error(data));
    }
    data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
    data->img_addr = mlx_get_data_addr(data->img, &data->bpp,
                                             &data->ll, &data->endian);
    return (0);
}
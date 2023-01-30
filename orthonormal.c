#include "fractol.h"

static  void    julia_graph(t_data *data, int x, int y)
{
    int dot;

    dot = 0;
    if ((double)x <= ((WIDTH / 2) + 2) && (double)x >= ((WIDTH / 2) - 2))
        my_mlx_pixel_put(data, x, y, RED);
    if ((double)y <= ((HEIGHT / 2) + 2) && (double)y >= ((WIDTH / 2) - 2))
        my_mlx_pixel_put(data, x, y, RED);

    // if ((double)x <= ((((data->jr - data->min_r) * WIDTH) / (data->max_r - data->min_r)) + 2)
    //     && (double)x >= ((((data->jr - data->min_r) * WIDTH) / (data->max_r - data->min_r) - 2)))
    //             my_mlx_pixel_put(data, x, y, GREEN);

    // if ((double)y <= ((((data->ji - data->max_i) * HEIGHT) / (data->min_i - data->max_i)) + 2)
    //     && (double)y >= ((((data->ji - data->max_i) * HEIGHT) / (data->min_i - data->max_i) - 2)))
    //             my_mlx_pixel_put(data, x, y, GREEN);

    if ((double)x <= ((((data->jr - data->min_r) * WIDTH) / (data->max_r - data->min_r)) + 4)
        && (double)x >= ((((data->jr - data->min_r) * WIDTH) / (data->max_r - data->min_r) - 4)))
                dot = 1;

    if (dot == 1 && ((double)y <= ((((data->ji - data->max_i) * HEIGHT) / (data->min_i - data->max_i)) + 4)
        && (double)y >= ((((data->ji - data->max_i) * HEIGHT) / (data->min_i - data->max_i) - 4))))
                my_mlx_pixel_put(data, x, y, RED);
}

static  void    mandelbrot_graph(t_data *data, int x, int y)
{
    if ((double)x <= (((WIDTH * 2) / 3) + 2) && (double)x >= (((WIDTH * 2) / 3) - 2))
        my_mlx_pixel_put(data, x, y, RED);
    if ((double)y <= ((HEIGHT / 2) + 2) && y >= ((HEIGHT / 2) - 2))
        my_mlx_pixel_put(data, x, y, RED);
}

void    graph_draw(t_data *data)
{
    int x;
    int y;
    double pos_r;
    double pos_i;

    y = -1;
    printf("x = %lf, ", ((data->jr - data->min_r) * WIDTH) / (data->max_r - data->min_r));
    printf("y = %lf\n", ((data->ji - data->max_i) * HEIGHT) / (data->min_i - data->max_i));
    while (++y < HEIGHT)
    {
        x = -1;
        while (++x < WIDTH)
        {
            if (data->fract == 0)
                mandelbrot_graph(data, x, y);
            if (data->fract == 1)
                julia_graph(data, x, y);
        }
    }
}

void    graph_switch(t_data *data)
{
    ft_printf("graph_switch\n");
    if (data->graph == 0) 	        //graph on
	    data->graph = 1;
	else if (data->graph == 1)		//graph off
	 	data->graph = 0;
}
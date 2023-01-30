#include "fractol.h"

int	handle_keypress(int keycode, t_data *data)
{
    // ft_printf("keycode : %d\n", data->step;);
	if (keycode == XK_Escape)
	{
		mlx_destroy_window(data->mlx, data->win);
		data->win = NULL;
        mlx_destroy_image(data->mlx, data->img);
        // mlx_destroy_display(data->mlx);
        // free(data->mlx);
	}
	else if (keycode == 103)
		graph_switch(data);
	// else if (keycode == 103 && data->graph == "off") 	//graph on
	// 	data->graph = "on";
	// else if (keycode == 103 && data->graph == "on")		//graph off
	// 	data->graph = "off";
	switch_julia_configuration(keycode, data);
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

int	handle_mouse(int keycode, int x, int y, t_data *data)
{
	if (keycode == 4)
		zoom_in(data, x, y);
	else if (keycode == 5)
		zoom(data, 2);
	else if (keycode == 1)
		click_configuration(data, x, y);
	else
		return (0);
	render(data);
	return (0);
}
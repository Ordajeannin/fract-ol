#include "fractol.h"

void click_configuration(t_data *data, int x, int y)
{
    if (data->fract == 1)
	{
		data->jr = data->min_r + (double)x * (data->max_r - data->min_r) / WIDTH;
		data->ji = data->max_i + (double)y * (data->min_i - data->max_i) / HEIGHT;
	}
}

static void modify_step(int keycode, t_data *data)
{
	if (keycode == 49)				// 1-> biggest step
		data->step = 0.1;
	else if (keycode == 50)			// 2-> slow down
		data->step = 0.05;
	else if (keycode == 51)			// 3-> slown down
		data->step = 0.01;
	else if (keycode == 52)			// 4-> slow down
		data->step = 0.005;
	else if (keycode == 53)			// 5-> slow down
		data->step = 0.001;
	else if (keycode == 54)			// 6-> slow down
		data->step = 0.0005;
	else if (keycode == 55)			// 7-> slow down
		data->step = 0.0001;
	else if (keycode == 56)			// 8-> slown down
		data->step = 0.00005;
	else if (keycode == 57)		// 9-> lowest step
		data->step = 0.00001;
	else if (keycode == 48)			// 0-> can't be more precise
		data->step = 0.000001;
}

void switch_julia_configuration(int keycode, t_data *data)
{
	ft_printf("keycode : %d\n", keycode);
	if (keycode >= 48 && keycode <= 57)
		modify_step(keycode, data);
	if (keycode == 53)		// 5-> lowest step
		data->step = 0.001;
	if (keycode == 114)		//shift axe to real
		data->axe = 'r';
	if (keycode == 105)		//shift axe to i
		data->axe = 'i';
	if (keycode == 61 && data->axe == 'r' && data->jr <= 2 - data->step)
		data->jr += data->step;
	if (keycode == 61 && data->axe == 'i' && data->ji <= 2 - data->step)
		data->ji += data->step;
	if (keycode == 45 && data->axe == 'r' && data->jr >= -2 + data->step)
		data->jr -= data->step;
	if (keycode == 45 && data->axe == 'i' && data->ji >= -2 +data->step)
		data->ji -= data->step;

	printf ("jr = %lf ji = %lf step = %lf graph = %d\n", data->jr, data->ji, data->step, data->graph);
}
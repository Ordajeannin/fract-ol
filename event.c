#include "test.h"
#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include <X11/keysym.h>
#include <X11/X.h>

//define a color : 0xTTRRGGBB
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF


int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx, data->win);
		data->win = NULL;
	}
	return (0);
}

int handle_close(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	data->win = NULL;
	return (0);
}

int handle_buttonpress(int keycode, int x, int y, t_data *data)
{
	//printf("mouse code : %d\nposition( %d, %d)\n\n", keycode, x, y);
	return (0);
}

int handle_motion(int x, int y, t_data *data)
{
	//printf("position : ( %d, %d)\n", x, y);
	return (0);
}
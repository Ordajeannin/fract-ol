#include "test.h"
#include <stdlib.h>
#include <stdio.h>

#include <X11/X.h>
#include <X11/keysym.h>
#include <mlx.h>

#define WINDOW_WIDTH 1080
#define WINDOW_HEIGHT 720

#define MLX_ERROR 1

# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF


int	main(void)
{
	t_data  display;

    /* initialisation display + window */
	display.mlx = mlx_init();
	if (display.mlx == NULL)
		return (MLX_ERROR);
	display.win = mlx_new_window(display.mlx, WINDOW_WIDTH, WINDOW_HEIGHT,
								"Hello world");
	if (display.win == NULL)
	{
		free(display.win);
		return (MLX_ERROR);
	}

	/* Setup hooks */ 

	display.img.mlx_img = mlx_new_image(display.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);

	display.img.addr = mlx_get_data_addr(display.img.mlx_img, &display.img.bits_per_pixel, 
											&display.img.line_length, &display.img.endian);
	
	mlx_loop_hook(display.mlx, &render_img, &display);
	mlx_hook(display.win, KeyPress, KeyPressMask, &handle_keypress, &display);
    mlx_hook(display.win, DestroyNotify, StructureNotifyMask, &handle_close, &display);
	mlx_hook(display.win, ButtonPress, ButtonPressMask, &handle_buttonpress, &display);
	mlx_hook(display.win, MotionNotify, PointerMotionMask, &handle_motion, &display);

	mlx_loop(display.mlx);


	/* we will exit the loop if there's no window left, and execute this code */
	mlx_destroy_image(display.mlx, display.img.mlx_img);
	mlx_destroy_display(display.mlx);
	free(display.mlx);
}

//display.img.mlx_img = mlx_new_image(display.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);

//(return a char*, wich is an array of pixel])
//mlx_get_data_addr(display.img.mlx_img, display.img.bits_per_pixels, display.img.size_line, 
//		display.img.endian);
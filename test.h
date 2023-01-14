#ifndef TEST_H
#define TEST_H

#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include <X11/keysym.h>
#include <X11/X.h>


//info needed by each img we manipule, the current one AND the buffer one
//mlx_new_image -> address. now, we went to extract info : 
//mlx_get_data_addr(void *img_ptr, int *bits_per_pixel, int *size_line, int *endian);
typedef struct s_img
{
	void *mlx_img; //address mlx_new_image return 
	char *addr;

	int bits_per_pixel;
	int line_length;
	int endian; //order when you read bytes : 2^3 2^2 2^1 2^0 ? -> BE (big first)
				//                            2^0 2^1 2^2 2^3 ? -> LE (little first)
} t_img;


//main struct, mlx + window, stock the image
typedef struct s_data
{
	void *mlx;
	void *win;
	t_img img;
	int cur_img;
} t_data;


//to draw a rectangle.... whououuuuu
typedef struct s_rect
{
	int	x;
	int	y;
	int width;
	int height;
	int color;
}	t_rect;



//graphics
void my_mlx_pixel_put(t_img *data, int x, int y, int color);

int render_win(t_data *data);

int render_img(t_data *data);

int render_rect_win(t_data *data, t_rect rect);

int render_rect_img(t_img *img, t_rect rect);

void render_background(t_data *data, int color);

void render_background_img(t_img *img, int color);

//event
int handle_no_event(void *data);

int handle_input(int keysym, t_data *data);

int handle_keypress(int keysym, t_data *data);

int handle_keyrelease(int keysym, void *data);

int handle_buttonpress(int keycode, int x, int y, t_data *data);

int handle_motion(int x, int y, t_data *data);

int handle_close(t_data *data);


//color
int encode_trgb(int transparency, int red, int green, int blue);

int get_transparency(int trgb);

int get_red(int trgb);

int get_green(int trgb);

int get_blue(int trgb);

int add_shade(double intensity, int color);

int get_complementary(int color);




#endif
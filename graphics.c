#include "test.h"
#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include <X11/keysym.h>
#include <X11/X.h>


#define WINDOW_WIDTH 1080
#define WINDOW_HEIGHT 720


//define a color : 0xTTRRGGBB
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF


//work for Big-Endian only
void my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
    // printf("hey! we're trying to print this colour : %d\n", color);
	char *pixel;
	int index;
	index = (y * img->line_length + x * (img->bits_per_pixel / 8));
	pixel = img->addr + index;
	*(unsigned int*)pixel = color;
}

int render_rect_win(t_data *data, t_rect rect)
{
	int	i;
	int j;

	if (data->win == NULL)
		return (1);
	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			mlx_pixel_put(data->mlx, data->win, j++, i, rect.color);
		++i;
	}
	return (0);
}

int render_rect_img(t_img *img, t_rect rect)
{
	int	i;
	int j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			my_mlx_pixel_put(img, j++, i, rect.color);
		++i;
	}
	return (0);
}

void	render_background_win(t_data *data, int color)
{
	int	i;
	int	j;

	if (data->win == NULL)
		return ;
	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
			mlx_pixel_put(data->mlx, data->win, j++, i, color);
		++i;
	}
}

void	render_background_img(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			my_mlx_pixel_put(img, j++, i, color);
		}
		++i;
	}
}

int	render_win(t_data *data)
{
    render_background_win(data, encode_trgb(166, 66, 21, 51));
	render_rect_win(data, (t_rect){WINDOW_WIDTH - 420, WINDOW_HEIGHT - 420,
			420, 420, encode_trgb(255, 255, 255, 0)});
	render_rect_win(data, (t_rect){420, 420, 420, 420, BLUE});

	return (0);
}

int	render_img(t_data *data)
{
	if (data->win == NULL)
		return (1);
	render_background_img(&data->img, encode_trgb(166, 66, 21, 51));
	render_rect_img(&data->img, (t_rect){WINDOW_WIDTH - 100, WINDOW_HEIGHT - 100,
		100, 100, encode_trgb(255, 255, 255, 0)});
	render_rect_img(&data->img, (t_rect){0, 0, 500, 300, BLUE});

	mlx_put_image_to_window(data->mlx, data->win, data->img.mlx_img, 0, 0);

	return (0);
}

// void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
// {
// 	char    *pixel;
// 	int		i;

// 	i = img->bpp - 8;
//     pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
// 	while (i >= 0)
// 	{
// 		/* big endian, MSB is the leftmost bit (Most Significant Byte) */
// 		if (img->endian != 0)
// 			*pixel++ = (color >> i) & 0xFF;
// 		/* little endian, LSB is the leftmost bit (Less Significant Byte) */
// 		else
// 			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
// 		i -= 8;
// 	}
// }
// -> work for BE && LE


#include "fractol.h"

void	apply_color(t_data *data, int x, int y, double it)
{
	int	color;

	if (data->palette % PALETTE == 3)
		color = encode_trgb(255, it * 255 / IT_MAX, 0, 0);
	if (data->palette % PALETTE == 1)
		color = encode_trgb(255, 0, it * 255 / IT_MAX, 0);
	if (data->palette % PALETTE == 2)
		color = encode_trgb(255, 0, 0, it * 255 / IT_MAX);
	if (data->palette % PALETTE == 4)
		color = encode_trgb(255, it * 5, it * 10, it * 20);
	if (data->palette % PALETTE == 0)
		color = encode_trgb(255, it * 5 * 255 / IT_MAX, it * 10 * 255 / IT_MAX, it * 20 * 255 / IT_MAX);
	if (data->palette % PALETTE == 5)
		color = encode_trgb(255, it * 255 / IT_MAX, it * 255 / IT_MAX, it * 255 / IT_MAX);
	my_mlx_pixel_put(data, x, y, color);
} 
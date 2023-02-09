/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannin <ajeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 20:39:50 by ajeannin          #+#    #+#             */
/*   Updated: 2023/02/09 19:22:05 by ajeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	psychedelic_color(t_data *data, int it)
{
	int	color;

	if (data->palette % PALETTE == 9)
		color = encode_trgb(255, it * 5, it * 10, it * 20);
	if (data->palette % PALETTE == 10)
		color = encode_trgb(255, it * 20, it * 5, it * 10);
	if (data->palette % PALETTE == 11)
		color = encode_trgb(255, it * 10, it * 20, it * 5);
	return (color);
}

static int	basic_color(t_data *data, double it)
{
	int	color;

	if (data->palette % PALETTE == 5)
		color = encode_trgb(255, it * 255 / IT_MAX, 0, 0);
	if (data->palette % PALETTE == 6)
		color = encode_trgb(255, 0, it * 255 / IT_MAX, 0);
	if (data->palette % PALETTE == 7)
		color = encode_trgb(255, 0, 0, it * 255 / IT_MAX);
	if (data->palette % PALETTE == 8)
		color = encode_trgb(255, it * 255 / IT_MAX,
				it * 255 / IT_MAX, it * 255 / IT_MAX);
	return (color);
}

static int	beautiful_color(t_data *data, double it)
{
	int	color;

	if (data->palette % PALETTE == 0)
		color = encode_trgb(255, it * 5 * 255 / IT_MAX,
				it * 10 * 255 / IT_MAX, it * 20 * 255 / IT_MAX);
	if (data->palette % PALETTE == 1)
		color = encode_trgb(255, it * 5 * 255 / IT_MAX,
				0, it * 20 * 255 / IT_MAX);
	if (data->palette % PALETTE == 2)
		color = encode_trgb(255, it * 5 * 255 / IT_MAX,
				it * 10 * 255 / IT_MAX, 0);
	if (data->palette % PALETTE == 3)
		color = encode_trgb(255, it * 20 * 255 / IT_MAX,
				it * 5 * 255 / IT_MAX, it * 10 * 255 / IT_MAX);
	if (data->palette % PALETTE == 4)
		color = encode_trgb(255, it * 10 * 255 / IT_MAX,
				it * 20 * 255 / IT_MAX, it * 5 * 255 / IT_MAX);
	return (color);
}

void	apply_color(t_data *data, int x, int y, double it)
{
	int	color;

	if (data->palette % PALETTE <= 4)
		color = beautiful_color(data, it);
	else if (data->palette % PALETTE <= 8)
		color = basic_color(data, it);
	else if (data->palette % PALETTE <= 11)
		color = psychedelic_color(data, it);
	my_mlx_pixel_put(data, x, y, color);
}

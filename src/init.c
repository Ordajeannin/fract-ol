/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannin <ajeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:45:37 by ajeannin          #+#    #+#             */
/*   Updated: 2023/02/14 17:06:01 by ajeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

//initialize min/max values of the complex plan
static void	scop_init(t_data *data)
{
	if (data->fract == 0)
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
	if (data->fract == 2)
	{
		data->min_r = -2.0;
		data->max_r = -1.5;
		data->min_i = 0.10;
		data->max_i = -0.25;
	}
}

//initialize the data structure
void	data_init(t_data *data)
{
	data->mlx = NULL;
	data->win = NULL;
	data->img = NULL;
	data->img_addr = NULL;
	data->endian = 0;
	data->ll = 0;
	data->bpp = 0;
	scop_init(data);
	data->zoom = 1;
	data->it_max = 50;
	data->axe = 'r';
	data->step = 0.01;
	data->graph = 0;
	data->palette = 0;
	data->pow = 0;
}

//initialize mlx, window, and first image
int	data_set(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
	{
		return (ft_error());
	}
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "fractol");
	if (data->win == NULL)
	{
		free(data->mlx);
		return (ft_error());
	}
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img_addr = mlx_get_data_addr(data->img, &data->bpp,
			&data->ll, &data->endian);
	return (0);
}

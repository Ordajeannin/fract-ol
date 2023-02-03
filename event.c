/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannin <ajeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:45:28 by ajeannin          #+#    #+#             */
/*   Updated: 2023/02/03 19:15:04 by ajeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_keypress(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
	{
		mlx_destroy_window(data->mlx, data->win);
		data->win = NULL;
		mlx_destroy_image(data->mlx, data->img);
	}
	else if (keycode == 103)
		graph_switch(data);
	else if (keycode == 32)
		data->palette++;
	switch_julia_configuration(keycode, data);
	return (0);
}

int	handle_close(t_data *data)
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

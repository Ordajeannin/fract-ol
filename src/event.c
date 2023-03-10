/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannin <ajeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:45:28 by ajeannin          #+#    #+#             */
/*   Updated: 2023/02/14 15:44:20 by ajeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

//shift the view
static void	handle_arrows(int keycode, t_data *data)
{
	if (keycode == 65361)
		move(data, 0.1, 'R');
	else if (keycode == 65362)
		move(data, 0.1, 'D');
	else if (keycode == 65363)
		move(data, 0.1, 'L');
	else if (keycode == 65364)
		move(data, 0.1, 'U');
}

/*
Even if this project is awesome, user may want, one day, to touch some grass.
So they have to escape the program...
Yes, I know, but hold your tears, avoid the leaks
*/
int	handle_close(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	data->win = NULL;
	mlx_destroy_image(data->mlx, data->img);
	return (0);
}

//handle keyboard input, like escape, graph, colors, or even julia configuration
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
	else if (keycode >= 65361 && keycode <= 65364)
		handle_arrows(keycode, data);
	switch_julia_configuration(keycode, data);
	return (0);
}

//handle zoom and julia's click-configuration
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannin <ajeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:45:41 by ajeannin          #+#    #+#             */
/*   Updated: 2023/02/01 18:11:24 by ajeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	click_configuration(t_data *data, int x, int y)
{
	if (data->fract == 1)
	{
		data->jr = get_pos_r(data, (double)x);
		data->ji = get_pos_i(data, (double)y);
	}
}

static void	modify_step(int keycode, t_data *data)
{
	if (keycode == 49)
		data->step = 0.1;
	else if (keycode == 50)
		data->step = 0.05;
	else if (keycode == 51)
		data->step = 0.01;
	else if (keycode == 52)
		data->step = 0.005;
	else if (keycode == 53)
		data->step = 0.001;
	else if (keycode == 54)
		data->step = 0.0005;
	else if (keycode == 55)
		data->step = 0.0001;
	else if (keycode == 56)
		data->step = 0.00005;
	else if (keycode == 57)
		data->step = 0.00001;
	else if (keycode == 48)
		data->step = 0.000001;
}

void	switch_julia_configuration(int keycode, t_data *data)
{
	ft_printf("keycode : %d\n", keycode);
	if (keycode >= 48 && keycode <= 57)
		modify_step(keycode, data);
	if (keycode == 114)
		data->axe = 'r';
	if (keycode == 105)
		data->axe = 'i';
	if (keycode == 61 && data->axe == 'r' && data->jr <= 2 - data->step)
		data->jr += data->step;
	if (keycode == 61 && data->axe == 'i' && data->ji <= 2 - data->step)
		data->ji += data->step;
	if (keycode == 45 && data->axe == 'r' && data->jr >= -2 + data->step)
		data->jr -= data->step;
	if (keycode == 45 && data->axe == 'i' && data->ji >= -2 + data->step)
		data->ji -= data->step;
	printf ("jr = %lf ji = %lf step = %lf graph = %d\n", data->jr, data->ji, data->step, data->graph);
}

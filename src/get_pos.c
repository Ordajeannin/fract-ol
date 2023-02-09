/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannin <ajeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 20:40:46 by ajeannin          #+#    #+#             */
/*   Updated: 2023/02/09 19:22:13 by ajeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double	get_pos_x(t_data *data)
{
	double	x;

	x = (((data->jr - data->min_r) * WIDTH) / (data->max_r - data->min_r));
	return (x);
}

double	get_pos_y(t_data *data)
{
	double	y;

	y = (((data->ji - data->max_i) * HEIGHT) / (data->min_i - data->max_i));
	return (y);
}

double	get_pos_r(t_data *data, double x)
{
	double	pos_r;

	pos_r = data->min_r + x * (data->max_r - data->min_r) / WIDTH;
	return (pos_r);
}

double	get_pos_i(t_data *data, double y)
{
	double	pos_i;

	pos_i = data->max_i + y * (data->min_i - data->max_i) / HEIGHT;
	return (pos_i);
}

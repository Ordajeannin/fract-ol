/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannin <ajeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:46:10 by ajeannin          #+#    #+#             */
/*   Updated: 2023/02/09 19:22:50 by ajeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	zoom(t_data *f, double zoom)
{
	double	center_r;
	double	center_i;

	if (zoom == 0.5)
	{
		f->zoom *= 2;
		ft_printf("zoom factor : %d\n", f->zoom);
	}
	center_r = f->min_r - f->max_r;
	center_i = f->max_i - f->min_i;
	f->max_r = f->max_r + (center_r - zoom * center_r) / 2;
	f->min_r = f->max_r + zoom * center_r;
	f->min_i = f->min_i + (center_i - zoom * center_i) / 2;
	f->max_i = f->min_i + zoom * center_i;
}

void	move(t_data *f, double distance, char direction)
{
	double	center_r;
	double	center_i;

	center_r = f->max_r - f->min_r;
	center_i = f->max_i - f->min_i;
	if (direction == 'R')
	{
		f->min_r += center_r * distance;
		f->max_r += center_r * distance;
	}
	else if (direction == 'L')
	{
		f->min_r -= center_r * distance;
		f->max_r -= center_r * distance;
	}
	else if (direction == 'D')
	{
		f->min_i -= center_i * distance;
		f->max_i -= center_i * distance;
	}
	else if (direction == 'U')
	{
		f->min_i += center_i * distance;
		f->max_i += center_i * distance;
	}
}

void	zoom_in(t_data *data, int x, int y)
{
	zoom(data, 0.5);
	x -= WIDTH / 2;
	y -= HEIGHT / 2;
	data->graph = 2;
	if (x < 0)
		move(data, (double)x * -1 / WIDTH, 'L');
	else if (x > 0)
		move(data, (double)x / WIDTH, 'R');
	if (y < 0)
		move(data, (double)y * -1 / HEIGHT, 'U');
	else if (y > 0)
		move (data, (double)y / HEIGHT, 'D');
}

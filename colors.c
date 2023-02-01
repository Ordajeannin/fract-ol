/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannin <ajeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:45:24 by ajeannin          #+#    #+#             */
/*   Updated: 2023/02/01 17:37:33 by ajeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	encode_trgb(int transparency, int red, int green, int blue)
{
	return (transparency << 24 | red << 16 | green << 8 | blue);
}

int	add_shade(double intensity, int color)
{
	int	transparency;
	int	r;
	int	g;
	int	b;

	transparency = intensity * 255;
	r = get_red(color);
	g = get_green(color);
	b = get_blue(color);
	return (transparency << 24 | r << 16 | g << 8 | b);
}

int	get_complementary(int color)
{
	int	t;
	int	r;
	int	g;
	int	b;

	t = get_transparency(color);
	r = get_red(color);
	g = get_green(color);
	b = get_blue(color);
	r = 255 - r;
	g = 255 - g;
	b = 255 - b;
	return (t << 24 | r << 16 | g << 8 | b);
}

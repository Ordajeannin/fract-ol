/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannin <ajeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:45:14 by ajeannin          #+#    #+#             */
/*   Updated: 2023/02/01 16:48:36 by ajeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_transparency(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	get_red(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_green(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_blue(int trgb)
{
	return (trgb & 0xFF);
}

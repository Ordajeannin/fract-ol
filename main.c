/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannin <ajeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:45:51 by ajeannin          #+#    #+#             */
/*   Updated: 2023/02/08 20:41:38 by ajeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac >= 2 && which_fract(&data, ac, av) == 0)
	{
		data_init(&data);
		data_set(&data);
		mlx_loop_hook(data.mlx, &render, &data);
		mlx_hook(data.win, KeyPress, KeyPressMask,
			&handle_keypress, &data);
		mlx_hook(data.win, DestroyNotify, StructureNotifyMask,
			&handle_close, &data);
		mlx_hook(data.win, ButtonPress, ButtonPressMask,
			&handle_mouse, &data);
		mlx_loop(data.mlx);
		mlx_destroy_display(data.mlx);
		free(data.mlx);
	}
	else
		ft_error(&data);
	return (0);
}

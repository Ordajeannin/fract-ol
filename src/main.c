/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannin <ajeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:45:51 by ajeannin          #+#    #+#             */
/*   Updated: 2023/02/14 14:46:43 by ajeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
main function's goal is to initialize data structure, handle the loop, and deal
with events. In fact... she don't do that, she just call slave's functions.
But here we can see the code's structure
*/
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
	else if (ac < 2)
		ft_error();
	return (0);
}

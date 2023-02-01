/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannin <ajeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:46:03 by ajeannin          #+#    #+#             */
/*   Updated: 2023/02/01 21:01:43 by ajeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	skip_space_sign(char *str, int *is_neg)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			*is_neg *= -1;
		i++;
	}
	return (i);
}

static double	ft_atod(char *nbr)
{
	int		i;
	double	nb;
	int		is_neg;
	double	div;

	nb = 0;
	div = 0.1;
	is_neg = 1;
	i = skip_space_sign(nbr, &is_neg);
	while (nbr[i] && ft_isdigit(nbr[i]) && nbr[i] != '.')
	{
		nb = (nb * 10.0) + (nbr[i] - '0');
		i++;
	}
	if (nbr[i] == '.')
		i++;
	while (nbr[i] && ft_isdigit(nbr[i]))
	{
		nb = nb + ((nbr[i] - '0') * div);
		div *= 0.1;
		i++;
	}
	if (nbr[i] && !ft_isdigit(nbr[i]))
		return (-42);
	return (nb * is_neg);
}

static void	set_julia(t_data *data, int ac, char **av)
{
	if (ac == 2)
	{
		data->jr = 0.075347;
		data->ji = -0.652546;
	}
	else
	{
		data->jr = ft_atod(av[2]);
		data->ji = ft_atod(av[3]);
	}
	if (data->jr >= 2 || data->ji >= 2)
		ft_error(data);
	if (data->jr <= 2 || data->ji <= 2)
		ft_error(data);
}

int	which_fract(t_data *data, int ac, char **av)
{
	if (ft_strncmp(av[1], "mandelbrot", 11) == 0 && ac == 2)
	{
		data->fract = 0;
	}
	else if (ft_strncmp(av[1], "julia", 6) == 0 && (ac == 2 || ac == 4))
	{
		data->fract = 1;
		set_julia(data, ac, av);
	}
	else if (ft_strncmp(av[1], "rect", 5) == 0 && ac == 2)
	{
		data->fract = 2;
	}
	else
		return (ft_error(data));
	return (0);
}

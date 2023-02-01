/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannin <ajeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:46:03 by ajeannin          #+#    #+#             */
/*   Updated: 2023/02/01 18:57:27 by ajeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	atod_utils(t_data *data, char *nbr, int *is_neg, int *i)
{
	int	tmp;
	int	dot_count;

	tmp = ft_strlen(nbr);
	dot_count = 0;
	if (nbr[*i] == '-')
	{
		*is_neg = -1;
		i++;
	}
	else
		*is_neg = 1;
	if (nbr[*i] == '.' || !ft_isdigit(nbr[*i]))
		return (ft_error(data) + 1);
	while (nbr[*i] && dot_count <= 1 && (ft_isdigit(nbr[*i]) || nbr[*i] == '.'))
	{
		if (nbr[*i] == '.')
			dot_count += 1;
		i++;
	}
	if (*i != tmp || dot_count > 1)
		return (ft_error(data) + 1);
	*i = 0;
	return (0);
}

static double	ft_atod(t_data *data, char *nbr)
{
	int		i;
	int		is_neg;
	double	nb;
	double	div;

	i = 0;
	is_neg = 0;
	nb = 0;
	div = 10;
	if (atod_utils(data, nbr, &is_neg, &i) == 1)
		return (-69);
	while (nbr[i] && nbr[i] != '.')
	{
		nb = (nb * 10) + (nbr[i] - '0');
		i++;
	}
	if (nbr[i] == '.')
		i++;
	while (nbr[i])
	{
		nb = nb + ((nbr[i] - '0') / div);
		div *= 10;
		i++;
	}
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
		data->jr = ft_atod(data, av[2]);
		data->ji = ft_atod(data, av[3]);
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

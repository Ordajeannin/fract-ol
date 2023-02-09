/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannin <ajeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:45:33 by ajeannin          #+#    #+#             */
/*   Updated: 2023/02/09 22:00:46 by ajeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# undef _GLIBCXX_DEBUG
# pragma GCC optimize("Ofast,inline")
# pragma GCC target("bmi,bmi2,lzcnt,popcnt")
# pragma GCC target("movbe")
# pragma GCC target("aes,pclmul,rdrnd")
# pragma GCC target("avx,avx2,f16c,fma,sse3,ssse3,sse4.1,sse4.2")

# include "../libft/includes/libft.h"
# include "../minilibx/mlx.h"
# include <stdlib.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <math.h>

# ifndef IT_MAX
#  define IT_MAX 60
# endif
# define WIDTH 1080
# define HEIGHT 1080
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF
# define PALETTE 12

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*img_addr;
	int		endian;
	int		ll;
	int		bpp;
	double	min_r;
	double	max_r;
	double	min_i;
	double	max_i;
	double	ji;
	double	jr;
	int		zoom;
	int		color;
	int		it;
	int		it_max;
	int		fract;
	int		x;
	int		y;
	int		**color_set;
	char	axe;
	double	step;
	int		graph;
	int		palette;

}	t_data;

typedef struct s_complex
{
	double	r;
	double	i;
}	t_complex;

void	click_configuration(t_data *data, int x, int y);
void	switch_julia_configuration(int keycode, t_data *data);
int		get_blue(int trgb);
int		get_green(int trgb);
int		get_red(int trgb);
int		get_transparency(int trgb);
int		get_complementary(int color);
int		add_shade(double intensity, int color);
int		encode_trgb(int transparency, int red, int green, int blue);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	mandelbrot(t_data *data);
void	julia(t_data *data);
void	data_init(t_data *data);
int		data_set(t_data *data);
int		ft_error(void);
int		handle_keypress(int keycode, t_data *data);
int		handle_close(t_data *data);
int		handle_mouse(int keycode, int x, int y, t_data *data);
int		render(t_data *data);
int		which_fract(t_data *data, int ac, char **av);
void	zoom(t_data *f, double zoom);
void	move(t_data *f, double distance, char direction);
void	zoom_in(t_data *data, int x, int y);
void	graph_switch(t_data *data);
void	graph_draw(t_data *data);
double	get_pos_r(t_data *data, double x);
double	get_pos_i(t_data *data, double y);
double	get_pos_x(t_data *data);
double	get_pos_y(t_data *data);
void	apply_color(t_data *data, int x, int y, double it);
double	ft_abs(t_complex z);
void	burningship(t_data *data);

#endif
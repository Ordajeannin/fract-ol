# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajeannin <ajeannin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/01 16:45:54 by ajeannin          #+#    #+#              #
#    Updated: 2023/02/03 20:28:13 by ajeannin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fractol

SRC			=	main.c event.c init.c utils.c parsing.c mandelbrot.c colors.c colors2.c julia.c julia_config.c zoom.c orthonormal.c get_pos.c colors3.c burning_ship.c

INCLUDES	=	fractol.h

MLX			=	-I minilibx -L./minilibx -lmlx -lXext -lX11 -lm

LIBFT		=	-Llibft -lft

CC			=	gcc

CCFLAGS		=	#-Wall -Werror -Wextra

$(NAME):
		$(CC) $(CCFLAGS) $(SRC) $(MLX) $(LIBFT) -g
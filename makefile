# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajeannin <ajeannin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/01 16:45:54 by ajeannin          #+#    #+#              #
#    Updated: 2023/02/14 18:09:18 by ajeannin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fractol

SRC_DIR		=	src/

SRC_FILES	=	main.c event.c init.c utils.c parsing.c mandelbrot.c colors.c colors2.c colors3.c julia.c julia_config.c zoom.c orthonormal.c get_pos.c burning_ship.c

SRC			=	$(addprefix $(SRC_DIR), $(SRC_FILES))

INCLUDES	=	fractol.h

MLX			=	-I minilibx -L./minilibx -lmlx -lXext -lX11 -lm

LIBFT		=	-Llibft -lft

CC			=	gcc

CCFLAGS		=	-Wall -Werror -Wextra -flto -Ofast

IT_MAX		=	1000

POW			=	3


$(NAME):
		$(CC) $(CCFLAGS) $(SRC) $(MLX) $(LIBFT) -D IT_MAX=$(IT_MAX) -D POW=$(POW) -g -o $(NAME)

all:	$(NAME)

clean:
	make clean -C libft/

fclean: clean
	rm $(NAME)
	
norme:
	norminette $(SRC) libft includes

re: fclean all

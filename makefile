# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajeannin <ajeannin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/01 16:45:54 by ajeannin          #+#    #+#              #
#    Updated: 2023/02/08 20:50:58 by ajeannin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fractol

SRC			=	main.c event.c init.c utils.c parsing.c mandelbrot.c colors.c colors2.c colors3.c julia.c julia_config.c zoom.c orthonormal.c get_pos.c burning_ship.c

INCLUDES	=	fractol.h

MLX			=	-I minilibx -L./minilibx -lmlx -lXext -lX11 -lm

LIBFT		=	-Llibft -lft

CC			=	gcc

CCFLAGS		=	#-Wall -Werror -Wextra

$(NAME):
		$(CC) $(CCFLAGS) $(SRC) $(MLX) $(LIBFT) -g -o $(NAME)

all:	$(NAME)

clean:
	make clean -C libft/
	rm $(NAME)

fclean: clean

norme:
	norminette $(SRC) libft

re: fclean all

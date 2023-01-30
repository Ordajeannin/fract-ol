NAME		=	fractol

SRC			=	main.c event.c init.c utils.c parsing.c mandelbrot.c colors.c colors2.c julia.c julia_config.c zoom.c orthonormal.c

INCLUDES	=	fractol.h

MLX			=	-I minilibx -L./minilibx -lmlx -lXext -lX11 -lm

LIBFT		=	-Llibft -lft

CC			=	gcc

CCFLAGS		=	#-Wall -Werror -Wextra

$(NAME):
		$(CC) $(CCFLAGS) $(SRC) $(MLX) $(LIBFT) -g
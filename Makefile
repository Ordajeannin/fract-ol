NAME		=	fractol

SRC			=	main.c graphics.c event.c color.c

INCLUDES	=	test.h

MLX			=	-I minilibx-linux -L./minilibx-linux -lmlx -lXext -lX11 -lm

CC			=	gcc

CCFLAGS		=	#-Wall -Werror -Wextra

$(NAME):
		$(CC) $(CCFLAGS) $(SRC) $(INCLUDES) $(MLX)
		./a.out
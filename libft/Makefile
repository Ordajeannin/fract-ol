# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajeannin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 16:27:15 by ajeannin          #+#    #+#              #
#    Updated: 2022/11/07 18:35:45 by ajeannin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

########## VARIABLES ##########

NAME 			= libft.a 
INCLUDES		= includes
SRC_DIR			= src/
OBJ_DIR			= obj/
CC			= gcc
CFLAGS 			= -Werror -Wextra -Wall -I


########### SOURCES ###########

SRC_FILES 		= ft_atoi			\
			ft_bzero			\
			ft_calloc			\
			get_next_line_bonus		\
			get_next_line_utils_bonus	\
			ft_isalnum			\
			ft_isalpha			\
			ft_isascii			\
			ft_isdigit			\
			ft_isprint			\
			ft_itoa				\
			ft_memchr			\
			ft_memcmp			\
			ft_memcpy			\
			ft_memmove			\
			ft_memset			\
			ft_printf			\
			ft_print_hexa			\
			ft_print_percent		\
			ft_print_ptr			\
			ft_print_str_nbr		\
			ft_print_unsigned		\
			ft_putchar_fd			\
			ft_putendl_fd			\
			ft_putnbr_fd			\
			ft_putstr_fd			\
			ft_split			\
			ft_strchr			\
			ft_strdup			\
			ft_striteri			\
			ft_strjoin			\
			ft_strlcat			\
			ft_strlcpy			\
			ft_strlen			\
			ft_strmapi			\
			ft_strncmp			\
			ft_strnstr			\
			ft_strrchr			\
			ft_strtrim			\
			ft_substr			\
			ft_tolower			\
			ft_toupper			\
			ft_lstnew			\
			ft_lstadd_front			\
			ft_lstsize			\
			ft_lstlast			\
			ft_lstadd_back			\
			ft_lstdelone			\
			ft_lstclear			\
			ft_lstiter			\
			ft_lstmap

SRC			= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ			= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
OBJF			= .cache_exists

############ RULES ############

all 			: $(NAME)

$(NAME) 		: $(OBJ)
				ar -crs $(NAME) $(OBJ)
				ctags -R .

$(OBJ_DIR)%.o 		: $(SRC_DIR)%.c | $(OBJF)
				gcc $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJF)			:
				mkdir -p $(OBJ_DIR)

clean 			: 
				rm -rf $(OBJ_DIR)

fclean 			: clean
				rm -rf $(NAME)

re			: fclean all

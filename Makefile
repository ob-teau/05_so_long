# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acoinus <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/27 14:34:25 by acoinus           #+#    #+#              #
#    Updated: 2021/12/09 18:55:40 by acoinus          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long

LIB			= -L./libft -lft -L./minilibx_linux -lmlx -lXext -lX11

SRC			= ft_errors.c\
			  main.c\
			  so_long.c\
			  ft_line_nb.c\
			  ft_map_filler.c\
			  ft_check_c.c\
			  ft_map_checker.c\
			  ft_graphical.c\
			  ft_graphical2.c\
			  ft_close.c\

OBJ			= $(SRC:.c=.o)

CC			= clang

FLAGS		= -Wall -Wextra -Werror

FS			= -fsanitize=address -g3

RM			= rm -f

all		: LIBFT $(NAME)

LIBFT	:
				make -C libft

$(NAME)	: $(OBJ)
				make -C minilibx_linux
				$(CC) $(FLAGS) -o $(NAME) $(SRC) $(LIB)

%.o	:		%.c
				$(CC) $(FLAGS) -o $@ -c $<

norme	:
				norminette $(SRC)
				norminette so_long.h
				make -C libft norme

clean	:
				$(RM) $(OBJ)

fclean 	:	clean
				$(RM) $(NAME)
				make -C libft fclean
				make -C minilibx_linux clean

s		:	$(OBJ)
				make -C libft
				make -C minilibx_linux
				$(CC) $(FLAGS) $(FS) -o $(NAME) $(SRC) $(LIB)

sre		:	fclean s

re		: 	fclean all

.PHONY	: all norme clean fclean re

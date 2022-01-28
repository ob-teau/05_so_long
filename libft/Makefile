# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acoinus <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/01 14:00:16 by acoinus           #+#    #+#              #
#    Updated: 2021/12/09 18:37:38 by acoinus          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRC		= ft_putchar_fd.c\
		  ft_putstr_fd.c\
		  ft_strchr.c\
		  ft_strdup.c\
		  ft_strjoin_strn.c\
		  ft_strlen.c\
		  get_next_line.c\
		  ft_putnbr_fd.c\

OBJ		= $(SRC:.c=.o)

CC		= clang

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

.c.o :
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME) : 	$(OBJ)
				ar rcs $(NAME) $(OBJ)

norme :
			norminette .


all :		$(NAME)

clean :
				$(RM) $(OBJ)

fclean : clean
				$(RM) $(NAME)

re :			fclean all

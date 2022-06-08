# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alex <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/21 22:59:45 by alex              #+#    #+#              #
#    Updated: 2020/06/02 20:38:27 by alex             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
CC		= gcc
CFLAGS		= -Wall -Wextra -Werror
CPPFLAGS	= -I$(DEP_DIR)

DEP_DIR		= includes/
SRC_DIR		= srcs/
DEPS		= ft.h

SRC		= srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c \
			srcs/ft_strlen.c srcs/ft_strcmp.c
OBJ		= $(SRC:.c=.o)
RM		= rm -f

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcsv $(NAME) $(OBJ)

%.o: $(SRC_DIR)%.c $(DEP_DIR)$(DEPS)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $(SRC)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

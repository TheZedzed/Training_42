# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alex <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/02 20:24:22 by alex              #+#    #+#              #
#    Updated: 2020/07/11 18:13:46 by alex             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= ft_cat

DEP_DIR		:= includes/
SRCS_DIR	:= srcs/

SRC		:= srcs/ft_cat_stream.c srcs/ft_strcmp.c srcs/ft_putstr.c \
			srcs/main.c srcs/ft_puterror.c
OBJ		:= $(SRC:.c=.o)

CC		:= gcc
CFLAGS		+= -Wall -Wextra -Werror
CPPFLAGS	:= -I$(DEP_DIR)
RM		:= rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(SRCS_DIR)%.o: $(SRCS_DIR)%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.Phony: re

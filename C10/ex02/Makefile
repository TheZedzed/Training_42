# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alex <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/02 20:24:22 by alex              #+#    #+#              #
#    Updated: 2020/07/05 19:24:34 by alex             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= ft_tail

DEP_DIR		:= includes/
SRCS_DIR	:= srcs/

SRC		:= srcs/main.c srcs/ft_atoi.c srcs/ft_str_isdigit.c \
			srcs/ft_isdigit.c srcs/ft_isspace.c srcs/ft_strcmp.c \
			srcs/ft_isoperator.c srcs/ft_tail_stdin.c \
			srcs/ft_error_arg.c srcs/ft_putstr.c srcs/ft_realloc.c \
			srcs/ft_memcpy.c
OBJ		:= $(SRC:.c=.o)

CC		:= gcc
CFLAGS		+= -Wall -Wextra -Werror -g
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

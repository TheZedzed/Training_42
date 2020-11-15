# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alex <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/15 19:18:25 by alex              #+#    #+#              #
#    Updated: 2020/07/15 22:19:37 by alex             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= do_op

DEP_DIR		:= includes/
SRCS_DIR	:= srcs/

SRCS		:= srcs/chosen_func.c srcs/ft_atoi.c srcs/val_error.c \
			srcs/ft_subs.c srcs/ft_add.c srcs/ft_div.c \
			srcs/ft_multi.c srcs/ft_putnbr.c srcs/ft_mod.c \
			srcs/ft_putstr.c srcs/do_op.c srcs/ft_putchar.c \
			srcs/main.c
OBJ		:= $(SRCS:.c=.o)

CC		:= gcc
CFLAGS		:= -Wall -Wextra -Werror
CPPFLAGS	:= -I$(DEP_DIR)
RM		:= rm -f

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $@ $^

$(SRCS_DIR)%.o: $(SRCS_DIR)%.c
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.Phony: re all

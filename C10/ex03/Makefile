# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alex <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/02 20:24:22 by alex              #+#    #+#              #
#    Updated: 2020/07/15 15:41:51 by alex             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= ft_hexdump

DEP_DIR		:= includes/
SRCS_DIR	:= srcs/

SRC		:= srcs/main.c srcs/opt_error.c srcs/check_num.c srcs/error.c \
			srcs/check_option.c srcs/ft_strlen.c srcs/ft_strncmp.c \
			srcs/head_arg.c srcs/nb_files.c srcs/set_command.c \
			srcs/simple_itoa.c srcs/ft_putstr.c srcs/tail_stream.c
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

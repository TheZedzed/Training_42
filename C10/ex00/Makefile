# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alex <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/26 18:25:19 by alex              #+#    #+#              #
#    Updated: 2020/05/31 18:43:52 by alex             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L$(LIB_DIR)
LIB_DIR = lib/
SRC_DIR = srcs/
DEP_DIR = includes/
SRC = $(SRC_DIR)ft_display_file.c
OBJ = $(SRC:.c=.o)
DEPS = ft.h
LDLIBS = -lft
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

:%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

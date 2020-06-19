# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alex <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/02 20:24:22 by alex              #+#    #+#              #
#    Updated: 2020/06/16 20:10:33 by alex             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBRARY		:= libft.a
NAME		:= ft_display_file

DEP_DIR		:= includes/
LIB_DIR		:= lib/
SRCS_DIR	:= srcs/
OBJS_DIR	:= objs/

SRC		:= $(wildcard $(SRCS_DIR)*.c)
OBJS		:= $(SRC:$(SRCS_DIR)%.c=$(OBJS_DIR)%.o)
SOURCES		:= $(wildcard *.c)
OBJECTS		:= $(SOURCES:%.c=%.o)

CC		:= gcc
CFLAGS		+= -Wall -Wextra -Werror
CPPFLAGS	:= -I$(DEP_DIR)
LDFLAGS		:= -L$(LIB_DIR)
LDLIBS		:= -lft
AR		:= ar
ARFLAGS		:= -rcsv
RM		:= rm -rf

all: dobj
	$(MAKE) $(LIBRARY)
	$(MAKE) $(NAME)

dobj:
	mkdir $(OBJS_DIR)

NAME: $(OBJECTS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -c $^ -o $@ $(LDLIBS)

LIBRARY: $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS_DIR)
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(LIBRARY)
	$(RM) $(NAME)

re: fclean all

.Phony: re

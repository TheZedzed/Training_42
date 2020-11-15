CC = gcc
CFLAGS = -Wall -Wextra -Werror
HEADER = ./include
TARGET = rush-02
SRC = ./src/exception_chk.c \
	./src/invert_to_word_sub.c \
	./src/invert_to_word.c \
	./src/read_dict.c \
	./src/split_dict.c \
	./src/split_num.c \
	./src/main.c \
	./src/print_error.c \
	./src/ft_free.c \
	./src/ft_func.c
OBJ = ${SRC:.c=.o}

.PHONY:all clean fclean re
all: ${TARGET}

.c.o :
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I $(HEADER)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

clean:
	rm $(OBJ)

fclean: clean
	rm -f $(TARGET)

re: fclean all
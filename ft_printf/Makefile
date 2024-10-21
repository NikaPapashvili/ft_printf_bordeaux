NAME = libftprintf.a

CC = gcc
CFLAGS += -Wall -Wextra -Werror

SRC  = $(wildcard src/*.c) $(wildcard management/*.c) $(wildcard utils/*.c)
OBJ  = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(NAME)

clean:
	rm -f src/*.o
	rm -f utils/*.o
	rm -f management/*.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

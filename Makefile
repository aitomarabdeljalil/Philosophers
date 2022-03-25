NAME	:= philosophers
CC		:= gcc
CFLAGES	:= -Wall -Wextra -Werror -pthread
SRC		:= main.c
OBJ		:= $(patsubst %.c, %.o, $(SRC))

.PHONY: all clean fclean re

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean:
	rm -rf $(OBJ) $(NAME)

re:
	fclean all

$(NAME): $(SRC)
	$(CC) $(CFLAGS) -o $(NAME) $(SRC)
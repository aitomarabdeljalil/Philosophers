NAME	:= philosophers
CC		:= gcc
CFLAGES	:= -Wall -Wextra -Werror -pthread
SRC		:= main.c ft_atoi.c ft_isdigit.c
OBJ		:= $(patsubst %.c, %.o, $(SRC))

.PHONY: all clean fclean re

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean:
	rm -rf $(OBJ) $(NAME)

re: fclean all

$(NAME): $(SRC) philo.h
	$(CC) $(CFLAGS) -o $(NAME) $(SRC)
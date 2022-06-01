NAME	:= philo_bonus
CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror -pthread
SRC		:= ft_atoi.c ft_isdigit.c info.c main.c philosopher.c philo_utils.c tools.c
OBJ		:= $(patsubst %.c, %.o, $(SRC))

.PHONY: all clean fclean re

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean:
	rm -rf $(OBJ) $(NAME)

re: fclean all

$(NAME): $(SRC) philo_bonus.h
	$(CC) $(CFLAGS) -o $(NAME) $(SRC)
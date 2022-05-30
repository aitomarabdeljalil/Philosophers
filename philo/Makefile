NAME	:= philo
CC		:= gcc
CFLAGS	:= -I . -Wall -Wextra -Werror -pthread -g
SRC		:= ft_atoi.c ft_isdigit.c initialize.c isdead.c main.c philo_life.c time_func.c activity.c

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
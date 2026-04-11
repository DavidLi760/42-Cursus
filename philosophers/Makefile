NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

SRC =	main.c \
		thread.c \
		init.c \
		utils.c

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re:	fclean all
	rm -rf $(OBJ)

.PHONY: all clean fclean re


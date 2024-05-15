CC		= gcc
NAME		= ft_display_file
SRCS		= ft_display_file.c
OBJ		= $(SRCS:.c=.o)
FLAGS		= -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):
	$(CC) -c $(FLAGS) $(SRCS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

.PHONY: clean all fclean

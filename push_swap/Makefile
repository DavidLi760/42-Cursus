CC	= gcc
FLAGS	= -Wall -Werror -Wextra -g3
NAME	= push_swap

SRC		= main.c \
		ft_check_arg.c \
		ft_check_arg_utils.c \
		stack.c \
		swap.c \
		push.c \
		rotate.c \
		reverse_rotate.c \
		sort.c \
		algo.c \
		finder.c \
		get_cost_a.c \
		get_cost_b.c \
		utils.c \
		ft_split.c

OBJ		= $(SRC:.c=.o)

all: $(NAME) 

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

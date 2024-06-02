NAME = push_swap

SRCS = 	main.c\
		input_check.c\
		input_check_utils.c\
		initialization.c\
		stack.c\
		swap.c\
		push.c\
		rotate.c\
		reverse_rotate.c\
		sort_tiny.c\
		sort.c\
		position.c\
		cost.c\
		do_move.c\
		utils.c\

OBJS = ${SRCS:.c=.o}

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all: ${NAME}

$(NAME): ${OBJS}
	${CC} ${CFLAGS} -I push_swap.h ${OBJS} -o $(NAME)

clean:
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${NAME}

re:	fclean all

.PHONY: all clean fclean re

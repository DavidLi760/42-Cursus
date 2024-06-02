NAME = push_swap

SRCS = 	src/push_swap.c\
		src/ft_strdup.c\
		src/ft_atoi.c\
		src/ft_strlen.c\
		src/ft_split.c\
		src/quick_sort.c\
		src/medianne.c\
		utils/get_instructions.c\
		utils/list_utils.c\
		utils/push_instructions.c\
		utils/reverse_rotate_instructions.c\
		utils/rotate_instructions.c\
		utils/swap_instructions.c\
		algo/algo_large.c\
		algo/algo_utils.c\
		algo/small_sort.c

INCLUDES = push_swap.h

OBJS = ${SRCS:.c=.o}

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g3

all: ${NAME}

$(NAME): ${OBJS}
	${CC} ${CFLAGS} -I ${INCLUDES} ${OBJS} -o $(NAME)

clean:
	rm -rf ${OBJS}

fclean:
	rm -rf ${NAME}
	rm -rf ${OBJS}

re:	fclean all

.PHONY: all bonus clean fclean re

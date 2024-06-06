SRCS	=		ft_printf.c \
			ft_printmem.c \
			ft_putchar.c \
			ft_puthex_lower.c \
			ft_puthex_upper.c \
			ft_putnbr.c \
			ft_putstr.c \
			ft_putunsigned.c

OBJS	= ${SRCS:.c=.o}

NAME	= libftprintf.a

CC	= gcc

FLAGS	= -Wall -Wextra -Werror

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
		ar -rcs ${NAME} ${OBJS}

all:	${NAME}

clean:
		rm -f ${OBJS}
fclean: clean
		rm -f ${NAME}
re:	fclean all

.PHONY: all clean fclean re

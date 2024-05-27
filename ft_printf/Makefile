SRCS	=	ft_printf.c \
		ft_putadress.c \
		ft_putchar.c \
		ft_puthexa_lower.c \
		ft_puthexa_upper.c \
		ft_putnbr.c \
		ft_putstr.c \
		ft_putunbr.c \
		ft_strlen.c

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

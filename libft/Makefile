SRCS =	ft_atoi.c \
		ft_isalpha.c \
		ft_itoa.c \
		ft_memcpy.c \
		ft_putendl_fd.c \
		ft_strchr.c \
		ft_strlcpy.c \
		ft_strnstr.c \
		ft_tolower.c \
		ft_bzero.c \
		ft_isascii.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_putnbr_fd.c \
		ft_strdup.c \
		ft_strlen.c \
		ft_strrchr.c \
		ft_toupper.c \

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: ${NAME}

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): $(OBJS)
			ar -rcs $(NAME) $(OBJS)

clean:
			${RM} ${OBJS} ${OBJSBONUS}

fclean: clean
			${RM} ${NAME}

re: fclean all

.PHONY:		bonus all clean fclean re

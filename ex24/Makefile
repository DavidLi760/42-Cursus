NAME		= libft.a
SRCS		= 	srcs/ft_putchar.c\
			srcs/ft_putstr.c\
			srcs/ft_strcmp.c\
			srcs/ft_strlen.c\
			srcs/ft_swap.c
OBJS		= $(SRCS:.c=.o)
INCLUDES	= includes
FLAGS 		= -Werror -Wextra -Wall
CC 		= gcc

all:	$(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

.c.o:
	$(CC) $(FLAGS) -I $(INCLUDES) -c $< -o $(@:.c=.o)

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re

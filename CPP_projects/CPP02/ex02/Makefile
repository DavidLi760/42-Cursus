NAME	=	Talking_FPN
CC		=	c++
CFLAGS	=	-Wall -Wextra -Werror -g3
SRCS	=	main.cpp\
			Fixed.cpp
OBJS	=	$(SRCS:.cpp=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
	rm -rf $(OBJS)

.PHONY : re fclean clean all

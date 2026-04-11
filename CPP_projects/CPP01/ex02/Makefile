NAME	= HI_THIS_IS_BRAIN
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98 -g3
SRCS	= main.cpp
OBJS	= $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all
	rm -rf $(OBJS)

.PHONY : fclean clean re all

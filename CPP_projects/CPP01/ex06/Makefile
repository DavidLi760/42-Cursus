NAME	= harlFilter
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98 -g3
SRCS	= 	main.cpp\
			Harl.cpp
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

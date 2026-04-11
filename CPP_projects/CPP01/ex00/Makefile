NAME	= BraiiiiiiinnnzzzZ
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98 -g3
SRCS	= main.cpp\
		  Zombie.cpp\
		  newZombie.cpp\
		  randomChump.cpp
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

.PHONY : re fclean clean all

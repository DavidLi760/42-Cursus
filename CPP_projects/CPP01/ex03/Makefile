NAME	= Violence
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -g3
SRCS	=	main.cpp\
			HumanA.cpp\
			HumanB.cpp\
			Weapon.cpp
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

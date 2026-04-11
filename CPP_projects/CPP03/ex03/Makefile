NAME	= DiamondTrap
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++ -Wshadow -Wno-shadow
SRCS	= main.cpp\
		  ClapTrap.cpp\
		  ScavTrap.cpp\
		  FragTrap.cpp\
		  DiamondTrap.cpp
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

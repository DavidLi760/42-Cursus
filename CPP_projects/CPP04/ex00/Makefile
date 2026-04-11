NAME	= Poly
CC	= c++
CFLAGS	= -Wall -Wextra -Werror
SRC	= main.cpp\
	  Animal.cpp\
	  Dog.cpp\
	  Cat.cpp
OBJ	= $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all
	rm -rf $(OBJ)

.PHONY : fclean clean re all

NAME	= PhoneBook
CC		= c++
CFLAGS	= -Wall -Wextra -Werror
SRCS	=	PhoneBook.cpp\
			Contact.cpp\
			main.cpp
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

.PHONY : re all fclean clean

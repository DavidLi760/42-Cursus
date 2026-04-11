NAME = EasyFind
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -g3 -std=c++98
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all
	rm -rf $(OBJS)

.PHONY : fclean clean re all
NAME = btc
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS =	main.cpp\
	BitcoinExchange.cpp
OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : fclean re clean all

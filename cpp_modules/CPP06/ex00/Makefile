NAME=convert

CXX=clang++
CXXFLAGS=-Wall -Werror -Wextra -std=c++98
SRCS=Converter.cpp main.cpp
OBJS=$(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

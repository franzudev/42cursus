NAME = replace

CXX = clang++

CXXFLAGS = -Wall -Werror -Wextra

SRCS = replace.cpp Sed.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

test: $(NAME)
	cp $(NAME) test/
	sh test/test.sh

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

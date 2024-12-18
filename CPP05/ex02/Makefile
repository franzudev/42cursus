NAME = bureaucrat
CXX = clang++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
SRCS = main.cpp Bureaucrat.cpp Form.cpp PresidentialPardonForm.cpp \
RobotomyRequestForm.cpp ShrubberyCreationForm.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS) *_shrubbery

fclean: clean
	rm -rf $(NAME)

re: fclean all




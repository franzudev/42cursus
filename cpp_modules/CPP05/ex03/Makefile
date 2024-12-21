NAME = bureaucrat
CXX = clang++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
SRCS = main.cpp Bureaucrat.cpp Form.cpp PresidentialPardonForm.cpp \
RobotomyRequestForm.cpp ShrubberyCreationForm.cpp Intern.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	make clean

clean:
	rm -rf $(OBJS) *_shrubbery

fclean: clean
	rm -rf $(NAME)

re: fclean all




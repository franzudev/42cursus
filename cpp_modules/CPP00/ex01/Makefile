NAME = cbookpp

CXX = clang++

CXXFLAGS = -Wall -Werror -Wextra

SRCS_DIR = srcs/

ENTITIES_DIR = Contact PhoneBook

PATH_MAPPING = $(addprefix $(SRCS_DIR),$(addsuffix /,$(ENTITIES_DIR)))

ENTITIES_SRCS = $(addsuffix .cpp,$(ENTITIES_DIR))

SRCS = $(join $(PATH_MAPPING), $(ENTITIES_SRCS)) main.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS) $(INCLUDES)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

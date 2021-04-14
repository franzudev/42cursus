CHECKER = checker
PUSH_SWAP = push_swap
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRCS = checker.c push_swap.c
OBJS = $(SRCS:c=o)

all: $(NAME)

$(CHECKER): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

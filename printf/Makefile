NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRCS = src/ft_printf.c
OBJS	= $(SRCS:c=o)

all: $(NAME)

$(NAME): $(OBJS)
	ar -rc $@ $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
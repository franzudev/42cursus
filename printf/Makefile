NAME = output
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRCS = ft_printf.c helpers.c
OBJS = $(SRCS:c=o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) ft_printf.c helpers.c -Llibft -lft -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

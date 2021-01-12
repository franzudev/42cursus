NAME = libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRCS = $(wildcard *.c)
OBJS = $(patsubst %.c,%.o,$(SRCS))

DEPS = libft.h

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(DEPS) $(OBJS)
	ar -rc $@ *.o

clean:
	rm -f *.o

fclean: clean
	rm -f libft.a

re: fclean all
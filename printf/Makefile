NAME = libftprintf.a
CC = gcc
INCLUDE = include/libft.h
CFLAGS = -Wall -Werror -Wextra -I$(INCLUDE)
SRCS = ft_printf.c helpers.c
OBJS = $(SRCS:c=o)
LIBFT_SRC := libft
LIBFT_OBJ := libft
LIBFT_SRCS := $(wildcard $(LIBFT_SRC)/*.c)
LIBFT_OBJS := $(patsubst $(LIBFT_SRC)/%.c, $(LIBFT_OBJ)/%.o, $(LIBFT_SRCS))

all: $(NAME)

$(LIBFT_OBJ)/%.o: $(LIBFT_SRC)/%.c
	$(CC) -I$(LIBFT_SRC) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT_OBJS)
	ar -rcs $(NAME) $(OBJS) $(LIBFT_OBJS)
	rm libft/*.o

clean:
	rm -f $(OBJS) $(LIBFT_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

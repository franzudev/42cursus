INC_DIR = includes
SRC_DIR = srcs
CC = gcc
CFLAGS  = -c -Wall -Wextra -Werror -I $(INC_DIR)
SRCS = $(SRC_DIR)/ft_putchar.c $(SRC_DIR)/ft_putstr.c $(SRC_DIR)/ft_strcmp.c $(SRC_DIR)/ft_strlen.c $(SRC_DIR)/ft_swap.c
OBJS = $(SRC_DIR)/ft_putchar.o $(SRC_DIR)/ft_putstr.o $(SRC_DIR)/ft_strcmp.o $(SRC_DIR)/ft_strlen.o $(SRC_DIR)/ft_swap.o

DEPS = $(INC_DIR)/libft.h

libft.a: $(DEPS) $(OBJS)
	ar -rc $@ $(OBJS)

all: libft.a

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f libft.a

re: fclean all
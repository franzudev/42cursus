NAME = checker
NAME2 = push_swap
CC = gcc
CFLAGS = -Wall -Werror -Wextra
LDFLAGS = -Llibft -lft

SRCS_CHECKER = check_instruction.c exec_instruction.c operations.c gnl.c checker.c atoi_2.c utils.c check_args.c
SRCS_SWAP = check_instruction.c exec_instruction.c paperino.c pincopallino.c fralin.c quicksort.c operations.c gnl.c push_swap.c atoi_2.c utils.c check_args.c
# OBJS = $(SRCS:c=o)

all: $(NAME) $(NAME2)

$(NAME): $(OBJS)
	@make -C libft
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(NAME) $(SRCS_CHECKER)

$(NAME2): $(OBJS)
	@make -C libft
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(NAME2) $(SRCS_SWAP)

clean:
	@make clean -C libft

fclean: clean
	@make fclean -C libft
	rm -f $(NAME) $(NAME2)

re: fclean all

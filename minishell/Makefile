NAME = minishell

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS_DIR = srcs

SRCS_FILE = utils.c

MAIN = main.c

SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_FILE)) main.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -Llibft -lft $(OBJS) -o minishell

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
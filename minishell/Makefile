NAME = minishell

CC = gcc

CFLAGS = -Wall -Wextra -Werror

# only for personal mac
LDFLAGS = -L/usr/local/opt/ncurses/lib -lncurses

SRCS_DIR = srcs

SRCS_FILE = utils.c parser.c parser_utils.c

PRS_SRCS_FILE = parser.c utils.c

TRM_SRCS_FILE = terminal.c utils.c

CMD_SRCS_FILE = env.c pwd.c exit.c

MAIN = main.c

SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_FILE)) \
	   $(addprefix $(SRCS_DIR)/cmd/, $(CMD_SRCS_FILE)) \
	   $(addprefix $(SRCS_DIR)/terminal/, $(TRM_SRCS_FILE)) \
	   $(addprefix $(SRCS_DIR)/parser/, $(PRS_SRCS_FILE)) \
	   main.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make bonus -C libft
	$(CC) $(CFLAGS) -Llibft -lft $(OBJS) -o minishell

clean:
	@make clean -C libft
	rm -rf $(OBJS)

fclean: clean
	@make fclean -C libft
	rm -rf $(NAME)

re: fclean all

re: fclean all

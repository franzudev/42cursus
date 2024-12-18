NAME = minishell

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LDFLAGS = -Llibft -lft

SRCS_DIR = srcs

BUILTINS_SRCS_FILE =	cd.c \
						echo.c \
						env.c \
						exit.c \
						export.c \
						init_env_lst.c \
						pwd.c \
						sort_env_lst.c \
						unset.c

EXECS_SRCS_FILE =		exec_builtin.c \
						exec_cmd.c \
						exec_piped_cmd.c

HISTORY_SRCS_FILE = 	history.c

PARSING_SRCS_FILE = 	ansi_c_quoting.c \
						expand_var.c \
						handle_dbl_quotes.c \
						handle_quotes.c \
						handle_variables_quotes.c \
						handle_variables.c \
						interpreter.c \
						interpreter2.c \
						parse_cmdline.c \
						parse_path.c \
						parse_pipe.c \
						parse_semicolon.c

REDIRECTION_SRCS_FILE =	fds_handlers.c \
						fds_redir.c \
						redirection.c

TERMCAP_SRCS_FILE =		handle_keys.c \
						readline.c \
						termcap.c

TOKENIZER_SRCS_FILE =	ast_type.c \
						ast.c \
						tokenizer.c

UTILS_SRCS_FILE =		error.c \
						file_status.c \
						fork_utils.c \
						free_utils.c \
						list_utils.c \
						parsing_utils.c \
						signal.c \
						string_utils.c \
						string_utils2.c

MAIN = main.c

SRCS = $(addprefix $(SRCS_DIR)/builtins/, $(BUILTINS_SRCS_FILE)) \
	   $(addprefix $(SRCS_DIR)/execs/, $(EXECS_SRCS_FILE)) \
	   $(addprefix $(SRCS_DIR)/history/, $(HISTORY_SRCS_FILE)) \
	   $(addprefix $(SRCS_DIR)/parsing/, $(PARSING_SRCS_FILE)) \
	   $(addprefix $(SRCS_DIR)/redirection/, $(REDIRECTION_SRCS_FILE)) \
	   $(addprefix $(SRCS_DIR)/termcap/, $(TERMCAP_SRCS_FILE)) \
	   $(addprefix $(SRCS_DIR)/tokenizer/, $(TOKENIZER_SRCS_FILE)) \
	   $(addprefix $(SRCS_DIR)/utils/, $(UTILS_SRCS_FILE)) \
	   srcs/main.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make bonus -C libft
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) -o $(NAME)

clean:
	@make clean -C libft
	rm -rf $(OBJS)

fclean: clean
	@make fclean -C libft
	rm -rf $(NAME)

re: fclean all


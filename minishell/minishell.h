#ifndef MINISHELL_H
# define MINISHELL_H
# define USER "e3r4p12 $>"


# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <curses.h>
# include <term.h>
# include <fcntl.h>
# include <signal.h>
# include <sys/ioctl.h>
# include "libft/libft.h"
# include <errno.h>

typedef struct	s_env {
	char*			name;
	char*			value;
}				t_env;

enum e_arrows {
	LEFT = 1000,
	RIGHT,
	UP,
	DOWN
};

enum e_token_types {
	COMM,
	OPERATOR,
	FLAGS,
	ARGS
};

typedef struct	s_term{
	struct	termios	old_conf;
	char			**old_env;
	t_list			*env;
	char 			line[2048];
	int 			last_status_code;
	int 			cx;
	int				cy;
	int 			rows;
	int 			cols;
}				t_term;

typedef struct s_token {
	char			*value;
	int 			type;
	struct s_token	*next;
}				t_token;

typedef struct s_comm {
	char			*value;
	char 			*flags;
	int 			order;
	struct s_comm 	*next;
}				t_comm;

void	init_env(char **sys_env);
void	env_command(void);
void	free_all(void);

t_term *term;
#endif

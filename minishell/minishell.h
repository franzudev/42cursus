#ifndef MINISHELL_H
# define MINISHELL_H
# define ABUF_INIT {NULL, 0}


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

// append buffer

struct abuf {
	char *b;
	int len;
};


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

typedef struct	s_term{
	struct	termios	old_conf;
	char			**old_env;
	t_list			*env;
	int 			cx;
	int				cy;
	int 			rows;
	int 			cols;
}				t_term;

typedef struct s_comm {
	int		quote_open;
	char	value;
}				t_comm;

void	init_env(char **sys_env);
void	env_command(void);

t_term *term;
#endif

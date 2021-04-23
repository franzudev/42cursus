#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <curses.h>
# include <term.h>
# include <fcntl.h>

typedef struct s_env {
	char			*content;
	struct s_env	*next;
}	t_env;

typedef struct s_mini {
	t_env	*env;
}				t_mini;

#endif

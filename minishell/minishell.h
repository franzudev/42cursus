#ifndef MINISHELL_H
# define MINISHELL_H
# define USER "e3r4p12 $>"
# define MAX_LEN 2048

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <curses.h>
# include <term.h>
# include <fcntl.h>
# include <signal.h>
# include <sys/ioctl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "libft/libft.h"
# include <errno.h>
# include <limits.h>

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

 enum e_output {
 	STD,
	PIPE,
	APPEND,
	WRITE,
 };

 typedef struct s_history {
 	char				*executed;
 	char 				*display;
 	int 				order;
 	struct s_history	*prev;
 	struct s_history	*next;
 }				t_history;

typedef struct	s_term{
	struct	termios	old_conf;
	char			**reenv;
	t_list			*env;
	char 			line[MAX_LEN];
	t_history		*history;
	t_history		*history_clone;
	int 			history_mode;
	int 			last_status_code;
}				t_term;

typedef struct s_token {
	char			*value;
	int 			type;
	struct s_token	*next;
}				t_token;

typedef struct s_comm {
	char			*value;
	char 			**args;
	char 			*input;
	char            *output;
	int 			output_type;
	int				pipe[2];
	pid_t			pidC;
	struct s_comm	*prev;
	struct s_comm 	*next;
}				t_comm;

void	init_env(char **sys_env);
void	lst_del(void *lst);
void	free_all(void);
int		ft_size(void **arr);

// parser
t_comm	*parse_input(void);
void	command_output(t_comm *command, char *str);
void	command_input(t_comm *command, char *str);
char	*slice_operators(char *str);
//char	*ft_dollaroni(char *usd);
int		ft_index_of(char *str, char *set);
int		ft_rindex_of(char *str, char *set);
char	*strip_quotes(char *str, char *temp, char type);
char	*strip_string_from_cmd(char *str);
void	ft_add_prev(t_comm *cmd);

// terminal
void	enableRawMode(void);
void 	restore_term(void);
void	delete_nbytes(int cp);
void	delete_char(int *cp);
void	new_line_command(int *cp);
void	write_char(int *cp, char c);
int		quit_gracefully(void);
int		read_input(void);

// cmd
int		cmd_echo(t_comm *cmd);
int		cmd_cd(t_comm *cmd);
int		cmd_pwd(void);
int		cmd_exit(void);
int		cmd_export(t_comm *cmd);
int 	cmd_unset(t_comm *cmd);
int		env_command(void);
int		cmd_red_in(char *file_path);
int		cmd_red_out(char *file_path, int i);
void	free_reenv(char **reenv);
char	**rebuild_env(t_list *env, char **reenv);
int		exec_cmd(t_comm *cmd);
char	**ft_dir_path(void);
char	*ft_full_path(char **dir_path, char *cmd);
int		cmd_bin(t_comm *cmd);
int		launch_cmd(t_comm *cmd);
void	free_cmd(t_comm *commands);
int		ft_error(char *str, int i);

// history
void	update_history(int f);

t_term *term;
#endif

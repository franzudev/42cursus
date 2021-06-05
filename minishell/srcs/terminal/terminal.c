#include "../../minishell.h"


int	quit_gracefully(void)
{
	write(STDOUT_FILENO, "exit\n\x0d", 6);
	// to remove
	int file;
	file = open("history.txt", O_WRONLY);
	t_history *temp = term->history_clone;
	while (temp)
	{
		if (temp->prev)
		{
			ft_putstr_fd("\nhistory: ", file);
			ft_putstr_fd(temp->prev->executed, file);
		}
		ft_putstr_fd("\nexecuted: ", file);
		ft_putstr_fd(temp->executed, file);
		ft_putstr_fd("\nexec: ", file);
		ft_putstr_fd(temp->display, file);
		temp = temp->next;
	}
	close(file);
	// till here
	return (-1);
}

void	enableRawMode(void)
{
	struct termios	raw;

	if (tcgetattr(STDIN_FILENO, &term->old_conf) == -1)
		exit(2);
	raw = term->old_conf;
	raw.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
	raw.c_oflag &= ~(OPOST);
	raw.c_cflag |= (CS8);
	raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
	raw.c_cc[VMIN] = 0;
	raw.c_cc[VTIME] = 1;
	if (tcsetattr(STDIN_FILENO, TCSANOW, &raw) == -1)
		exit(3);
}

void	restore_term(void)
{
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &term->old_conf);
}

static void	parse_n_exec(int *cp)
{
	t_comm	*comm;

	if (term->history && !term->history->executed)
		term->history->executed = ft_strdup(term->line);
	else
	{
		ft_putstr_fd("song ca", 1);
		if (term->history)
		{
			ft_memset(term->history->display, \
			 0, ft_strlen(term->history->display));
			term->history->display = ft_strdup(term->history->executed);
		}
		remove_unexecuted();
		update_history(1);
	}
	comm = parse_input();
 	if (comm)
	{
		restore_term();
		ft_putstr_fd("agg a puli'", 1);
//		launch_cmd(comm);
		free_cmd(comm);
		ft_putstr_fd("agg pulit'", 1);
		enableRawMode();
	}
 	else
		ft_putstr_fd("\n\x0d", 1);
	term->history_mode = 0;
	new_line_command(cp);
}

int	read_input(void)
{
	ssize_t	r;
	int		cp;
	char	c;

	cp = 0;
	write(1, USER, ft_strlen(USER));
	r = read(STDIN_FILENO, &c, 1);
	while (r > -1)
	{
		if (c == '\x1b')
			is_arrow_key(&cp);
		if (ft_isprint(c))
			write_char(&cp, c);
		if (c == 127 && cp != 0)
			delete_char(&cp);
		if (c == '\r')
			parse_n_exec(&cp);
		if (c == (('d') & 0x1f) && cp == 0)
			return (quit_gracefully());
		if (c == (('c') & 0x1f))
		{
			ft_putstr_fd("\n\x0d", 1);
			new_line_command(&cp);
		}
		c = 0;
		r = read(STDIN_FILENO, &c, 1);
	}
	return (r);
}

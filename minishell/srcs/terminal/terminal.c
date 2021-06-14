#include "../../minishell.h"

int	quit_gracefully(void)
{
	write(STDOUT_FILENO, "exit\n\x0d", 6);
	return (-1);
}

void	enableRawMode(void)
{
	struct termios	raw;

	if (tcgetattr(STDIN_FILENO, &g_term->old_conf) == -1)
		exit(2);
	raw = g_term->old_conf;
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
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &g_term->old_conf);
}

static void	parse_n_exec(int *cp)
{
	t_comm	*comm;

	if (g_term->history && !g_term->history->executed)
		g_term->history->executed = ft_strdup(g_term->line);
	else
	{
		if (g_term->history)
		{
			free(g_term->history->display);
			ft_memset(g_term->history->display, \
			 0, ft_strlen(g_term->history->display));
			g_term->history->display = ft_strdup(g_term->history->executed);
		}
		remove_unexecuted();
		update_history(1);
	}
	comm = parse_input();
	if (comm)
	{
		restore_term();
		launch_cmd(comm);
		free_cmd(comm);
		enableRawMode();
	}
	else
		ft_putstr_fd("\n\x0d", 1);
	g_term->history_mode = 0;
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

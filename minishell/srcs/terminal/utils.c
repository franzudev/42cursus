#include "../../minishell.h"

void	delete_nbytes(int cp)
{
	while (cp)
	{
		write(STDOUT_FILENO, "\b", 1);
		write(STDOUT_FILENO, "\x20", 1);
		write(STDOUT_FILENO, "\b", 1);
		cp--;
	}
}

static void	edit_history(void)
{
	if (g_term->history_mode)
	{
		ft_memset(g_term->history->display, 0, ft_strlen(g_term->history->display));
		g_term->history->display = ft_strdup(g_term->line);
	}
}

void	delete_char(int *cp)
{
	delete_nbytes(1);
	*cp -= 1;
	g_term->line[*cp] = '\0';
	edit_history();
}

void	write_char(int *cp, char c)
{
	write(STDOUT_FILENO, &c, 1);
	g_term->line[*cp] = c;
	edit_history();
	*cp += 1;
}

void	new_line_command(int *cp)
{
	write(1, USER, ft_strlen(USER));
	ft_memset(g_term->line, 0, ft_strlen(g_term->line));
	*cp = 0;
}

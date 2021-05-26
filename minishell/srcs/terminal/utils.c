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
	if (term->history_mode)
	{
		ft_memset(term->history->display, 0, ft_strlen(term->history->display));
		term->history->display = ft_strdup(term->line);
	}
}

void	delete_char(int *cp)
{
	delete_nbytes(1);
	*cp -= 1;
	term->line[*cp] = '\0';
	edit_history();
}

void	write_char(int *cp, char c)
{
	write(STDOUT_FILENO, &c, 1);
	term->line[*cp] = c;
	edit_history();
	*cp += 1;
}

void	new_line_command(int *cp)
{
	write(1, USER, ft_strlen(USER));
	ft_memset(term->line, 0, ft_strlen(term->line));
	*cp = 0;
}

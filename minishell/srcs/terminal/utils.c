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

void	delete_char(int *cp)
{
	delete_nbytes(1);
	*cp -= 1;
	term->line[*cp] = '\0';
}

void	write_char(int *cp, char c)
{
	write(STDOUT_FILENO, &c, 1);
	term->line[*cp] = c;
	*cp += 1;
}

void	new_line_command(int *cp)
{
	write(1, "\n\x0d", 2);
	write(1, USER, ft_strlen(USER));
	ft_memset(term->line, 0, ft_strlen(term->line));
	*cp = 0;
}

int	quit_gracefully(void)
{
	write(STDOUT_FILENO, "exit\n\x0d", 6);
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
	return (-1);
}

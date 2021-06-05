#include "../../minishell.h"

static void	restore_clone(void)
{
	while (g_term->history_clone)
	{
		if (g_term->history_clone->prev)
			g_term->history_clone = g_term->history_clone->prev;
		else
			break ;
	}
}

void	remove_unexecuted(void)
{
	t_history	*prev;

	if (!g_term->history_clone)
		return ;
	while (g_term->history_clone)
	{
		if (!g_term->history_clone->executed)
		{
			free(g_term->history_clone->display);
			if (g_term->history_clone->prev)
			{
				prev = g_term->history_clone->prev;
				prev->next = g_term->history_clone->next;
			}
			else
				prev = g_term->history_clone->next;
			free(g_term->history_clone);
			g_term->history_clone = prev;
		}
		if (g_term->history_clone->next)
			g_term->history_clone = g_term->history_clone->next;
		else
			break ;
	}
	restore_clone();
}

void	put_history(char *display, int *cp)
{
	int	len;

	len = ft_strlen(g_term->line);
	if (len > 0)
	{
		delete_nbytes(len);
		ft_memset(g_term->line, 0, len);
	}
	len = 0;
	while (*display)
		g_term->line[len++] = *(display++);
	*cp = len;
	write(1, g_term->line, len);
}

int	hist_size(void)
{
	int			len;
	t_history	*hist;

	hist = g_term->history_clone;
	len = 0;
	while (hist)
	{
		len++;
		hist = hist->next;
	}
	return (len);
}

int	is_same_history(void)
{
	int	len;

	len = ft_strlen(g_term->line);
	if (ft_strncmp(g_term->line, g_term->history->display, len) == 0)
		return (1);
	return (0);
}

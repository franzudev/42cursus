#include "../../minishell.h"

void	remove_unexecuted(void)
{
	t_history *prev;

	while (term->history_clone)
	{
		if (!term->history_clone->executed)
		{
			free(term->history_clone->display);
			if (term->history_clone->prev)
			{
				prev = term->history_clone->prev;
				prev->next = term->history_clone->next;
			}
			else
				prev = term->history_clone->next;
			free(term->history_clone);
			term->history_clone = prev;
		}
		if (term->history_clone->next)
			term->history_clone = term->history_clone->next;
		else
			break;
	}
	while (term->history_clone)
	{
		if (term->history_clone->prev)
			term->history_clone = term->history_clone->prev;
		else
			break;
	}
}

void	put_history(char *display, int *cp)
{
	int len;

	len = ft_strlen(term->line);
	if (len > 0)
	{
		delete_nbytes(len);
		ft_memset(term->line, 0, len);
	}
	len = 0;
	while (*display)
		term->line[len++] = *(display++);
	*cp = len;
	write(1, term->line, len);
}

int	hist_size(void)
{
	int			len;
	t_history	*hist;

	hist = term->history_clone;
	len = 0;
	while  (hist)
	{
		len++;
		hist = hist->next;
	}
	return (len);
}

int		is_same_history(void)
{
	int len;

	len = ft_strlen(term->line);
	if (ft_strncmp(term->line, term->history->display, len) == 0)
		return (1);
	return (0);
}

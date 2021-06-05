#include "../../minishell.h"

void 	arrow_up(int *cp)
{
	t_history	*history;

	history = g_term->history;
	if (history->order == hist_size() && !g_term->history_mode)
		put_history(history->display, cp);
	else if (history->prev)
	{
		put_history(history->prev->display, cp);
		g_term->history = history->prev;
	}
	else
		put_history(history->display, cp);
	g_term->history_mode = 1;
}

void 	arrow_down(int *cp)
{
	if (g_term->history->order == hist_size() && !ft_strlen(g_term->line))
		return ;
	else if (!g_term->history->executed)
		return ;
	else if (g_term->history->order == hist_size())
	{
		put_history("", cp);
		g_term->history_mode = 0;
		if (g_term->history->next)
			g_term->history = g_term->history->next;
	}
	else if (g_term->history->next)
	{
		put_history(g_term->history->next->display, cp);
		g_term->history = g_term->history->next;
		g_term->history_mode = 1;
	}
}

void	is_arrow_key(int *cp)
{
	char	buff[2];

	read(STDIN_FILENO, &buff, 2);
//	arrow_up(cp);
//	arrow_up(cp);
//	buff[0] = '[';
//	buff[1] = 'B';
	if (!g_term->history)
		return ;
	if (buff[0] == '[' && buff[1] == 'A')
	{
		if (ft_strlen(g_term->line) > 0
			&& hist_size() == g_term->history->order && !is_same_history())
		{
			update_history(0);
//			g_term->history = g_term->history->next;
		}
		arrow_up(cp);
	}
	if (buff[0] == '[' && buff[1] == 'B')
		arrow_down(cp);
}

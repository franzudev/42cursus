#include "../../minishell.h"

void 	arrow_up(int *cp)
{
	t_history	*history;

	history = term->history;
	if (history->order == hist_size() && !term->history_mode)
		put_history(history->display, cp);
	else if (history->prev)
	{
		put_history(history->prev->display, cp);
		term->history = history->prev;
	}
	else
		put_history(history->display, cp);
	term->history_mode = 1;
}

void 	arrow_down(int *cp)
{
	if (term->history->order == hist_size() && !ft_strlen(term->line))
		return ;
	else if (!term->history->executed)
		return ;
	else if (term->history->order == hist_size())
	{
		put_history("", cp);
		term->history_mode = 0;
		if (term->history->next)
			term->history = term->history->next;
	}
	else if (term->history->next)
	{
		put_history(term->history->next->display, cp);
		term->history = term->history->next;
		term->history_mode = 1;
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
	if (!term->history)
		return ;
	if (buff[0] == '[' && buff[1] == 'A')
	{
		if (ft_strlen(term->line) > 0
			&& hist_size() == term->history->order && !is_same_history())
		{
			update_history(0);
//			term->history = term->history->next;
		}
		arrow_up(cp);
	}
	if (buff[0] == '[' && buff[1] == 'B')
		arrow_down(cp);
}

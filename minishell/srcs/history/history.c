#include "../../minishell.h"

t_history	*histlast(t_history *lst)
{
	if (!lst)
		return (lst);
	while (lst->next)
		lst = lst->next;
	return (lst);
}


void	histadd_back(t_history **lst, t_history *new)
{
	t_history *res;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	res = histlast(*lst);
//	new->prev = res;
	res->next = new;
}

void	update_history()
{
	t_history *history;

	history = (t_history *) malloc(sizeof(t_history));
	history->executed = ft_strdup(term->line);
	history->display = ft_strdup(term->line);
	histadd_back(&term->history, history);
}

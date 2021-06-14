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
	t_history	*res;

	if (!new)
		return ;
	if (!*lst)
	{
		new->order = 1;
		*lst = new;
		return ;
	}
	res = histlast(*lst);
	new->order = res->order + 1;
	new->prev = res;
	new->next = NULL;
	res->next = new;
}

void	update_history(int f)
{
	t_history	*history;

	if (!ft_strlen(g_term->line))
		return ;
	history = (t_history *) malloc(sizeof(t_history));
	if (!history)
		return ;
	if (f)
		history->executed = ft_strdup(g_term->line);
	history->display = ft_strdup(g_term->line);
	histadd_back(&g_term->history, history);
	g_term->history = history;
	if (!g_term->history_clone)
		g_term->history_clone = g_term->history;
}

#include "../minishell.h"

int	ft_index_of(char *str, char *set)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_strchr(set, str[i]))
			return (i);
		i++;
	}
	return (-1);
}

int	ft_rindex_of(char *str, char *set)
{
	int	i;

	i = (int)ft_strlen(str) - 1;
	while (i > -1)
	{
		if (ft_strchr(set, str[i]))
			return (i);
		i--;
	}
	return (-1);
}

int	ft_size(void **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	lst_del(void *lst)
{
	if (!lst)
		return ;
	free(((t_env *)lst)->name);
	free(((t_env *)lst)->value);
	free(lst);
	lst = NULL;
}

void	hist_del(void *lst)
{
	if (!lst)
		return ;
	free(((t_history *)lst)->executed);
	free(((t_history *)lst)->display);
}

void	ft_histdelone(t_history *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	del(lst);
	free(lst);
	lst = NULL;
}

void	ft_histclear(t_history **lst, void (*del)(void *))
{
	t_history	*temp;

	if (!*lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_histdelone(*lst, del);
		*lst = temp;
	}
	*lst = 0;
}

void	free_all(void)
{
	ft_histclear(&term->history_clone, hist_del);
	ft_histclear(&term->history_clone, free);
	ft_lstclear(&term->env, lst_del);
	ft_lstclear(&term->env, free);
	free(term->history);
	free(term->env);
	free(term);
}
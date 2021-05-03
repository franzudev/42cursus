#include "../minishell.h"

void	lst_del(void *lst)
{
	if (!lst)
		return ;
	free(((t_env *)lst)->name);
	free(((t_env *)lst)->value);
	free(lst);
	lst = NULL;
}

void	free_all(void)
{
	ft_lstclear(&term->env, lst_del);
	ft_lstclear(&term->env, free);
	free(term->env);
	free(term);
}
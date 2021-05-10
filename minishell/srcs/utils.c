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

void	free_all(void)
{
	ft_lstclear(&term->env, lst_del);
	ft_lstclear(&term->env, free);
	free(term->env);
	free(term);
}
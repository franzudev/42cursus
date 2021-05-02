#include "minishell.h"

void	lst_del(void *lst)
{
	if (!lst)
		return ;
	free(((t_env *)lst)->name);
	free(((t_env *)lst)->value);
	free(lst);
	lst = NULL;
}

void	lst_dele(void *lst)
{
	free(lst);
	lst = NULL;
}

int	main(int argc, char **argv, char **env)
{
	term = (t_term *)malloc(sizeof(t_term));
	if (argc != 1)
		exit(1);
	if (!argv[0])
		exit(1);
	init_env(env);
	env_command();
	ft_lstclear(&term->env, lst_del);
	ft_lstclear(&term->env, lst_dele);
	free(term->env);
	term->env = NULL;
	free(term);
	term = NULL;
}

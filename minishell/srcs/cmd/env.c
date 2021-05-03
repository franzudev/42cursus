#include "../../minishell.h"

int	env_command(void)
{
	t_list	*t;

	t = term->env;
	while (t->content)
	{
		printf("\x0d%s=%s\n", ((t_env *)t->content)->name, (
				(t_env *)t->content)->value);
		t = t->next;
	}
	return (EXIT_SUCCESS);
}

static t_list	*alloc_env(char *sys_env, t_list *temp)
{
	t_env	*env;
	char	**envval;

	env = (t_env *)malloc(sizeof(t_env));
	if (!env)
		exit(1);
	envval = ft_split(sys_env, '=');
	env->name = envval[0];
	env->value = envval[1];
	temp->content = env;
	temp->next = (t_list *)malloc(sizeof(t_list));
	if (!temp->next)
		exit(1);
	free(envval);
	return (temp->next);
}

void	init_env(char **sys_env)
{
	t_list	*env_list;
	t_list	*temp;
	t_env	*env;
	char	**envval;
	int		i;

	i = 1;
	env_list = (t_list *)malloc(sizeof(t_list));
	env = (t_env *)malloc(sizeof(t_env));
	if (!env)
		exit(1);
	envval = ft_split(sys_env[0], '=');
	env->name = envval[0];
	env->value = envval[1];
	env_list->content = env;
	env_list->next = (t_list *)malloc(sizeof(t_list));
	temp = env_list;
	temp = temp->next;
	free(envval);
	while (sys_env[i])
		temp = alloc_env(sys_env[i++], temp);
	term->env = env_list;
}

#include "../../minishell.h"

void	free_reenv(char **reenv)
{
	int	i;

	i = 0;
	if (!reenv)
		return ;
	while (reenv[i])
		free(reenv[i++]);
	free(reenv);
}

char	**rebuild_env(t_list *env, char **reenv)
{
	char	**new;
	char	*temp;
	int		i;

	i = 0;
	free_reenv(reenv);
	new = (char **)malloc(sizeof(char *) * ft_lstsize(env));
	while (env)
	{
		temp = ft_strjoin(((t_env *)env->content)->name, "=");
		new[i] = ft_strjoin(temp, ((t_env *)env->content)->value);
		free(temp);
		i++;
	}
	return (new);
}

int	env_command(int export)
{
	t_list	*t;

	t = term->env;
	while (t)
	{
		if (export)
			ft_putstr_fd("declare -x ", 1);
		ft_putstr_fd(((t_env *)t->content)->name, 1);
		ft_putstr_fd("=", 1);
		if (export)
			ft_putstr_fd("\"", 1);
		ft_putstr_fd(((t_env *)t->content)->value, 1);
		if (export)
			ft_putstr_fd("\"", 1);
		ft_putstr_fd("\n\x0d", 1);
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
	ft_lstadd_back(&temp, ft_lstnew(env));
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
	env = (t_env *)malloc(sizeof(t_env));
	if (!env)
		exit(1);
	envval = ft_split(sys_env[0], '=');
	env->name = envval[0];
	env->value = envval[1];
	env_list = ft_lstnew(env);
	temp = env_list;
	free(envval);
	while (sys_env[i])
		temp = alloc_env(sys_env[i++], temp);
	term->env = env_list;
}

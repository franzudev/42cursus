#include "../../minishell.h"

int	cmd_export(t_comm *cmd)
{
	t_list	*t;
	t_env	*new;
	char	**envval;

	if (!cmd->args[1])
	{
		env_command(1);
		return (EXIT_SUCCESS);
	}
	new = (t_env *)malloc(sizeof(t_env));
	envval = ft_split(cmd->args[1], '=');
	new->name = envval[0];
	new->value = envval[1];
	free(envval);
	t = ft_lstnew(new);
	ft_lstadd_back(&g_term->env, t);
	return (EXIT_SUCCESS);
}

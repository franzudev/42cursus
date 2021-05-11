#include "../../minishell.h"

int	cmd_export(t_comm *cmd) //ft_lstnew PORCODIO
{
	t_list	*t;
	t_env	*new;
	char	**envval;

	new = (t_env *)malloc(sizeof(t_env));
	envval = ft_split(cmd->args[1], '=');
	new->name = envval[0];
	new->value = envval[1];
	free(envval);
	t = ft_lstnew(new);
	ft_lstadd_back(&term->env,t);
	return (EXIT_SUCCESS);
}

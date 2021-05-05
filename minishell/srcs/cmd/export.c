#include "../../minishell.h"

int	cmd_export(t_comm *cmd)
{
	t_list *t;
	t_list *new;
	char	**envval;

	t = term->env;
	envval = ft_split(cmd->args, '=');
	((t_env *)new->content)->name = envval[0];
	((t_env *)new->content)->value = envval[1];
	ft_lstadd_back(&t, new);
	return (EXIT_SUCCESS);
}

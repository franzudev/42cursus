#include "../../minishell.h"

int cmd_unset(t_comm *cmd)
{
	int len;
	t_list *t;
	t_list *prev;

	t = term->env;
	if (!cmd->args[1])
		return (EXIT_SUCCESS);
	len = ft_strlen(cmd->args[1]);
	while(t)
	{
		if(ft_strncmp(((t_env *)t->content)->name, cmd->args[1], len) == 0)
		{
			prev->next = t->next;
			ft_lstdelone(t, lst_del);
			return (EXIT_SUCCESS);
		}
		prev = t;
		t = t->next;
	}
	return (EXIT_FAILURE);
}

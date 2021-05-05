#include "../../minishell.h"

int cmd_unset(t_comm *cmd)
{
	int len;
	t_list *t;
	t_list *prev;

	t = term->env;
	len = ft_strlen(cmd->args);
	while(t)
	{
		if(ft_strncmp(((t_env *)t->content)->name, cmd->args, len) == 0)
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

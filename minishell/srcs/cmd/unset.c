#include "../../minishell.h"

int cmd_unset(t_comm *cmd)
{
	int len;
	int first;
	t_list *t;
	t_list *prev;

	t = term->env;
	if (!cmd->args[1])
	{
		write(STDOUT_FILENO, "\n\x0d", 2);
		return (EXIT_SUCCESS);
	}
	len = ft_strlen(cmd->args[1]);
	first = 0;
	while(t)
	{
		if (ft_strncmp(((t_env *)t->content)->name, cmd->args[1], len) == 0)
		{
			if (!first)
			{
				prev = t->next;
				ft_lstdelone(t, lst_del);
				t = prev;
			}
			else
			{
				prev->next = t->next;
				ft_lstdelone(t, lst_del);
				break;
			}
		}
		prev = t;
		first = 1;
		t = t->next;
	}
	write(STDOUT_FILENO, "\n\x0d", 2);
	term->last_status_code = 0;
	return (EXIT_SUCCESS);
}

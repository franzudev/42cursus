#include "../../minishell.h"

static int is_env(t_comm *cmd)
{
	if(cmd->args[0] == '$')
		return(EXIT_SUCCESS);
	return(EXIT_FAILURE);
}

static char	*ft_search_env(t_comm *cmd)
{
	t_list	*t;
	char *str;

	t = term->env;
	str = cmd->args + 1;
	while(t)
	{
		if (ft_strncmp(str, ((t_env *)t->content)->name, ft_strlen(str)) == 0)
			return (((t_env *)t->content)->value);
		t = t->next;
	}
	return (NULL);
}

int	cmd_echo(t_comm *cmd)
{
	char	*env;

	if (!(is_env(cmd)))
	{
		env = ft_search_env(cmd);
		if (env != NULL)
			write(STDOUT_FILENO, env, ft_strlen(env));
	}
	else
		write(STDOUT_FILENO, cmd->args, ft_strlen(cmd->args));
	if (ft_strncmp(cmd->flags, "-n", 2) != 0)
		write(STDOUT_FILENO, "\n", 1);
	return (EXIT_SUCCESS);
}

int main()
{
	t_comm comm;

	comm.flags = "";
	comm.value = "echo";
	comm.args = "ciao ciao";

	cmd_echo(&comm);

	return 0;
}

// Porca Miseria non funziona con $$$ >>> PDIOOOOOOOOOØØ!!!! seg fault
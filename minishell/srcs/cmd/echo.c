#include "../../minishell.h"

// static int is_env(t_comm *cmd)
// {
// 	if(cmd->args[1][0] == '$' || cmd->args[2][0]) //da aggiustare
// 		return(EXIT_SUCCESS);
// 	return(EXIT_FAILURE);
// }

// static char	*ft_search_env(t_comm *cmd)
// {
// 	t_list	*t;
// 	char *str;

// 	t = term->env;
// 	str = cmd->args + 1; // NO PORCODIO
// 	while(t)
// 	{
// 		if (ft_strncmp(str, ((t_env *)t->content)->name, ft_strlen(str)) == 0)
// 			return (((t_env *)t->content)->value);
// 		t = t->next;
// 	}
// 	return (NULL);
// }

int	cmd_echo(t_comm *cmd)
{
	//char	*env;
	int 	i;
	int		option;
	// if (!(is_env(cmd)))
	// {
	// 	env = ft_search_env(cmd);
	// 	if (env != NULL)
	// 		write(STDOUT_FILENO, env, ft_strlen(env));
	// }
	// else
	// {
		write(STDOUT_FILENO, "\n\x0d", 2);
		i = 1;
		option = 0;
		if (cmd->args[i])
		{
			if (!ft_strncmp(cmd->args[1], "-n", 3))
			{
				i = 2;
				option = 1;
				if(!cmd->args[i])
					return(EXIT_SUCCESS);
			}
			write(STDOUT_FILENO, cmd->args[i], ft_strlen(cmd->args[i]));
			while (cmd->args[++i])
			{
					write(STDOUT_FILENO, " ", 1);
					write(STDOUT_FILENO, cmd->args[i], ft_strlen(cmd->args[i]));
			}
		}
		if (option == 0)
			write(STDOUT_FILENO, "\n\x0d", 2);
	return (EXIT_SUCCESS);
}

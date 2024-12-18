#include "../../minishell.h"

int	ft_error(char *str, int i)
{
	ft_putstr_fd(str, 1);
	ft_putstr_fd(": command not found\n\x0d", 2);
	return (i);
}

void	free_cmd(t_comm *commands)
{
	int		i;
	t_comm	*command;

	command = commands;
	while (command)
	{
		i = 0;
		if (command->args)
		{
			while (command->args[i])
			{
				free(command->args[i]);
				command->args[i++] = NULL;
			}
			free(command->args);
			if (command->input)
				free(command->input);
			if (command->output)
				free(command->output);
			free(commands);
			command = command->next;
			commands = command;
			continue ;
		}
		break ;
	}
	free(commands);
}

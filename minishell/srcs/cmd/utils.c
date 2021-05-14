#include "../../minishell.h"

void free_cmd(t_comm *commands)
{
	int	i;
	t_comm *command;

	command = commands;
	while (command)
	{
		i = 0;
		if (command->args) {
			while (command->args[i])
				free(command->args[i++]);
			free(command->args);
			if (command->input)
				free(command->input);
			if (command->output)
				free(command->output);
			free(commands);
			command = command->next;
			commands = command;
			continue;
		}
		break;
	}
	free(commands);
}

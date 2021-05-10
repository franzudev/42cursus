#include "../../minishell.h"

static void	parse_operators(t_comm *command, char *cmd, int cmds_size, int
index)
{
	char	*tmp;

	command_output(command, cmd);
	if (!command->output && cmds_size > 1 && index != cmds_size - 1)
		command->output_type = PIPE;
	command_input(command, cmd);
	if (command->output_type > PIPE || command->input)
	{
		tmp = slice_operators(cmd);
		command->args = ft_split(tmp, ' ');
		free(tmp);
	}
	else
		command->args = ft_split(cmd, ' ');
}

static void	parse_command(t_comm *command, char **cmd)
{
	int	j;
	int	size;

	j = 0;
	size = ft_size((void **)cmd);
	while (cmd[j])
	{
		parse_operators(command, cmd[j], size, j);
		command->value = command->args[0];
		command->next = (t_comm *)malloc(sizeof(t_comm));
		command = command->next;
		free(cmd[j]);
		j++;
	}
}

t_comm	*parse_input(void)
{
	int		i;
	char	**cmds;
	char	**cmd;
	t_comm	*commands;
	t_comm	*command;

	cmds = ft_split(term->line, ';');
	commands = (t_comm *)malloc(sizeof(t_comm));
	command = commands;
	i = 0;
	while (cmds[i])
	{
		cmd = ft_split(cmds[i], '|');
		parse_command(command, cmd);
		free(cmd);
		i++;
	}
	i = 0;
	while (cmds[i])
		free(cmds[i++]);
	free(cmds);
	return (commands);
}

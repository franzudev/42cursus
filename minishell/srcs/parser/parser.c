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

static void	parse_strings(t_comm *command, char *cmd)
{
	char	**args;
	int		i;
	int		s;
	char	*temp;

	args = command->args;
	temp = NULL;
	i = 0;
	while (args[i])
	{
		if (ft_index_of(args[i], "'\"") != -1)
		{
			temp = strip_string_from_cmd(cmd);
			// if (temp[0] == '"')
			// 	ft_dollaroni(temp);
			s = i;
			free(args[i++]);
			while (args[i])
			{
				free(args[i]);
				args[i++] = NULL;
			}
			args[s] = ft_strdup(temp);
			if (temp)
				free(temp);
			continue ;
		}
		i++;
	}
}

static t_comm	*parse_command(t_comm *command, char **cmds, int i)
{
	int	j;
	int	size;

	j = 0;
	size = ft_size((void **)cmds);
	while (cmds[j])
	{
		parse_operators(command, cmds[j], size, j);
		parse_strings(command, cmds[j]);
		command->value = command->args[0];
		if (j < size - i)
			command->next = (t_comm *)malloc(sizeof(t_comm));
		command = command->next;
		free(cmds[j]);
		j++;
	}
	return (command);
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
	i = 0;
	cmd = ft_split(cmds[i++], '|');
	command = parse_command(commands, cmd, 0);
	free(cmd);
	while (cmds[i])
	{
		cmd = ft_split(cmds[i], '|');
		command = parse_command(command, cmd, 1);
		free(cmd);
		i++;
	}
	free(command);
	command = NULL;
	i = 0;
	while (cmds[i])
		free(cmds[i++]);
	free(cmds);
	return (commands);
}

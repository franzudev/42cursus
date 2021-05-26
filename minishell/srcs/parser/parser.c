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

static void	free_args(char **args, int i)
{
	int		q_idx;
	int		pos;
	int		on;
	char	type;
	int		size;

	q_idx = ft_index_of(args[i], "'\"");
	type = args[i][q_idx];
	on = 0;
	if (ft_rindex_of(args[i], &type) == q_idx)
		pos = i + 1;
	else
	{
		pos = i;
		on = 1;
	}
	size = ft_size((void **)args);
	free(args[i]);
	args[i++] = NULL;
	while (args[i])
	{
		if (ft_index_of(args[i], &type) == -1)
		{
			free(args[i]);
			args[i] = NULL;
		}
		else
		{
			int diff = (i - pos);
			if (on)
				break;
			else
				diff++;
			while (pos + diff <= size)
			{
				free(args[i]);
				args[i++] = NULL;
				args[pos] = args[pos + diff];
				pos++;
			}
			break;
		}
		i++;
	}
}

static void	parse_strings(t_comm *command, char *cmd)
{
	char	**args;
	char	**cmd_p;
	int		i;
	int		s;
	char	*temp;

	cmd_p = (char **)malloc(sizeof(char *));
	*cmd_p = cmd;
	args = command->args;
	temp = NULL;
	i = 0;
	while (args[i])
	{
		if (ft_index_of(args[i], "'\"") != -1)
		{
			temp = strip_string_from_cmd(cmd_p);
			if (!temp)
			{
				args[i] = ft_strdup("");
				i++;
				continue ;
			}
			s = i;
			if (!(i == ft_size((void **)args) - 1))
				free_args(args, i);
			args[s] = ft_strdup(++temp);
			--temp;
			i = s;
			if (temp)
			{
				free(temp);
				temp = NULL;
			}
		}
		i++;
	}
	free(cmd_p);
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

void	ft_add_prev(t_comm *cmd)
{
	t_comm	*prev;
	t_comm	*save;

	cmd->prev = NULL;
	prev = cmd;
	save = cmd;
	cmd = cmd->next;
	while (cmd)
	{
		if (cmd->input && cmd->prev)
		{
			save->input = cmd->input;
			cmd->input = NULL;
		}
		cmd->prev = prev;
		prev = cmd;
		cmd = cmd->next;
	}
}

t_comm	*parse_input(void)
{
	int		i;
	char	**cmds;
	char	**cmd;
	t_comm	*commands;
	t_comm	*command;

	if (ft_strlen(term->line) == 0)
		return (NULL);
	i = 0;
	cmds = ft_split(term->line, ';');
	commands = (t_comm *)malloc(sizeof(t_comm));
	cmd = ft_split(cmds[i++], '|');
	command = parse_command(commands, cmd, cmds[i] ? 0 : 1);
	free(cmd);
	while (cmds[i])
	{
		cmd = ft_split(cmds[i], '|');
		command = parse_command(command, cmd, 1);
		free(cmd);
		i++;
	}
//	if (command)
//		free(command);
//	command = NULL;
	i = 0;
	while (cmds[i])
		free(cmds[i++]);
	free(cmds);
	return (commands);
}

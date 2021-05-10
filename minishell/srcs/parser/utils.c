#include "../../minishell.h"

static int	is_append(const char *str, int *wri)
{
	if (*wri > 0 && str[*wri - 1] == '>')
	{
		*wri -= 1;
		return (*wri + 1);
	}
	return (-1);
}

void	command_output(t_comm *command, char *str)
{
	int		wri;
	int		app;
	int		inp;
	char	*temp;

	wri = ft_rindex_of(str, ">");
	app = is_append(str, &wri);
	if (wri != -1 || app != -1)
	{
		++wri;
		++app;
		if (wri > app)
		{
			inp = ft_rindex_of(&str[wri], "<");
			command->output_type = WRITE;
			if (inp != -1)
				temp = ft_substr(&str[wri], 0, ft_index_of(&str[wri], "<"));
			else
				temp = ft_substr(&str[wri], 0, ft_strlen(&str[wri]));
		}
		if (app > wri)
		{
			inp = ft_rindex_of(&str[app], "<");
			command->output_type = APPEND;
			if (inp != -1)
				temp = ft_substr(&str[app], 0, ft_index_of(&str[app], "<"));
			else
				temp = ft_substr(&str[app], 0, ft_strlen(&str[app]));
		}
		command->output = ft_strtrim(temp, " ");
		free(temp);
	}
	else
	{
		command->output = NULL;
		command->output_type = STD;
	}
}

void	command_input(t_comm *command, char *str)
{
	int		inp;
	int		wri;
	int		app;
	char	*temp;

	inp = ft_rindex_of(str, "<");
	if (inp != -1)
	{
		++inp;
		wri = ft_index_of(&str[inp], ">");
		app = is_append(&str[inp], &wri);
		if (wri == -1 && app == -1)
			temp = ft_substr(&str[inp], 0, ft_strlen(&str[inp]));
		else
			temp = ft_substr(&str[inp], 0, ft_index_of(&str[inp], ">"));
		command->input = ft_strtrim(temp, " ");
		free(temp);
	}
	else
		command->input = NULL;
}

char	*slice_operators(char *str)
{
	int	inp;
	int	wri;

	inp = ft_index_of(str, "<");
	wri = ft_index_of(str, ">");
	if (inp == -1 && wri == -1)
		return (str);
	if (inp < wri)
		return (ft_substr(str, 0, inp));
	return (ft_substr(str, 0, wri));
}

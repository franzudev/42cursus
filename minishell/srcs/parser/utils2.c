#include "../../minishell.h"

char	*replace_dollar(char *str)
{
	t_list	*temp;
	t_env	*env;
	int		i;

	temp = g_term->env;
	i = 0;
	while (ft_isalpha(str[i]))
		i++;
	while (temp)
	{
		env = temp->content;
		if (!ft_strncmp(env->name, str, i))
			return (env->value);
		temp = temp->next;
	}
	return (NULL);
}

char	*strip_quotes(char *str, char **temp, char type)
{
	int		i;
	int		next_quote;
	char	*dollar;
	char	*join;

	next_quote = ft_rindex_of(str, &type);
	if (next_quote == 0 || next_quote == 1)
		return (ft_substr(str, 1, 0));
	i = 1;
	while (str[i] != type)
		i++;
	*temp = (char *)malloc(i);
	ft_strlcat(*temp, str++, 2);
	while (*str && *str != type)
	{
		if (type == '"' && *str == '$' && (*(str + 1) != ' '
				&& *(str + 1) != '"'))
		{
			dollar = replace_dollar(++str);
			if (dollar)
			{
				join = ft_strjoin(*temp, dollar);
				free(*temp);
				*temp = join;
			}
			while (*str && ft_isalpha(*str))
				str++;
			continue ;
		}
		else
			ft_strlcat(*temp, str++, ft_strlen(*temp) + 2);
	}
//	ft_strlcat(temp, str++, ft_strlen(temp) + 2);
	return (++str);
}

char	*strip_string_from_cmd(char **string)
{
	char	**temp;
	char	*str;

	str = *string;
	temp = (char **)malloc(sizeof(char *));
	while (*str)
	{
		if (*str == '\'')
		{
			str = strip_quotes(str, temp, '\'');
			break ;
//			str += ft_strlen(temp);
		}
		if (*str == '"')
		{
			str = strip_quotes(str, temp, '"');
			break ;
//			str += ft_strlen(temp);
		}
		str++;
	}
	*string = str;
	free(temp);
	return (*temp);
}

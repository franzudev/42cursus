#include "../../minishell.h"

char	*strip_quotes(char *str, char *temp, char type)
{
	int i;

	if (ft_rindex_of(str, &type) == 0)
		return (NULL);
	i = 1;
	while (str[i] != type)
		i++;
	i++;
	temp = (char *)malloc(i);
	ft_strlcat(temp, str++, 2);
	while (*str != type)
		ft_strlcat(temp, str++, ft_strlen(temp) + 2);
	ft_strlcat(temp, str++, ft_strlen(temp) + 2);
	return (temp);
}

char	*strip_string_from_cmd(char *str)
{
	char	*temp;

	temp = NULL;
	while (*str)
	{
		if (*str == '\'')
		{
			temp = strip_quotes(str, temp, '\'');
			str += ft_strlen(temp);
		}
		if (*str == '"')
		{
			temp = strip_quotes(str, temp, '"');
			str += ft_strlen(temp);
		}
		str++;
	}
	return temp;
}

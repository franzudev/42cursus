#include <stdlib.h>

char *ft_strdup(char *src)
{
	int i;
	char *str;

	i = 0;
	while (src[i++]);
	str = (char *) malloc(sizeof(char) * i);
	if (str == NULL)
		return 0;
	i = 0;
	while (src[i] != '\0')
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	
	return (str);
}
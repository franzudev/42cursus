#include <stdlib.h>
#include <stdio.h>

char **ft_split(char *str, char *charset)
{
	char **res;
	int w;
	int i;
	int len;

	i = 0;
	w = 1;
	len = 0;
	while (str[i])
	{
		if ((str[i] == *charset && str[i + 1] != *charset && str[i + 1] != '\0') || (str[i] != *charset && i == 0))
			w++;
		i++;
	}
	i = 0;
	res = (char **)malloc(sizeof(char **) * w);
	w = 0;
	while (str[i])
	{
		if (str[i] != *charset)
			len++;
		if ((str[i + 1] == *charset || str[i + 1] == '\0') && len > 0)
		{
			res[w++] = (char *)malloc(sizeof(char *) * (len + 1));
			len = 0;
		}
		i++;
	}
	i = 0;
	w = 0;
	int a = 0;
	while (str[i])
	{
		if (str[i] != *charset)
			res[w][a++] = str[i];
		if ((str[i + 1] == *charset || str[i + 1] == '\0') && a > 0)
		{
			res[w++][a] = '\0';
			a = 0;
		}
		i++;
	}
	res[w] = "\0";

	return res;
}

int main(void)
{
    char *str = "||stiamn fafjdfk|jòa<.|.asdfjelfj|o|andando|al||mare||adfad";
	char **res = ft_split(str, "a");
	int i = 0;
	while (res[i][0] != '\0')
		printf("%s\n", res[i++]);
	return 0;
}
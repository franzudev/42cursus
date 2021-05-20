#include <iostream>
#include <cstring>

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return 0;
	}
	char *str;
	int i = 0, j = 1, k;
	while (argv[j])
	{
		k = 0;
		while (argv[j][k])
			k++;
		i += k;
		j++;
	}
	str = (char *)malloc(i);
	j = 1;
	i = 0;
	while (argv[j])
	{
		k = 0;
		while (argv[j][k])
		{
			if (argv[j][k] >= 'a' && argv[j][k] <= 'z')
				str[i++] = argv[j][k] - 32;
			else
				str[i++] = argv[j][k];
			k++;
		}
		j++;
	}
	std::cout << str << "\n";
	while (*str)
		*(str++) = 0;
	return 0;
}

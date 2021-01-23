#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t l;

	l = 0;
	while (s[l] != 0)
		l++;
	return (l);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size;
	char	*res;
	int		i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	size = ft_strlen(s1) + ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * size);
	if (!res)
		return (0);
	while (*s1)
		res[i++] = *(s1++);
	while (*s2)
		res[i++] = *(s2++);
	res[i] = 0;
	return (res);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	size;
	size_t	i;

	size = ft_strlen(s1) + 1;
	if (!(s2 = (char *)malloc(size)))
		return (0);
	i = 0;
	while (i < size)
	{
		((unsigned char *)s2)[i] = ((unsigned char *)s1)[i];
		i++;
	}
	return (s2);
}

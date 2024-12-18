#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int *ints;
	int size;
	int i;

	if (min >= max)
		return (0);

	i = 0;
	size = max - min;
	ints = (int *) malloc(sizeof(int) * size);
	while (i < size)
		ints[i++] = min++;
	ints[i] = '\0';
	return (ints);
}

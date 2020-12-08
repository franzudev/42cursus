#include <stdlib.h>
#include <stdio.h>

int 	*ft_range(int min, int max)
{
	int *ints;
	int size;
	int i;

	if (min >= max)
		return (ints);

	i = 0;
	size = max - min;
	ints = (int *) malloc(sizeof(int) * size);
	while (i < size)
		ints[i++] = min++;
	ints[i] = '\0';
	return (ints);
}

int main()
{
	int *res = ft_range(1, 2147483647);

	while (*res)
		printf("%d\n", *res++);
	return 0;
}
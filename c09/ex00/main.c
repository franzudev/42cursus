#include <stdio.h>
#include "libft.h"

int main(void)
{
	int a = 1;
	int b = 5;
	int *pa = &a;
	int *pb = &b;
	char *str = "torone";
	char *cmp = "torane";

	ft_putstr(str);
	printf("a: %d \nb: %d\n", a, b);
	ft_swap(pa, pb);
	printf("a: %d \nb: %d\n", a, b);
	printf("%d\n", ft_strlen(str));
	printf("%d", ft_strcmp(str, cmp));

	return 0;
}
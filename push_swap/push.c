#include "push_swap.h"

void	ft_push(int *dest, int *source, int *size_dest, int *size_source)
{
	int i;

	if (*size_source == 0)
		return ;
	i = *size_dest;
	while (i > 0)
	{
		dest[i] = dest[i - 1];
		i--;
	}
	dest[0] = source[0];
	i = 0;
	while (++i < *size_source)
		source[i - 1] = source[i];
	*size_source -= 1;
	*size_dest += 1;
}

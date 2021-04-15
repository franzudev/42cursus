void	ft_rotate(int *stack, int size)
{
	int i;
	int temp;

	if (size == 0)
		return ;
	i = 0;
	temp = stack[0];
	while (i < size - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[i] = temp;
}
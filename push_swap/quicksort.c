#include<stdio.h>
#define MAX 100

void ft_quicksort(int *a,int primo,int ultimo)
{
	int	i;
	int	j;
	int	pivot;
	int	temp;

	if (primo < ultimo)
	{
		pivot = primo;
		i = primo;
		j = ultimo;
		while (i < j)
		{
			while (a[i] <= a[pivot] && i < ultimo)
				i++;
			while (a[j] > a[pivot])
				j--;
			if (i<j)
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
		temp = a[pivot];
		a[pivot] = a[j];
		a[j] = temp;
		ft_quicksort(a, primo, j - 1);
		ft_quicksort(a, j + 1, ultimo);
	}
}

// int main(){
// 	int n, a[MAX];
// 	n = insert_array(a);
// 	quicksort(a,0,n-1);
// 	return 0;
// }
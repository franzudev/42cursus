#include<stdio.h>
#include<unistd.h>

int board[20];
int count;

int ft_abs(int value)
{
	if (value <= 0)
        return value * -1;
    return value * 1;
}


int arrange(int row,int column)
{
	int i;

	i = 1;
	while (i < row)
	{
		if (board[i] == column)
			return 0;
		else
			if (ft_abs(board[i] - column) == ft_abs(i - row))
				return 0;
		i++;
	}
	return 1;
}

void	print(int n)
{
	int i;
	int j;
	char a;
	++count;

	i = 1;
	while (i <= n)
	{
		j = 1;
		while (j <= n)
		{
			if(board[i]==j)
			{
				a = i;
				write(1, (board[i] - 1 - '0') , 1);
				// printf("%d", board[i] - 1);
			}
			j++;
		}
		i++;
	}
}

void	queen(int row)
{
	int column;

	column = 1;
	while (column <= 10)
	{
		if (arrange(row,column))
		{
			board[row] = column; 
			if (row == 10)
			{
				print(10);
				printf("\n");
			}
			else
				queen(row + 1);
		}
		column++;
	}
}

int ft_ten_queens_puzzle(void)
{
	queen(1);
	return count;
}

int main()
{
	printf("%d", ft_ten_queens_puzzle());
	return (0);
}
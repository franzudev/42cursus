#include<stdio.h>
#include<unistd.h>

int ft_abs(int value)
{
	if (value <= 0)
        return value * -1;
    return value * 1;
}


int can_stay_here(int row,int column, int *board)
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

void	print(int n, int *board, int *count)
{
	int i;
	int j;
	char res;

	*count += 1;
	i = 1;
	while (i <= n)
	{
		j = 1;
		while (j <= n)
		{
			if (board[i] == j)
			{
				res = (board[i] - 1) % 10 + '0';
				write(1, &res, sizeof(char));
			}
			j++;
		}
		i++;
	}
}

void	ten_queens(int row, int *board, int *count)
{
	int column;

	column = 1;
	while (column <= 10)
	{
		if (can_stay_here(row, column, board))
		{
			board[row] = column; 
			if (row == 10)
			{
				print(10, board, count);
				// printf("\n");
				write(1, "\n", 1);
			}
			else
				ten_queens(row + 1, board, count);
		}
		column++;
	}
}

int ft_ten_queens_puzzle(void)
{
	int board[11];
	int count;

	count = 0;
	ten_queens(1, board, &count);
	return count;
}

int main()
{
	int count = ft_ten_queens_puzzle();
	printf("%d", count);
	return (0);
}
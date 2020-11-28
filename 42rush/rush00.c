#include "ft_putchar.c"

void	rush(int x, int y)
{
	int row;
	int col;

	row = 1;
	while(row <= y)
	{
		col = 1;
		while (col <= x)
		{
			if ((row == 1 && col == 1) || (row == y && col == x))
				ft_putchar('o');
			else if ((row == 1 && col == x) || (row == y && col == 1))
				ft_putchar('o');
			else if (col == 1 || col == x)
				ft_putchar('|');
			else if (row == 1 || row == y)
				ft_putchar('-');
			else
				ft_putchar(' ');
			col++;
		}
		ft_putchar('\n');
		row++;
	}
}

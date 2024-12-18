#include <stdlib.h>
#include <stdio.h>

void fill_arrays(int board[], char *argv, int size)
{
	int i;
	int j;

	i = 1;
	j = size - 8;
	while (i < 5)
	{
		board[i++] = argv[j] - '0';
		j += 2;
	}
	j = 0;

}

int is_tallest(int x, int y)
{
	if (x == 1 || y == 1)
	{
		return (1);
	}
	return (0);
}

int is_scale(int x, int y)
{
	if (x == 1 && y == 4)
	{
		return (2);
	}
	if (x == 4 && y == 1)
	{
		return (1);
	}
	return (0);
}

void create_board_constrained(int board[6][6], char *argv)
{
	int y;
	int x;

	y = 1;
	x = 0;
	while (x < 32)
	{
		if (x < 8)
			board[0][y++] = argv[x];
		y = 1;
		if (x < 16)
			board[5][y++] = argv[x];
		y = 1;
		if (x < 24)
			board[y++][0] = argv[x];
		y = 1;
		if (x < 32)
			board[y++][5] = argv[x];
		
	}
}

void write_scale_or_tallest(int *x, int *y, int board[4][4], int flag)
{
	int i = 0;
	int g = 0;
	int j = 0;
	int cnd = 0;
	while (i < 4)
	{
		cnd = is_scale(x[i], y[i]);
		if (cnd && flag)
		{
			while (g < 4)
			{
				if (cnd == 2)
				{
					board[3 - g][i] = j + 1;
				}
				else if (cnd == 1)
				{
					board[g][i] = j + 1;
				}
				j++;
				g++;
			}
			j = 0;
		} 
		else if (cnd && !flag)
		{
			while (g < 4)
			{
				if (cnd == 2)
				{
					board[i][3 - g] = j + 1;
				}
				else if (cnd == 1)
				{
					board[i][g] = j + 1;
				}
				j++;
				g++;
			}
			j = 0;
		}
		i++;
	}
}

void fill_constraint(int board[6][6], char *argv)
{
	
	fill_arrays(board[0],argv, 8);
	fill_arrays(board[0],argv, 16);
}

int get_param_len(char *argv)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (argv[i])
		len++;
	return (len);

}


int main(int argc, char *argv[])
{
	int x;
	int y;
	int board[6][6];
	int params_len;

	if (argc != 2)
	{
		return (1);
	}
	x = 0;
	y = 0;
	params_len = get_param_len(argv[1]);

	create_board_constrained(board, argv[1]);
	//write_scale_or_tallest(up, down, board, 1);
	//write_scale_or_tallest(left, right, board, 0);
	//fill_board(up)

	int counter = 0;
	int counter2 = 0;

	while(counter < 6)
	{
		while(counter2 < 6)
		{
			printf("%d ", board[counter][counter2]);
			counter2++;
		}
		printf("\n");
		counter2 = 0;
		counter++;
	}
}
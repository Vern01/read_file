#include "fdf.h"
#include <stdio.h>

void	print_iarray(int **array)
{
	int		x;
	int		y;

	y = -1;
	while (array[++y][0] != -1)
	{
		x = 0;
		while (array[y][x] != -1)
			ft_putnbr(array[y][x++]);
		ft_putstr("\n");
	}
}

void	free_iarray(int ***iarray)
{
	int		**temp;
	int		y;

	temp = *iarray;
	y = -1;
	while (temp[++y][0] != -1)
		free(temp[y]);
	free(temp[y]);
	free(*iarray);
}

int		main(int argc, char *argv[])
{
	int		**iarray;

	if (argc == 1)
		return (write(1, "Please give a file name:\n", 25));
	iarray = read_file(argv[1]);
	print_iarray(iarray);
	free_iarray(&iarray);
}
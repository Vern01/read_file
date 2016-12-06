#include "fdf.h"

void	print_iarray(int **array)
{
	int		x;
	int		y;

	y = -1;
	while (array[++y] != -1)
	{
		x = 0;
		while (array[y][x] != -1)
			ft_putnbr(array[y][x++]);
		ft_putstr("\n");
	}
}

int		main(int argc, char *argv[])
{
	int		**iarray;

	if (argc == 1)
		return (write(1, "Please give a file name:\n", 25));
	iarray = read_file(argv[1]);
	print_iarray(iarray);
}
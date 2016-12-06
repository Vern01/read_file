#include <fdf.h>
#include <stdio.h>

void	realloc_array(int ***iarray, int iarray_size)
{
	int		**new;
	int		**temp;
	int		y;

	if (!(new = (int **)malloc(sizeof(int *) * (iarray_size + 2))))
		exit(0);
	temp = *iarray;
	y = -1;
	while (++y < iarray_size)
		new[y] = temp[y];
	if (iarray_size != 0)
	{
		free(temp[y]);
		free(temp);
	}
	if (!(new[y + 1] = (int *)malloc(sizeof(int))))
		exit(0);
	new[y + 1][0] = -1;
	*iarray = new;
}

int		array_size(char **array)
{
	int		count;

	count = 0;
	while (*array++)
		count++;
	return (count);
}

int		*add_row(char **array)
{
	int		*iarray;
	int		x;

	if (!(iarray = (int *)malloc(sizeof(int) * (array_size(array) + 1))))
		exit(0);
	x = -1; 
	while (array[++x])
		iarray[x] = ft_atoi(array[x]);
	iarray[x] = -1;
	return (iarray);
}

void	add_to_array(char **array, int ***iarray, int iarray_size)
{
	int		**temp;

	realloc_array(iarray, iarray_size);
	temp = *iarray;
	temp[iarray_size] = add_row(array);
}
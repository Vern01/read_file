#include "fdf.h"

void	free_array(char ***array)
{
	char	**temp;

	temp = *array;
	while (*temp)
		free(*temp++);
	free(*array);
}

int		**read_file(char *s)
{
	int			fd;
	int			count;
	int			**iarray;
	char		*line;
	char		**array;

	fd = open(s, O_RDONLY);
	count = 0;
	while (get_next_line(fd, &line))
	{
		array = ft_strsplit(line, ' ');
		add_to_array(array, &iarray, count++);
		free_array(&array);
		free(line);
	}
	return (iarray);
}
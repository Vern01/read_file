#ifndef FDF_H
# define FDF_H
# include <fcntl.h>
# include <unistd.h>
# include <get_next_line.h>
# include <libft.h>

int		**read_file(char *s);
void    add_to_array(char **array, int ***iarray, int iarray_size);

#endif
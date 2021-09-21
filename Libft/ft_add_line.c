# include "libft.h"
#include <stdio.h>

char		**ft_add_line(char **mat, char *line)
{
	int		matlen;
	char	**new_mat;
	int		count;

	matlen = ft_matlen(mat);
	new_mat = malloc(sizeof(char *) * (matlen + 2));
	count = 0;
	while (mat[count])
	{
		new_mat[count] = ft_strdup(mat[count]);
		if (!new_mat[count])
			return (0);
		count++;
	}
	new_mat[count] = ft_strdup(line);
	if (!new_mat[count++])
		return (0);
	new_mat[count] = 0;
	return (new_mat);
}

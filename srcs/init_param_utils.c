#include "fdf.h"

char	*ft_strdup_fdf(const char *s1)
{
	size_t			s1_len;
	unsigned char	*dst;
	unsigned int	len;
	int				count;

	s1_len = ft_strlen(s1);
	if (s1_len == 1)
		s1_len++;
	else
		s1_len = (s1_len / 2) + 2;
	len = s1_len;
	dst = malloc(sizeof(char) * s1_len);
	if (!dst)
		return (NULL);
	count = 0;
	while (*s1)
	{
		if (*s1 != 32)
			dst[count++] = *s1;
		s1++;
	}
	dst[count] = 0;
	return ((char *)dst);
}

char	**ft_add_line_fdf(char **mat, char *line)
{
	int		matlen;
	char	**new_mat;
	int		count;

	matlen = ft_matlen(mat);
	new_mat = malloc(sizeof(char *) * (matlen + 2));
	if (!new_mat)
		return (0);
	count = 0;
	while (matlen--)
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
	free_matc(mat);
	return (new_mat);
}

int	get_map_ready(t_map *map)
{
	map->data = malloc(sizeof(char *));
	if (!map->data)
		return (0);
	map->data[0] = 0;
	map->height = 0;
	map->max_width = 0;
	return (1);
}

void	increase_params(int *count, t_map *map)
{
	if (map->max_width < ft_digitlen_in_str(map->data[*count]))
		map->max_width = ft_digitlen_in_str(map->data[*count]);
	*count += 1;
	map->height++;
}

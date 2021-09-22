#include "fdf.h"

char	*ft_strdup_fdf(const char *s1)
{
	size_t			s1_len;
	unsigned char	*dst;
	unsigned int	len;
	int			count;

	s1_len = ft_strlen(s1);
	if (s1_len == 1)
		s1_len++;
	else
		s1_len = (s1_len / 2) + 2;
	len = s1_len;
	if (!(dst = malloc(sizeof(char) * s1_len)))
		return (NULL);
	count = 0;
	while (*s1)
	{
		if (*s1 != 32)
			dst[count++] = *s1;
		s1++;
	}
	return ((char *)dst);
}

char		**ft_add_line_fdf(char **mat, char *line)
{
	int		matlen;
	char	**new_mat;
	int		count;

	matlen = ft_matlen(mat);
	new_mat = malloc(sizeof(char *) * (matlen + 2));
	count = 0;
	while (mat[count])
	{
		new_mat[count] = ft_strdup_fdf(mat[count]);
		if (!new_mat[count])
			return (0);
		count++;
	}
	new_mat[count] = ft_strdup_fdf(line);
	if (!new_mat[count++])
		return (0);
	new_mat[count] = 0;
	return (new_mat);
}

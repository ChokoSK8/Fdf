#include "fdf.h"

int		init_map(t_map *map, char *file)
{
	t_point		pt;
	int			fd;
	char		c;
	int			ret;
	int			count;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	ret = read(fd, &c, 1);
	count = -1;
	pt.x = 0;
	pt.y = 0;
	while (ret)
	{
		count *= -1;
		if (count > 0 && ft_isdigit(c))
			map->data[pt.x][pt.y] = c;



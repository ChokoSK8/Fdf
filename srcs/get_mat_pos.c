#include "fdf.h"

t_ptdouble	**get_mat_pos(t_map map)
{
	t_point		pt;
	t_ptdouble	**mat;

	mat = malloc(sizeof(t_ptdouble *) * (map.height + 1));
	if (!mat)
		return (0);
	pt.y = 0;
	while (map.mati[pt.y])
	{
		mat[pt.y] = malloc(sizeof(t_ptdouble) * (map.max_width + 1));
		if (!mat[pt.y])
			return (0);
		pt.x = 0;
		while (pt.x < (int)map.max_width)
		{
			mat[pt.y][pt.x].x = pt.x - 0.04 * (map.mati[pt.y][pt.x]);
			mat[pt.y][pt.x].y = pt.y - 0.04 * (map.mati[pt.y][pt.x]);
			pt.x++;
		}
		mat[pt.y][pt.x].x = -1;
		pt.y++;
	}
	mat[pt.y] = 0;
	return (mat);
}

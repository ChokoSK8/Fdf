#include "fdf.h"

void	print_mat_pos(t_ptdouble **mat)
{
	t_point		pt;

	pt.y = 0;
	while (mat[pt.y])
	{
		pt.x = 0;
		while (mat[pt.y][pt.x].x != -1)
		{
			printf("mat[%d][%d] : (%f, %f)\n", pt.y, pt.x, mat[pt.y][pt.x].x, mat[pt.y][pt.x].y);
			pt.x++;
		}
		pt.y++;
	}
}

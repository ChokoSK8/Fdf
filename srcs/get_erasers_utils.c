#include "fdf.h"

t_vect		get_vect_from_line(t_line line)
{
	t_vect	vect;

	vect.x = 1 / line.a;
	if (vect.x < 0)
	{
		vect.x *= -1;
		vect.y = -1;
	}
	else
		vect.y = 1;
	return (vect);
}

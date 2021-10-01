#include "fdf.h"

t_apex		get_apex_of_diamonds(t_apex apex, t_display disp)
{
	apex.a = get_apex(disp, apex.a);
	apex.b = get_apex(disp, apex.b);
	apex.c = get_apex(disp, apex.c);
	apex.d = get_apex(disp, apex.d);
	return (apex);
}

t_ptdouble		get_apex(t_display disp, t_ptdouble pt)
{
	t_ptdouble	pt_a;

	pt_a.x = disp.origin.x + pt.x * disp.vect_x.x + pt.y * disp.vect_y.x;
	pt_a.y = disp.origin.y + pt.x * disp.vect_x.y + pt.y * disp.vect_y.y;
	return (pt_a);
}

void		display_line(t_ptdouble apex_a, t_ptdouble apex_b, int size_line, t_img *img)
{
	t_vect		vect;
	t_ptdouble	count;
	double		dist;
	int		pos;

	dist = get_dist_btw_2_pts(apex_a, apex_b);
	count.x = apex_a.x;
	count.y = apex_a.y;
	vect = get_vect_btw_2_pts(apex_a, apex_b);
	while (get_dist_btw_2_pts(count, apex_a) < dist)
	{
		pos = ((int)count.x * 4 + size_line * (int)count.y);
		img->data[pos] = 100;
		img->data[pos + 1] = 50;
		img->data[pos + 2] = 90;
		count = get_next_ptdouble(count, vect);
	}
}

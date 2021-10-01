#include "fdf.h"

t_ptdouble	get_pt_perp(t_lines lines, t_ptdouble pt, t_line eraser, t_apex apex)
{
	t_param_perp		l_tmp;
	t_line				l_perp;
	t_ptdouble			pt_1;
	t_ptdouble			pt_2;
	t_ptdouble			pt_3;
	t_ptdouble			none;
	double				dist_1;
	double				dist_2;
	double				dist_3;

	pt_1.x = 0;
	l_tmp = get_l_tmp(lines, eraser, apex);
	l_perp.a = (-1) / eraser.a;
	l_perp.b = pt.y - pt.x * l_perp.a;
	pt_1.x = (l_perp.b - l_tmp.ab.b) / (l_tmp.ab.a - l_perp.a);
	pt_1.y = pt_1.x * l_perp.a + l_perp.b;
	pt_2.x = (l_perp.b - l_tmp.bd.b) / (l_tmp.bd.a - l_perp.a);
	pt_2.y = pt_2.x * l_perp.a + l_perp.b;
	pt_3.x = (l_perp.b - l_tmp.ac.b) / (l_tmp.ac.a - l_perp.a);
	pt_3.y = pt_3.x * l_perp.a + l_perp.b;
	dist_1 = get_dist_btw_2_pts(pt_1, pt);
	dist_2 = get_dist_btw_2_pts(pt_2, pt);
	dist_3 = get_dist_btw_2_pts(pt_3, pt);
	if (is_pt_between_x(l_tmp.ab.x_1, pt_1.x, l_tmp.ab.x_2)
		&& (!is_pt_between_x(l_tmp.bd.x_1, pt_2.x, l_tmp.bd.x_2) ||(dist_1 <= dist_2))
			&& (!is_pt_between_x(l_tmp.ac.x_1, pt_3.x, l_tmp.ac.x_2) ||(dist_1 <= dist_3)))
				return (pt_1);
	if (is_pt_between_x(l_tmp.bd.x_1, pt_2.x, l_tmp.bd.x_2))
		if ((!is_pt_between_x(l_tmp.ab.x_1, pt_1.x, l_tmp.ab.x_2)) ||(dist_2 <= dist_1))
			if ((!is_pt_between_x(l_tmp.ac.x_1, pt_3.x, l_tmp.ac.x_2)) ||(dist_2 <= dist_3))
				return (pt_2);
	if (is_pt_between_x(l_tmp.ac.x_1, pt_3.x, l_tmp.ac.x_2))
		if ((!is_pt_between_x(l_tmp.ab.x_1, pt_1.x, l_tmp.ab.x_2)) ||(dist_3 <= dist_1))
			if ((!is_pt_between_x(l_tmp.bd.x_1, pt_2.x, l_tmp.bd.x_2)) ||(dist_3 <= dist_2))
				return (pt_3);
	none.x = 0;
	none.y = 0;
	return (none);
}

double		get_dist_min(double dist_1, double dist_2, double dist_3)
{
	double dist_min;

	dist_min = dist_1;
	if (dist_min > dist_2)
		dist_min = dist_2;
	if (dist_min > dist_3)
		dsit_min = dist_3;
	return (dist_min);
}

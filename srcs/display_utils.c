#include "fdf.h"

t_vect		get_vect_btw_2_pts(t_ptdouble pt_a, t_ptdouble pt_b)
{
	t_vect		vect;

	vect.x = pt_b.x - pt_a.x;
	vect.y = pt_b.y - pt_a.y;
	return (vect);
}

double			convert(double degre)
{
	double rad;

	rad = degre / 57.2958;
	return (rad);
}

double			convert_inv(double rad)
{
	double degre;

	degre = 57.2958 * rad;
	return (degre);
}

double		get_dist_btw_2_pts(t_ptdouble pt_a, t_ptdouble pt_b)
{
	double		dist;

	dist = sqrt(pow(pt_a.x - pt_b.x, 2) + pow(pt_a.y - pt_b.y, 2));
	return (dist);
}

t_ptdouble	apply_vect(t_ptdouble pt, t_vect vect, double len)
{
	pt.x += (len * vect.x);
	pt.y += (len * vect.y);
	return (pt);
}

void		print_apex(t_apex apex)
{
	printf("apex.a : (%f, %f)\n", apex.a.x, apex.a.y);
	printf("apex.b : (%f, %f)\n", apex.b.x, apex.b.y);
	printf("apex.c : (%f, %f)\n", apex.c.x, apex.c.y);
	printf("apex.d : (%f, %f)\n", apex.d.x, apex.d.y);
}

int		is_pts_equal(t_ptdouble pt_a, t_ptdouble pt_b)
{
	if (((int)pt_a.x != (int)pt_b.x &&
				(pt_a.y - pt_b.y > 0.2 || pt_a.y - pt_b.y < -0.2)) || 
				((int)pt_a.y != (int)pt_b.y && 
				(pt_a.x - pt_b.x > 0.2 || pt_a.x - pt_b.x < -0.2)))
		return (0);
	return (1);
}

t_lines		get_eq_lines(t_apex apex)
{
	t_lines		lines;

	lines.ac.a = (apex.a.y - apex.c.y) / (apex.a.x - apex.c.x);
	lines.ac.b = apex.a.y - lines.ac.a * apex.a.x;
	lines.ab.a = (apex.a.y - apex.b.y) / (apex.a.x - apex.b.x);
	lines.ab.b = apex.a.y - lines.ab.a * apex.a.x;
	lines.bd.a = (apex.b.y - apex.d.y) / (apex.b.x - apex.d.x);
	lines.bd.b = apex.b.y - lines.bd.a * apex.b.x;
	lines.cd.a = (apex.d.y - apex.c.y) / (apex.d.x - apex.c.x);
	lines.cd.b = apex.c.y - lines.cd.a * apex.c.x;
	return (lines);
}

t_ptdouble	get_pt_perp(t_lines lines, t_ptdouble pt, t_line eraser, t_apex apex)
{
	t_param_perp		l_tmp;
	t_line				l_perp;
	t_ptdouble			pt_1;
	t_ptdouble			pt_2;
	t_ptdouble			pt_3;
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
	t_ptdouble none;
	none.x = 0;
	none.y = 0;
	return (none);
}

int		is_pt_between_x(double x_a, double x_b, double x_c)
{
	double		dist_ab;
	double		dist_bc;
	double		dist_ac;

	dist_ab = x_b - x_a;
	dist_bc = x_c - x_b;
	dist_ac = x_c - x_a;
	if (dist_ab < dist_ac && dist_bc < dist_ac)
		return (1);
	return (0);
}

t_param_perp		get_l_tmp(t_lines lines, t_line eraser, t_apex apex)
{
	t_param_perp	l_tmp;

	if (is_line_equal_to_eraser(lines.ab, eraser))
	{
		l_tmp.ab.a = lines.ac.a;
		l_tmp.ab.b = lines.ac.b;
		if (apex.a.x < apex.c.x)
		{
			l_tmp.ab.x_1 = apex.a.x;
			l_tmp.ab.x_2 = apex.c.x;
		}
		else
		{
			l_tmp.ab.x_1 = apex.c.x;
			l_tmp.ab.x_2 = apex.a.x;
		}

		l_tmp.ac.a = lines.bd.a;
		l_tmp.ac.b = lines.bd.b;
		if (apex.b.x < apex.d.x)
		{
			l_tmp.ac.x_1 = apex.b.x;
			l_tmp.ac.x_2 = apex.d.x;
		}
		else
		{
			l_tmp.ac.x_1 = apex.d.x;
			l_tmp.ac.x_2 = apex.b.x;
		}

		l_tmp.bd.a = lines.cd.a;
		l_tmp.bd.b = lines.cd.b;
		if (apex.c.x < apex.d.x)
		{
			l_tmp.bd.x_1 = apex.c.x;
			l_tmp.bd.x_2 = apex.d.x;
		}
		else
		{
			l_tmp.bd.x_1 = apex.d.x;
			l_tmp.bd.x_2 = apex.c.x;
		}
	}
	if (is_line_equal_to_eraser(lines.cd, eraser))
	{
		l_tmp.ab.a = lines.ac.a;
		l_tmp.ab.b = lines.ac.b;
		if (apex.a.x < apex.c.x)
		{
			l_tmp.ab.x_1 = apex.a.x;
			l_tmp.ab.x_2 = apex.c.x;
		}
		else
		{
			l_tmp.ab.x_1 = apex.c.x;
			l_tmp.ab.x_2 = apex.a.x;
		}

		l_tmp.ac.a = lines.bd.a;
		l_tmp.ac.b = lines.bd.b;
		if (apex.b.x < apex.d.x)
		{
			l_tmp.ac.x_1 = apex.b.x;
			l_tmp.ac.x_2 = apex.d.x;
		}
		else
		{
			l_tmp.ac.x_1 = apex.d.x;
			l_tmp.ac.x_2 = apex.b.x;
		}

		l_tmp.bd.a = lines.ab.a;
		l_tmp.bd.b = lines.ab.b;
		if (apex.a.x < apex.b.x)
		{
			l_tmp.bd.x_1 = apex.a.x;
			l_tmp.bd.x_2 = apex.b.x;
		}
		else
		{
			l_tmp.bd.x_1 = apex.b.x;
			l_tmp.bd.x_2 = apex.a.x;
		}
	}
	if (is_line_equal_to_eraser(lines.bd, eraser))
	{
		l_tmp.ab.a = lines.ac.a;
		l_tmp.ab.b = lines.ac.b;
		if (apex.a.x < apex.c.x)
		{
			l_tmp.ab.x_1 = apex.a.x;
			l_tmp.ab.x_2 = apex.c.x;
		}
		else
		{
			l_tmp.ab.x_1 = apex.c.x;
			l_tmp.ab.x_2 = apex.a.x;
		}

		l_tmp.ac.a = lines.ab.a;
		l_tmp.ac.b = lines.ab.b;
		if (apex.a.x < apex.b.x)
		{
			l_tmp.ac.x_1 = apex.a.x;
			l_tmp.ac.x_2 = apex.b.x;
		}
		else
		{
			l_tmp.ac.x_1 = apex.b.x;
			l_tmp.ac.x_2 = apex.a.x;
		}

		l_tmp.bd.a = lines.cd.a;
		l_tmp.bd.b = lines.cd.b;
		if (apex.c.x < apex.d.x)
		{
			l_tmp.bd.x_1 = apex.c.x;
			l_tmp.bd.x_2 = apex.d.x;
		}
		else
		{
			l_tmp.bd.x_1 = apex.c.x;
			l_tmp.bd.x_2 = apex.d.x;
		}
	}
	if (is_line_equal_to_eraser(lines.ac, eraser))
	{
		l_tmp.ab.a = lines.ab.a;
		l_tmp.ab.b = lines.ab.b;
		if (apex.a.x < apex.b.x)
		{
			l_tmp.ab.x_1 = apex.a.x;
			l_tmp.ab.x_2 = apex.b.x;
		}
		else
		{
			l_tmp.ab.x_1 = apex.b.x;
			l_tmp.ab.x_2 = apex.a.x;
		}

		l_tmp.ac.a = lines.bd.a;
		l_tmp.ac.b = lines.bd.b;
		if (apex.b.x < apex.d.x)
		{
			l_tmp.ac.x_1 = apex.b.x;
			l_tmp.ac.x_2 = apex.d.x;
		}
		else
		{
			l_tmp.ac.x_1 = apex.d.x;
			l_tmp.ac.x_2 = apex.b.x;
		}

		l_tmp.bd.a = lines.cd.a;
		l_tmp.bd.b = lines.cd.b;
		if (apex.c.x < apex.d.x)
		{
			l_tmp.bd.x_1 = apex.c.x;
			l_tmp.bd.x_2 = apex.d.x;
		}
		else
		{
			l_tmp.bd.x_1 = apex.d.x;
			l_tmp.bd.x_2 = apex.c.x;
		}
	}
	return (l_tmp);
}

int		is_line_equal_to_eraser(t_line line, t_line eraser)
{
	if (line.a - eraser.a == 0 && line.b - eraser.b == 0)
		return (1);
	return (0);
}

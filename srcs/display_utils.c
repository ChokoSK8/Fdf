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

double		get_coefxy(int coef_x, int coef_y)
{
	double	dist;

	dist = sqrt(pow(coef_x, 2) + pow(coef_y, 2));
	return (dist);
}

void		print_apex(t_apex apex)
{
	printf("apex.a : (%f, %f)\n", apex.a.x, apex.a.y);
	printf("apex.b : (%f, %f)\n", apex.b.x, apex.b.y);
	printf("apex.c : (%f, %f)\n", apex.c.x, apex.c.y);
	printf("apex.d : (%f, %f)\n", apex.d.x, apex.d.y);
}

t_display		init_display(t_img img)
{
	t_display		disp;

	disp.origin.x = 500;
	disp.origin.y = 50;
	disp.angle = 45;
	disp.vect_x.x = cos(convert(disp.angle)) * img.coef_x;
	disp.vect_x.y = sin(convert(disp.angle)) * img.coef_x;
	disp.vect_y.x = -sin(convert(disp.angle)) * img.coef_y;
	disp.vect_y.y = cos(convert(disp.angle)) * img.coef_y;
	return (disp);
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
		count = apply_vect(count, vect, 0.0001);
	}
}	

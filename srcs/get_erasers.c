#include "fdf.h"

t_eraser	get_erasers(t_lines lines, t_apex apex)
{
	t_eraser	eraser;
	double		angle;
	double		tmp;

	angle = get_angle_from_pts(apex.c, apex.a, apex.b);
	eraser = init_eraser(lines.ac, lines.ab, apex, 1);
	tmp = get_angle_from_pts(apex.a, apex.b, apex.d);
	printf("angle A : %f\n", angle);
	if (angle < tmp)
	{
		eraser = init_eraser(lines.ab, lines.bd, apex, 2);
		angle = tmp;
	printf("angle B : %f\n", angle);
	}
	tmp = get_angle_from_pts(apex.b, apex.d, apex.c);
	if (angle < tmp)
	{
		eraser = init_eraser(lines.bd, lines.cd, apex, 3);
		angle = tmp;
	printf("angle D : %f\n", angle);
	}
	tmp = get_angle_from_pts(apex.d, apex.c, apex.a);
	if (angle < tmp)
	{
		eraser = init_eraser(lines.cd, lines.ac, apex, 4);
		angle = tmp;
	printf("angle C : %f\n", angle);
	}
	printf("angle : %f\n", angle);
	return (eraser);
}

double		get_angle_from_pts(t_ptdouble pt_a, t_ptdouble pt_b, t_ptdouble pt_c)
{
	double	angle;
	double	num;
	double	den;
	t_vect	vect_a;
	t_vect	vect_b;

	vect_a = get_vect_btw_2_pts(pt_a, pt_b);
	vect_b = get_vect_btw_2_pts(pt_b, pt_c);
//	printf("vect_a : (%f, %f)\n", vect_a.x, vect_a.y);
//	printf("vect_b : (%f, %f)\n", vect_b.x, vect_b.y);
	num = vect_a.x * vect_b.x + vect_a.y * vect_b.y;
	den = sqrt(pow(vect_a.x, 2) + pow(vect_a.y, 2)) * sqrt(pow(vect_b.x, 2) + pow(vect_b.y, 2));
//	printf("den : %f\n", den);
//	printf("num : %f\n", num);
	angle = 180 - convert_inv(acos(num / den));
	return (angle);
}

t_eraser	init_eraser(t_line line_a, t_line line_b, t_apex apex, int n)
{
	t_eraser	eraser;

	eraser.a = line_a;
	eraser.b = line_b;
	if (n == 1)
	{
		eraser.pt_a = apex.c;
		eraser.pt_c = apex.a;
		eraser.pt_d = apex.b;
	}
	if (n == 2)
	{
		eraser.pt_a = apex.a;
		eraser.pt_c = apex.b;
		eraser.pt_d = apex.d;
	}
	if (n == 3)
	{
		eraser.pt_a = apex.b;
		eraser.pt_c = apex.d;
		eraser.pt_d = apex.c;
	}
	if (n == 4)
	{
		eraser.pt_a = apex.d;
		eraser.pt_c = apex.c;
		eraser.pt_d = apex.a;
	}
	return (eraser);
}

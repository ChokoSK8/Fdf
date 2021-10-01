#include "fdf.h"

void	display_squares(t_img *img, t_ptdouble **mat_pos)
{
	t_point		pt;
	t_display	disp;

	disp = init_display(*img);
	pt.y = 0;
	while (mat_pos[pt.y])
	{
		pt.x = 0;
		while (mat_pos[pt.y][pt.x].x != -1)
		{
			print_diamonds(img, mat_pos, pt, disp);
			pt.x++;
		}
		pt.y++;
	}
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

void	print_diamonds(t_img *img, t_ptdouble **mat_pos,
		t_point pt, t_display disp)
{
	t_apex		apex;
	t_lines		lines;

	if (mat_pos[pt.y + 1] && mat_pos[pt.y][pt.x + 1].x != -1)
	{
		apex.a = mat_pos[pt.y][pt.x];
		apex.b = mat_pos[pt.y][pt.x + 1];
		apex.c = mat_pos[pt.y + 1][pt.x];
		apex.d = mat_pos[pt.y + 1][pt.x + 1];
		apex = get_apex_of_diamonds(apex, disp);
		if (!is_apex_equal(apex))
		{
			lines = get_eq_lines(apex);
			erase_inside(apex, lines, img);
			display_line(apex.a, apex.b, img->size_line, img);
			display_line(apex.b, apex.d, img->size_line, img);
			display_line(apex.a, apex.c, img->size_line, img);
			display_line(apex.c, apex.d, img->size_line, img);
		}
	}
}

int	is_ptdouble_equal(t_ptdouble pt_a, t_ptdouble pt_b)
{
	if (pt_a.x == pt_b.x && pt_a.y == pt_b.y)
		return (1);
	return (0);
}

int	is_apex_equal(t_apex apex)
{
	if (is_ptdouble_equal(apex.a, apex.b)
		&& is_ptdouble_equal(apex.a, apex.c)
		&& is_ptdouble_equal(apex.a, apex.d))
		return (1);
	return (0);
}

void	put_pixels(t_img *img, t_ptdouble pt)
{
	int	pos;

	pos = ((int)pt.x * 4 + img->size_line * (int)pt.y);
	img->data[pos] = 10;
	img->data[pos + 1] = 100;
	img->data[pos + 2] = 20;
}

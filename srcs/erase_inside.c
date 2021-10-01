#include "fdf.h"

void	erase_inside(t_apex apex, t_lines lines, t_img *img)
{
	t_eraser	eraser;

	eraser = init_eraser(apex.a, apex.c, lines.ac);
	erase_from_one_lign(eraser, lines, img, apex);
	eraser = init_eraser(apex.a, apex.b, lines.ab);
	erase_from_one_lign(eraser, lines, img, apex);
	eraser = init_eraser(apex.c, apex.d, lines.cd);
	erase_from_one_lign(eraser, lines, img, apex);
	eraser = init_eraser(apex.b, apex.d, lines.bd);
	erase_from_one_lign(eraser, lines, img, apex);
}

t_eraser	init_eraser(t_ptdouble pt_a, t_ptdouble pt_b, t_line line)
{
	t_eraser	eraser;

	eraser.pt_a = pt_a;
	eraser.pt_b = pt_b;
	eraser.line = line;
	return (eraser);
}

void	erase_from_one_lign(t_eraser eraser, t_lines lines,
		t_img *img, t_apex apex)
{
	t_ptdouble	tmp;
	t_dists		dist;
	t_vects		vect;
	t_ptdouble	count;
	t_ptdouble	perp;

	vect.v = get_vect_btw_2_pts(eraser.pt_a, eraser.pt_b);
	dist.v = get_dist_btw_2_pts(eraser.pt_a, eraser.pt_b);
	tmp = eraser.pt_a;
	while (get_dist_btw_2_pts(tmp, eraser.pt_a) < dist.v)
	{
		count = tmp;
		perp = get_pt_perp(lines, count, eraser.line, apex);
		vect.h = get_vect_btw_2_pts(count, perp);
		dist.h = get_dist_btw_2_pts(count, perp);
		if (is_perp_ok(perp) && !is_pts_equal(count, perp))
		{
			while (get_dist_btw_2_pts(tmp, count) < dist.h)
			{
				put_pixels(img, count);
				count = get_next_ptdouble(count, vect.h);
			}
		}
		tmp = get_next_ptdouble(tmp, vect.v);
	}
}

int	is_perp_ok(t_ptdouble perp)
{
	if (perp.x == 0 && perp.y == 0)
		return (0);
	return (1);
}

t_ptdouble	get_next_ptdouble(t_ptdouble pt, t_vect vect)
{
	t_ptdouble	witness;

	witness = pt;
	while ((int)pt.x == (int)witness.x
		&& (int)pt.y == (int)witness.y)
		pt = apply_vect(pt, vect, 0.0001);
	return (pt);
}

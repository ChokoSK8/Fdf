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

int		is_ptdouble_equal(t_ptdouble pt_a, t_ptdouble pt_b)
{
	if (pt_a.x == pt_b.x && pt_a.y == pt_b.y)
		return (1);
	return (0);
}

int		is_apex_equal(t_apex apex)
{
	if (is_ptdouble_equal(apex.a, apex.b) && is_ptdouble_equal(apex.a, apex.c) &&
			is_ptdouble_equal(apex.a, apex.d))
		return (1);
	return (0);
}

void	print_diamonds(t_img *img, t_ptdouble **mat_pos, t_point pt, t_display disp)
{
	t_apex		apex;
	t_lines		lines;

	if (mat_pos[pt.y + 1] && mat_pos[pt.y][pt.x + 1].x != -1)
	{
		printf("pt : (%d, %d)\n", pt.x, pt.y);
		apex.a = mat_pos[pt.y][pt.x];
		apex.b = mat_pos[pt.y][pt.x + 1];
		apex.c = mat_pos[pt.y + 1][pt.x];
		apex.d = mat_pos[pt.y + 1][pt.x + 1];
//		printf("pt_d : (%f, %f)\n", apex.d.x, apex.d.y);
		apex = get_apex_of_diamonds(apex, disp);
		if (!is_apex_equal(apex))
		{
//		if (pt.y == 2 && pt.x == 2)
//		{
		//	print_apex(apex);
			lines = get_eq_lines(apex);
			erase_inside(apex, lines, img);
//		}
			display_line(apex.a, apex.b, img->size_line, img);
			display_line(apex.b, apex.d, img->size_line, img);
			display_line(apex.a, apex.c, img->size_line, img);
			display_line(apex.c, apex.d, img->size_line, img);
		}
	}
}

void	erase_inside(t_apex apex, t_lines lines, t_img *img)
{
	t_ptdouble	perp;
	t_vect		vect_h;
	t_vect		vect_v;
	double		dist_h;
	double		dist_v;
	t_ptdouble	count;
	t_ptdouble	tmp;
	int		pos;
	t_ptdouble	witness;
	int		perp_ok;

	//FROM A TO C
	vect_v = get_vect_btw_2_pts(apex.a, apex.c);
	dist_v = get_dist_btw_2_pts(apex.a, apex.c);
	tmp = apex.a;
	witness = tmp;
	while (get_dist_btw_2_pts(tmp, apex.a) < dist_v)
	{
		count = tmp;
		perp_ok = 1;
		perp = get_pt_perp(lines, count, lines.ac, apex);
		if (perp.x == 0 && perp.y == 0)
			perp_ok = 0;
	//	printf("perp : (%f, %f)\n", perp.x, perp.y);
		vect_h = get_vect_btw_2_pts(count, perp);
		dist_h = get_dist_btw_2_pts(count, perp);
	//	printf("dist_h : %f\n", dist_h);
		if (perp_ok && !is_pts_equal(count, perp))
		{
			while (get_dist_btw_2_pts(tmp, count) < dist_h)
			{
				pos = ((int)count.x * 4 + img->size_line * (int)count.y);
				img->data[pos] = 0;
				img->data[pos + 1] = 0;
				img->data[pos + 2] = 0;
				witness = count;
				while ((int)count.x == (int)witness.x && 
						(int)count.y == (int)witness.y)
					count = apply_vect(count, vect_h, 0.0001);
			}
		}
		witness = tmp;
		while ((int)tmp.x == (int)witness.x && 
				(int)tmp.y == (int)witness.y)
			tmp = apply_vect(tmp, vect_v, 0.0001);
	}

	//FROM B TO D
	vect_v = get_vect_btw_2_pts(apex.b, apex.d);
	dist_v = get_dist_btw_2_pts(apex.d, apex.d);
	tmp = apex.b;
	witness = tmp;
	while (get_dist_btw_2_pts(tmp, apex.b) < dist_v)
	{
		count = tmp;
		perp_ok = 1;
		perp = get_pt_perp(lines, count, lines.bd, apex);
		if (perp.x == 0 && perp.y == 0)
			perp_ok = 0;
//		printf("perp : (%f, %f)\n", perp.x, perp.y);
		vect_h = get_vect_btw_2_pts(count, perp);
		dist_h = get_dist_btw_2_pts(count, perp);
	//	printf("dist_h : %f\n", dist_h);
		if (perp_ok && !is_pts_equal(count, perp))
		{
			while (get_dist_btw_2_pts(tmp, count) < dist_h)
			{
				pos = ((int)count.x * 4 + img->size_line * (int)count.y);
				img->data[pos] = 0;
				img->data[pos + 1] = 0;
				img->data[pos + 2] = 0;
				witness = count;
				while ((int)count.x == (int)witness.x && 
						(int)count.y == (int)witness.y)
					count = apply_vect(count, vect_h, 0.0001);
			}
		}
		witness = tmp;
		while ((int)tmp.x == (int)witness.x && 
				(int)tmp.y == (int)witness.y)
			tmp = apply_vect(tmp, vect_v, 0.0001);
	}

	//FROM A TO B
	vect_v = get_vect_btw_2_pts(apex.a, apex.b);
	dist_v = get_dist_btw_2_pts(apex.a, apex.b);
	tmp = apex.a;
	witness = tmp;
	while (get_dist_btw_2_pts(tmp, apex.a) < dist_v)
	{
		count = tmp;
		perp_ok = 1;
		perp = get_pt_perp(lines, count, lines.ab, apex);
		if (perp.x == 0 && perp.y == 0)
			perp_ok = 0;
	//	printf("perp : (%f, %f)\n", perp.x, perp.y);
		vect_h = get_vect_btw_2_pts(count, perp);
		dist_h = get_dist_btw_2_pts(count, perp);
	//	printf("dist_h : %f\n", dist_h);
		if (perp_ok && !is_pts_equal(count, perp))
		{
			while (get_dist_btw_2_pts(tmp, count) < dist_h)
			{
				pos = ((int)count.x * 4 + img->size_line * (int)count.y);
				img->data[pos] = 0;
				img->data[pos + 1] = 0;
				img->data[pos + 2] = 0;
				witness = count;
				while ((int)count.x == (int)witness.x && 
						(int)count.y == (int)witness.y)
					count = apply_vect(count, vect_h, 0.0001);
			}
		}
		witness = tmp;
		while ((int)tmp.x == (int)witness.x && 
				(int)tmp.y == (int)witness.y)
			tmp = apply_vect(tmp, vect_v, 0.0001);
	}

	//FROM C TO D
	vect_v = get_vect_btw_2_pts(apex.c, apex.d);
	dist_v = get_dist_btw_2_pts(apex.c, apex.d);
	tmp = apex.c;
	witness = tmp;
	while (get_dist_btw_2_pts(tmp, apex.c) < dist_v)
	{
		count = tmp;
		perp_ok = 1;
		perp = get_pt_perp(lines, count, lines.cd, apex);
		if (perp.x == 0 && perp.y == 0)
			perp_ok = 0;
	//	printf("perp : (%f, %f)\n", perp.x, perp.y);
		vect_h = get_vect_btw_2_pts(count, perp);
		dist_h = get_dist_btw_2_pts(count, perp);
	//	printf("dist_h : %f\n", dist_h);
		if (perp_ok && !is_pts_equal(count, perp))
		{
			while (get_dist_btw_2_pts(tmp, count) < dist_h)
			{
				pos = ((int)count.x * 4 + img->size_line * (int)count.y);
				img->data[pos] = 0;
				img->data[pos + 1] = 0;
				img->data[pos + 2] = 0;
				witness = count;
				while ((int)count.x == (int)witness.x && 
						(int)count.y == (int)witness.y)
					count = apply_vect(count, vect_h, 0.0001);
			}
		}
		witness = tmp;
		while ((int)tmp.x == (int)witness.x && 
				(int)tmp.y == (int)witness.y)
			tmp = apply_vect(tmp, vect_v, 0.0001);
	}
}

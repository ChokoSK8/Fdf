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

void	print_diamonds(t_img *img, t_ptdouble **mat_pos, t_point pt, t_display disp)
{
	t_apex		apex;
//	t_eraser	eraser;
//	t_lines		lines;

	if (mat_pos[pt.y + 1] && mat_pos[pt.y][pt.x + 1].x != -1)
	{
		apex.a = mat_pos[pt.y][pt.x];
		apex.b = mat_pos[pt.y][pt.x + 1];
		apex.c = mat_pos[pt.y + 1][pt.x];
		apex.d = mat_pos[pt.y + 1][pt.x + 1];
		apex = get_apex_of_diamonds(apex, disp);
		if (pt.x == 1 && pt.y == 2)
		{
			print_apex(apex);
		//	lines = get_eq_lines(apex);
		//	eraser = get_erasers(lines, apex);
		//	erase_inside(eraser, lines, img);
		}
		display_line(apex.a, apex.b, img->size_line, img);
		display_line(apex.b, apex.d, img->size_line, img);
		display_line(apex.a, apex.c, img->size_line, img);
		display_line(apex.c, apex.d, img->size_line, img);
	}
}

void	erase_inside(t_eraser eraser, t_lines lines, t_img *img)
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

	//FROM A TO C
	printf("eraser.pt_a : (%f, %f)\n", eraser.pt_a.x, eraser.pt_a.y);
	printf("eraser.pt_c : (%f, %f)\n", eraser.pt_c.x, eraser.pt_c.y);
	printf("eraser.pt_d : (%f, %f)\n", eraser.pt_d.x, eraser.pt_d.y);
	vect_v = get_vect_btw_2_pts(eraser.pt_a, eraser.pt_c);
	dist_v = get_dist_btw_2_pts(eraser.pt_a, eraser.pt_c);
	tmp = eraser.pt_a;
	witness = tmp;
	while (get_dist_btw_2_pts(tmp, eraser.pt_a) < dist_v)
	{
		count = tmp;
		perp = get_pt_perp(lines, eraser, count, eraser.a);
		printf("perp : (%f, %f)\n", perp.x, perp.y);
		vect_h = get_vect_btw_2_pts(count, perp);
		dist_h = get_dist_btw_2_pts(count, perp);
		if (!is_pts_equal(count, perp))
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
					count = apply_vect(count, vect_h, 0.001);
			}
		}
		witness = tmp;
		while ((int)tmp.x == (int)witness.x && 
				(int)tmp.y == (int)witness.y)
			tmp = apply_vect(tmp, vect_v, 0.001);
	}

	//FROM C TO D
	vect_v = get_vect_btw_2_pts(eraser.pt_c, eraser.pt_d);
	dist_v = get_dist_btw_2_pts(eraser.pt_c, eraser.pt_d);
	tmp = eraser.pt_c;
	witness = tmp;
	while (get_dist_btw_2_pts(tmp, eraser.pt_c) < dist_v)
	{
		count = tmp;
		perp = get_pt_perp(lines, eraser, count, eraser.b);
		vect_h = get_vect_btw_2_pts(count, perp);
		dist_h = get_dist_btw_2_pts(count, perp);
		if (!is_pts_equal(count, perp))
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
					count = apply_vect(count, vect_h, 0.001);
			}
		}
		witness = tmp;
		while ((int)tmp.x == (int)witness.x && 
				(int)tmp.y == (int)witness.y)
			tmp = apply_vect(tmp, vect_v, 0.001);
	}
}

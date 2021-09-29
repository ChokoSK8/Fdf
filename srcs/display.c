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
	t_eraser	eraser;
	t_lines		lines;
	t_apex		new;

	if (mat_pos[pt.y + 1] && mat_pos[pt.y][pt.x + 1].x != -1)
	{
		apex.a = mat_pos[pt.y][pt.x];
		apex.b = mat_pos[pt.y][pt.x + 1];
		apex.c = mat_pos[pt.y + 1][pt.x];
		apex.d = mat_pos[pt.y + 1][pt.x + 1];
		apex = get_apex_of_diamonds(apex, disp);
	//	if (pt.y == 0 && pt.x == 0)
	//	{
			print_apex(apex);
			(void)new;
			//			new = get_apex_inside(apex);
			//			print_apex(new);
			lines = get_eq_lines(apex);
			printf("lines.ac -> a : %f ; b : %f\n", lines.ac.a, lines.ac.b); 
			printf("lines.bd -> a : %f ; b : %f\n", lines.bd.a, lines.bd.b); 
			printf("lines.cd -> a : %f ; b : %f\n", lines.cd.a, lines.cd.b); 
			printf("lines.ab -> a : %f ; b : %f\n", lines.ab.a, lines.ab.b); 
			eraser = get_erasers(lines, apex);
			printf("eraser.a -> a : %f ; b : %f\n", eraser.a.a, eraser.a.b); 
			printf("eraser.b -> a : %f ; b : %f\n", eraser.b.a, eraser.b.b); 
			erase_inside(eraser, lines, img);
	//	}
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
	vect_v = get_vect_btw_2_pts(eraser.pt_a, eraser.pt_c);
	dist_v = get_dist_btw_2_pts(eraser.pt_a, eraser.pt_c);
	//	printf("dist_v : %f\n", dist_v);
	tmp = eraser.pt_a;
	witness = tmp;
	while ((int)tmp.x == (int)witness.x && 
			(int)tmp.y == (int)witness.y)
		tmp = apply_vect(tmp, vect_v, 0.001);
	while (get_dist_btw_2_pts(tmp, eraser.pt_a) < dist_v)
	{
		count = tmp;
		perp = get_pt_perp(lines, eraser, count, eraser.a);
		//	printf("count : (%f, %f)\n", count.x, count.y);
		//	printf("perp : (%f, %f)\n", perp.x, perp.y);
		vect_h = get_vect_btw_2_pts(count, perp);
		witness = count;
		while ((int)count.x == (int)witness.x && 
				(int)count.y == (int)witness.y)
			count = apply_vect(count, vect_h, 0.001);
		dist_h = get_dist_btw_2_pts(count, perp);
		//	printf("dist_h : %f\n", dist_h);
		if (!is_pts_equal(count, perp))
		{
			while (get_dist_btw_2_pts(tmp, count) < dist_h)
			{
				//	printf("count : (%f, %f)\n", count.x, count.y);
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

	printf("hey\n");
	//FROM C TO D
	vect_v = get_vect_btw_2_pts(eraser.pt_c, eraser.pt_d);
	dist_v = get_dist_btw_2_pts(eraser.pt_c, eraser.pt_d);
	tmp = eraser.pt_c;
	witness = tmp;
	while ((int)tmp.x == (int)witness.x && 
			(int)tmp.y == (int)witness.y)
		tmp = apply_vect(tmp, vect_v, 0.001);
	while (get_dist_btw_2_pts(tmp, eraser.pt_c) < dist_v)
	{
		count = tmp;
		perp = get_pt_perp(lines, eraser, count, eraser.b);
		vect_h = get_vect_btw_2_pts(count, perp);
		witness = count;
		while ((int)count.x == (int)witness.x && 
				(int)count.y == (int)witness.y)
			count = apply_vect(count, vect_h, 0.001);
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

/*void	erase_lines(t_apex apex, t_img *img)
  {
  t_vect		vect_h;
  t_vect		vect_v;
  double		dist;
  t_ptdouble	count;
  t_apex		nex;

  new = get_apex_biggest_line(apex);
  vect_v = get_vect_btw_2_pts(new.a, new.c);
  vect_h = get_vect_btw_2_pts(new.a, new.b);
  }	
  void	print_inside_diamonds(t_img *img, t_apex apex)
  {
  t_apex		new;
  t_lines		lines;
  t_ptdouble	pt;
  t_ptdouble	count;
  t_vect		vect_h;
  t_vect		vect_v;
  double		dist_ac;
  double		dist;
  int			pos;
  t_ptdouble	pt_a;

  new = get_apex_inside(apex);
//	print_apex(apex);
//	print_apex(new);
lines = get_eq_lines(new);
dist_ac = get_dist_btw_2_pts(new.a, new.c);
vect_v = get_vect_btw_2_pts(new.a, new.c);
pt_a = new.a;
while (get_dist_btw_2_pts(new.a, pt_a) <= dist_ac)
{
count = pt_a;
pt = get_pt_perpendiculare(lines, count);
vect_h = get_vect_btw_2_pts(count, pt);
dist = get_dist_btw_2_pts(count, pt);
printf("dist : %f\n", dist);
if (!is_pts_equal(count, pt))
{
while (get_dist_btw_2_pts(pt_a, count) <= dist)
{
pos = ((int)count.x * 4 + img->size_line * (int)count.y);
img->data[pos] = 20;
img->data[pos + 1] = 100;
img->data[pos + 2] = 10;
count = apply_vect(count, vect_h, 0.001);
}
}
pt_a = apply_vect(pt_a, vect_v, 0.001);
}
}

void	print_inside_diamonds(t_img *img, t_apex apex)
{
t_apex	new;
t_vect	vect_h;
t_vect	vect_v;
int		pos;
double	dist_h;
double	dist_v;
t_ptdouble	count;
t_ptdouble	pt_a;

new = get_apex_inside(apex);
//	print_apex(apex);
//	print_apex(new);
dist_h = get_dist_btw_2_pts(new.a, new.b);
dist_v = get_dist_btw_2_pts(new.a, new.c);
vect_v = get_vect_btw_2_pts(new.a, new.c);
vect_h = get_vect_btw_2_pts(new.a, new.b);
pt_a.x = new.a.x;
pt_a.y = new.a.y;
while (get_dist_btw_2_pts(new.a, pt_a) < dist_v)
{
	count.x = new.a.x;
	count.y = new.a.y;
	while (get_dist_btw_2_pts(new.a, count) < dist_h)
	{
		//	printf("count : (%f, %f)\n", count.x, count.y);
		pos = ((int)count.x * 4 + img->size_line * (int)count.y);
		img->data[pos] = 0;
		img->data[pos + 1] = 0;
		img->data[pos + 2] = 0;
		count = apply_vect(count, vect_h, 0.001);
	}
	new.a = apply_vect(new.a, vect_v, 0.001); 
}
}*/

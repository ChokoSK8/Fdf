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
	t_apex	apex;
	
	if (mat_pos[pt.y + 1] && mat_pos[pt.y][pt.x + 1].x != -1)
	{
		apex.a = mat_pos[pt.y][pt.x];
		apex.b = mat_pos[pt.y][pt.x + 1];
		apex.c = mat_pos[pt.y + 1][pt.x];
		apex.d = mat_pos[pt.y + 1][pt.x + 1];
		apex = get_apex_of_diamonds(apex, disp);
		display_line(apex.a, apex.b, img->size_line, img);
		display_line(apex.b, apex.d, img->size_line, img);
		display_line(apex.a, apex.c, img->size_line, img);
		display_line(apex.c, apex.d, img->size_line, img);
	}
}

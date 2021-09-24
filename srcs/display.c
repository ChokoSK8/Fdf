#include "fdf.h"

void	display_squares(t_img *img, t_map map)
{
	t_point		pt;
	t_display	disp;

	disp = init_display(*img);
	pt.y = 0;
	while (map.data[pt.y])
	{
		pt.x = 0;
		while (map.data[pt.y][pt.x])
		{
			if (map.data[pt.y][pt.x] >= 48)
				print_diamonds(img, pt, disp);
			pt.x++;
		}
		pt.y++;
	}
}

void	print_diamonds(t_img *img, t_point pt, t_display disp)
{
	t_apex		apex;

	apex = get_apex_of_diamonds(pt, *img, disp);
	display_line(apex.a, apex.b, img->size_line, img);
	display_line(apex.b, apex.d, img->size_line, img);
	display_line(apex.a, apex.c, img->size_line, img);
	display_line(apex.c, apex.d, img->size_line, img);
}

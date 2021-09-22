#include "fdf.h"

void	display_squares(t_img *img, t_map map)
{
	t_point		pt;

	pt.y = 0;
	while (map.data[pt.y])
	{
		pt.x = 0;
		while (map.data[pt.y][pt.x])
		{
			if (map.data[pt.y][pt.x] >= 48)
				print_diamonds(img, pt, img->size_line);
			pt.x++;
		}
		pt.y++;
	}
}

void	print_cases(t_img *img, t_point pt, int size_line)
{
	int		pos;
	t_point		len_pix;
	t_point		offset;

	len_pix.x = 0;
	offset.x = img->coef_x * 4;
	offset.y = img->coef_y * 4;
	pt.x = (pt.x * img->coef_x) + offset.x;
	pt.y = (pt.y * img->coef_y) + offset.y;
	while (len_pix.x <= img->coef_x)
	{
		len_pix.y = 0;
		while (len_pix.y < img->coef_y)
		{
			pos = (pt.x + len_pix.x) * 4 +
					size_line * (pt.y + len_pix.y);
			img->data[pos] = 100;
			img->data[pos + 1] = 50;
			img->data[pos + 2] = 90;
			len_pix.y++;
		}
		len_pix.x += img->coef_x;
	}
	len_pix.y = 0;
	while (len_pix.y <= img->coef_y)
	{
		len_pix.x = 0;
		while (len_pix.x < img->coef_x)
		{
			pos = (pt.x + len_pix.x) * 4 +
					size_line * (pt.y + len_pix.y);
			img->data[pos] = 100;
			img->data[pos + 1] = 50;
			img->data[pos + 2] = 90;
			len_pix.x++;
		}
		len_pix.y += img->coef_y;
	}
}

void	print_diamonds(t_img *img, t_point pt, int size_line)
{
	int			pos;
	t_ptdouble		len_pix;
	double			angle;
	t_ptdouble		new;
	t_point			offset;

	angle = 45;
	offset.x = img->coef_x * 4;
	offset.y = img->coef_y * 4;
	pt.x = (pt.x * img->coef_x) + offset.x;
	pt.y = (pt.y * img->coef_y) + offset.y;
	new.x = pt.x * cos(angle) - pt.y * sin(angle);
	new.y = pt.x * sin(angle) + pt.y * cos(angle);
	len_pix.x = 0;
	while ((int)len_pix.x <= img->coef_x)
	{
		len_pix.y = 0;
		while ((int)len_pix.y < img->coef_y)
		{
			pos = (pt.x + (int)len_pix.x) * 4 +
					size_line * (pt.y + (int)len_pix.y);
			img->data[pos] = 100;
			img->data[pos + 1] = 50;
			img->data[pos + 2] = 90;
			len_pix.y += cos(angle);
		}
		len_pix.x += img->coef_x;
	}
	len_pix.y = 0;
	while ((int)len_pix.y <= img->coef_y)
	{
		len_pix.x = 0;
		while ((int)len_pix.x < img->coef_x)
		{
			pos = (pt.x + (int)len_pix.x) * 4 +
					size_line * (pt.y + (int)len_pix.y);
			img->data[pos] = 100;
			img->data[pos + 1] = 50;
			img->data[pos + 2] = 90;
			len_pix.x += cos(angle);
		}
		len_pix.y += img->coef_y;
	}
}

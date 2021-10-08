/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 12:04:52 by abrun             #+#    #+#             */
/*   Updated: 2021/10/08 14:18:53 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	display_squares(t_img *img, t_ptdbl **mat_pos)
{
	t_point	pt;
	t_disp	disp;

	disp = init_disp(*img);
	pt.y = 0;
	while (mat_pos[pt.y])
	{
		pt.x = 0;
		while (mat_pos[pt.y][pt.x].x != -1)
		{
			printf("pt : (%d, %d)\n", pt.x, pt.y);
			print_diamonds(img, mat_pos, pt, disp);
			pt.x++;
		}
		pt.y++;
	}
}

t_disp	init_disp(t_img img)
{
	t_disp		disp;

	disp.origin.x = 500;
	disp.origin.y = 50;
	disp.angle = 45;
	disp.vect_x.x = cos(convert(disp.angle)) * img.coef_x;
	disp.vect_x.y = sin(convert(disp.angle)) * img.coef_x;
	disp.vect_y.x = -sin(convert(disp.angle)) * img.coef_y;
	disp.vect_y.y = cos(convert(disp.angle)) * img.coef_y;
	return (disp);
}

void	print_diamonds(t_img *img, t_ptdbl **mat_pos,
		t_point pt, t_disp disp)
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
			if (pt.x == 1 && pt.y == 1)
				erase_inside(apex, lines, img);
			display_line(apex.a, apex.b, img->size_line, img);
			display_line(apex.b, apex.d, img->size_line, img);
			display_line(apex.a, apex.c, img->size_line, img);
			display_line(apex.c, apex.d, img->size_line, img);
		}
	}
}

int	is_apex_equal(t_apex apex)
{
	if (is_ptdouble_equal(apex.a, apex.b)
		|| is_ptdouble_equal(apex.a, apex.c)
		|| is_ptdouble_equal(apex.a, apex.d)
		|| is_ptdouble_equal(apex.b, apex.c)
		|| is_ptdouble_equal(apex.b, apex.d)
		|| is_ptdouble_equal(apex.c, apex.d))
		return (1);
	return (0);
}

void	put_pixels(t_img *img, t_ptdbl pt)
{
	int	pos;

	pos = ((int)pt.x * 4 + img->size_line * (int)pt.y);
//	printf("pos : %d\n", pos);
	img->data[pos] = 0;
	img->data[pos + 1] = 0;
	img->data[pos + 2] = 0;
}

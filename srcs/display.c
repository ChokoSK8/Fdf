/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 12:04:52 by abrun             #+#    #+#             */
/*   Updated: 2021/10/21 16:20:34 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	display_squares(t_img *img, t_ptdbl **mat_pos, t_param param)
{
	t_point	pt;
	t_disp	disp;

	disp = init_disp(*img, param);
	pt.y = 0;
	while (mat_pos[pt.y])
	{
		pt.x = 0;
		while (mat_pos[pt.y][pt.x].x != -4)
		{
			print_diamonds(img, mat_pos, pt, disp);
			pt.x++;
		}
		pt.y++;
	}
}

t_disp	init_disp(t_img img, t_param param)
{
	t_disp		disp;
	double		a_y;
	double		d_y;
	double		c_x;
	double		b_x;

	disp.angle = 45;
	disp.vect_x.x = cos(convert(disp.angle)) * img.coef_x;
	disp.vect_x.y = sin(convert(disp.angle)) * img.coef_x;
	disp.vect_y.x = -sin(convert(disp.angle)) * img.coef_y;
	disp.vect_y.y = cos(convert(disp.angle)) * img.coef_y;
	a_y = (-3) * disp.vect_x.y + (-3) * disp.vect_y.y;
	b_x = (param.map.max_width + 3) * disp.vect_x.x + (-3) * disp.vect_y.x;
	c_x = (-3) * disp.vect_x.x + (param.map.height + 3) * disp.vect_y.x;
	d_y = (param.map.max_width + 3) * disp.vect_x.y
		+ (param.map.height + 3) * disp.vect_y.y;
	disp.origin.x = (param.width - b_x - c_x) / 2;
	disp.origin.y = (param.height - d_y - a_y) / 2;
	return (disp);
}

void	print_diamonds(t_img *img, t_ptdbl **mat_pos,
		t_point pt, t_disp disp)
{
	t_apex		apex;
	t_lines		lines;

	if (mat_pos[pt.y + 1] && mat_pos[pt.y][pt.x + 1].x != -4)
	{
		apex.a = mat_pos[pt.y][pt.x];
		apex.b = mat_pos[pt.y][pt.x + 1];
		apex.c = mat_pos[pt.y + 1][pt.x];
		apex.d = mat_pos[pt.y + 1][pt.x + 1];
		apex = get_apex_of_diamonds(apex, disp);
		lines = get_eq_lines(apex);
		erase_inside(apex, lines, img);
		display_line(apex.a, apex.b, img);
		display_line(apex.b, apex.d, img);
		display_line(apex.a, apex.c, img);
		display_line(apex.c, apex.d, img);
	}
}

int	is_apex_equal(t_apex apex)
{
	if (is_ptlong_double_equal(apex.a, apex.d)
		|| is_ptlong_double_equal(apex.c, apex.b))
		return (1);
	return (0);
}

void	put_pixels(t_img *img, t_ptdbl pt, int config)
{
	int	pos;

	pos = ((int)pt.x * 4 + img->size_line * (int)pt.y);
	if (config == 0)
	{
		img->data[pos] = 0;
		img->data[pos + 1] = 0;
		img->data[pos + 2] = 0;
	}
	else if (config == 2)
	{
		img->data[pos] = 100;
		img->data[pos + 1] = 100;
		img->data[pos + 2] = 10;
	}
	else
	{
		img->data[pos] = 20;
		img->data[pos + 1] = 10;
		img->data[pos + 2] = 100;
	}
}

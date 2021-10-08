/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase_inside.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 12:05:34 by abrun             #+#    #+#             */
/*   Updated: 2021/10/08 14:20:20 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	erase_inside(t_apex apex, t_lines lines, t_img *img)
{
	t_erase	eraser;

	eraser = init_erase(apex.a, apex.c, lines.ac);
	erase_from_one_lign(eraser, lines, img, apex);
	eraser = init_erase(apex.a, apex.b, lines.ab);
	erase_from_one_lign(eraser, lines, img, apex);
	eraser = init_erase(apex.c, apex.d, lines.cd);
	erase_from_one_lign(eraser, lines, img, apex);
	eraser = init_erase(apex.b, apex.d, lines.bd);
	erase_from_one_lign(eraser, lines, img, apex);
}

t_erase	init_erase(t_ptdbl pt_a, t_ptdbl pt_b, t_line line)
{
	t_erase	eraser;

	eraser.pt_a.x = pt_a.x;
	eraser.pt_a.y = pt_a.y;
	eraser.pt_b.x = pt_b.x;
	eraser.pt_b.y = pt_b.y;
	eraser.line = line;
	return (eraser);
}

void	erase_from_one_lign(t_erase eraser, t_lines lines,
		t_img *img, t_apex apex)
{
	t_ptdbl	tmp;
	t_dists	dist;
	t_vects	vect;
	t_ptdbl	count;
	t_ptdbl	perp;

	vect.v = get_vect_btw_2_pts(eraser.pt_a, eraser.pt_b);
	dist.v = get_dist_btw_2_pts(eraser.pt_a, eraser.pt_b);
	tmp = eraser.pt_a;
	while (get_dist_btw_2_pts(tmp, eraser.pt_a) < dist.v)
	{
		count = tmp;
		perp = get_pt_perp(lines, count, eraser.line, apex);
//		printf("perp : (%f, %f)\n", perp.x, perp.y);
		vect.h = get_vect_btw_2_pts(count, perp);
		dist.h = get_dist_btw_2_pts(count, perp);
//		printf("vect.h : (%f, %f)\n", vect.h.x, vect.h.y);
		if (is_perp_ok(perp) && !is_pts_equal(count, perp))
		{
			while (get_dist_btw_2_pts(tmp, count) < dist.h)
			{
			//	printf("count : (%f, %f)\n", count.x, count.y);
				put_pixels(img, count);
				count = get_next_ptdbl(count, vect.h);
			}
		}
		tmp = get_next_ptdbl(tmp, vect.v);
	}
}

int	is_perp_ok(t_ptdbl perp)
{
	if ((perp.x == 0 && perp.y == 0))
		return (0);
	return (1);
}

t_ptdbl	get_next_ptdbl(t_ptdbl pt, t_vect vect)
{
	t_ptdbl	witness;

	witness = pt;
	while ((int)pt.x == (int)witness.x
		&& (int)pt.y == (int)witness.y)
		pt = apply_vect(pt, vect, 0.0001);
	return (pt);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_diamonds_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 12:05:56 by abrun             #+#    #+#             */
/*   Updated: 2021/10/21 10:24:54 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_apex	get_apex_of_diamonds(t_apex apex, t_disp disp)
{
	apex.a = get_apex(disp, apex.a);
	apex.b = get_apex(disp, apex.b);
	apex.c = get_apex(disp, apex.c);
	apex.d = get_apex(disp, apex.d);
	return (apex);
}

t_ptdbl	get_apex(t_disp disp, t_ptdbl pt)
{
	t_ptdbl	pt_a;

	pt_a.up = pt.up;
	pt_a.x = disp.origin.x + pt.x * disp.vect_x.x + pt.y * disp.vect_y.x;
	pt_a.y = disp.origin.y + pt.x * disp.vect_x.y + pt.y * disp.vect_y.y;
	return (pt_a);
}

void	display_line(t_ptdbl apex_a, t_ptdbl apex_b, t_img *img)
{
	t_vect		vect;
	t_ptdbl		count;
	double		dist;
	int			config;

	config = 2;
	if (apex_a.up && apex_b.up)
		config = 1;
	dist = get_dist_btw_2_pts(apex_a, apex_b);
	count = apex_a;
	vect = get_vect_btw_2_pts(apex_a, apex_b);
	while (get_dist_btw_2_pts(count, apex_a) < dist)
	{
		put_pixels(img, count, config);
		count = get_next_ptdbl(count, vect);
	}
}

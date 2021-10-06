/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 12:05:50 by abrun             #+#    #+#             */
/*   Updated: 2021/10/05 12:05:52 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vect	get_vect_btw_2_pts(t_ptdbl pt_a, t_ptdbl pt_b)
{
	t_vect		vect;

	vect.x = pt_b.x - pt_a.x;
	vect.y = pt_b.y - pt_a.y;
	return (vect);
}

double	convert(double degre)
{
	double	rad;

	rad = degre / 57.2958;
	return (rad);
}

double	convert_inv(double rad)
{
	double	degre;

	degre = 57.2958 * rad;
	return (degre);
}

double	get_dist_btw_2_pts(t_ptdbl pt_a, t_ptdbl pt_b)
{
	double	dist;

	dist = sqrt(pow(pt_a.x - pt_b.x, 2) + pow(pt_a.y - pt_b.y, 2));
	return (dist);
}

t_ptdbl	apply_vect(t_ptdbl pt, t_vect vect, double len)
{
	pt.x += (len * vect.x);
	pt.y += (len * vect.y);
	return (pt);
}

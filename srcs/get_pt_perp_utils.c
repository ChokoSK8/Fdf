/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pt_perp_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 12:06:12 by abrun             #+#    #+#             */
/*   Updated: 2021/10/05 12:06:14 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_ptdbl	pick_perp(t_pperp param)
{
	if (param.btw_1 && (!param.btw_2
			|| (param.btw_2 && param.dist_1 <= param.dist_2))
		&& (!param.btw_3 || (param.btw_3 && param.dist_1 <= param.dist_3)))
		return (param.pt_1);
	if (param.btw_2 && (!param.btw_1
			|| (param.btw_1 && param.dist_2 <= param.dist_1))
		&& (!param.btw_3 || (param.btw_3 && param.dist_2 <= param.dist_3)))
		return (param.pt_2);
	if (param.btw_3 && (!param.btw_2
			|| (param.btw_2 && param.dist_3 <= param.dist_2))
		&& (!param.btw_1 || (param.btw_1 && param.dist_3 <= param.dist_1)))
		return (param.pt_3);
	param.pt_1.x = 0;
	param.pt_1.y = 0;
	return (param.pt_1);
}

t_lperp	assign_line_perp(t_line line, t_ptdbl pt_a, t_ptdbl pt_b)
{
	t_lperp	l_p;

	l_p.a = line.a;
	l_p.b = line.b;
	if (pt_a.x < pt_b.x)
	{
		l_p.x_1 = pt_a.x;
		l_p.x_2 = pt_b.x;
	}
	else
	{
		l_p.x_1 = pt_b.x;
		l_p.x_2 = pt_a.x;
	}
	return (l_p);
}

void	organize_param_perp(t_pperp *param)
{
	if (param->l_1.a == 0 && param->l_1.b == 0)
		param->l_1 = param->l_4;
	if (param->l_2.a == 0 && param->l_2.b == 0)
		param->l_2 = param->l_4;
	if (param->l_3.a == 0 && param->l_3.b == 0)
		param->l_3 = param->l_4;
}

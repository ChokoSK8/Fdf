/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pt_perp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 12:06:20 by abrun             #+#    #+#             */
/*   Updated: 2021/10/05 12:06:22 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_ptdbl	get_pt_perp(t_lines lines, t_ptdbl pt,
		t_line eraser, t_apex apex)
{
	t_pperp	param;
	t_line	l_perp;

	param = init_pperp(lines, eraser, apex);
	l_perp.a = (-1) / eraser.a;
	l_perp.b = pt.y - pt.x * l_perp.a;
	param.pt_1.x = (l_perp.b - param.l_1.b) / (param.l_1.a - l_perp.a);
	param.pt_1.y = param.pt_1.x * l_perp.a + l_perp.b;
	param.pt_2.x = (l_perp.b - param.l_2.b) / (param.l_2.a - l_perp.a);
	param.pt_2.y = param.pt_2.x * l_perp.a + l_perp.b;
	param.pt_3.x = (l_perp.b - param.l_3.b) / (param.l_3.a - l_perp.a);
	param.pt_3.y = param.pt_3.x * l_perp.a + l_perp.b;
	param.dist_1 = get_dist_btw_2_pts(pt, param.pt_1);
	param.dist_2 = get_dist_btw_2_pts(pt, param.pt_2);
	param.dist_3 = get_dist_btw_2_pts(pt, param.pt_3);
	init_param_btw(&param);
	param.pt_1 = pick_perp(param);
	return (param.pt_1);
}

void	init_param_btw(t_pperp *param)
{
	param->btw_1 = 0;
	param->btw_2 = 0;
	param->btw_3 = 0;
	if (is_pt_between_x(param->l_1.x_1, param->pt_1.x, param->l_1.x_2))
		param->btw_1 = 1;
	if (is_pt_between_x(param->l_2.x_1, param->pt_2.x, param->l_2.x_2))
		param->btw_2 = 1;
	if (is_pt_between_x(param->l_3.x_1, param->pt_3.x, param->l_3.x_2))
		param->btw_3 = 1;
}

t_pperp	init_pperp(t_lines lines, t_line eraser, t_apex apex)
{
	t_pperp	param;

	init_lines_perp(&param);
	if (!is_line_equal_to_eraser(lines.ab, eraser))
		param.l_1 = assign_line_perp(lines.ab, apex.a, apex.b);
	if (!is_line_equal_to_eraser(lines.ac, eraser))
		param.l_2 = assign_line_perp(lines.ac, apex.a, apex.c);
	if (!is_line_equal_to_eraser(lines.bd, eraser))
		param.l_3 = assign_line_perp(lines.bd, apex.b, apex.d);
	if (!is_line_equal_to_eraser(lines.cd, eraser))
		param.l_4 = assign_line_perp(lines.cd, apex.c, apex.d);
	organize_param_perp(&param);
	return (param);
}

void	init_lines_perp(t_pperp *param)
{
	param->l_1.a = 0;
	param->l_1.b = 0;
	param->l_2.a = 0;
	param->l_2.b = 0;
	param->l_3.a = 0;
	param->l_3.b = 0;
	param->l_4.a = 0;
	param->l_4.b = 0;
}

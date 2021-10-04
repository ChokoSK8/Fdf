#include "fdf.h"

t_ptdbl	get_pt_perp(t_lines lines, t_ptdbl pt,
		t_line eraser, t_apex apex)
{
	t_pperp	param;
	t_line	l_perp;
	t_ptdbl	pt_perp;

	param = init_pperp(lines, eraser, apex);
	l_perp.a = (-1) / eraser.a;
	l_perp.b = pt.y - pt.x * l_perp.a;
	pt_perp.x = (l_perp.b - param.l_1.b) / (param.l_1.a - l_perp.a);
	pt_perp.y = pt_perp.x * l_perp.a + l_perp.b;
	if (is_pt_between_x(param.l_1.x_1, pt_perp.x, param.l_1.x_2))
		return (pt_perp);
	pt_perp.x = (l_perp.b - param.l_2.b) / (param.l_2.a - l_perp.a);
	pt_perp.y = pt_perp.x * l_perp.a + l_perp.b;
	if (is_pt_between_x(param.l_2.x_1, pt_perp.x, param.l_2.x_2))
		return (pt_perp);
	pt_perp.x = (l_perp.b - param.l_3.b) / (param.l_3.a - l_perp.a);
	pt_perp.y = pt_perp.x * l_perp.a + l_perp.b;
	if (is_pt_between_x(param.l_3.x_1, pt_perp.x, param.l_3.x_2))
		return (pt_perp);
	pt_perp.x = 0;
	pt_perp.y = 0;
	return (pt_perp);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codeur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 11:21:58 by codeur            #+#    #+#             */
/*   Updated: 2021/10/20 18:49:06 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	init_param(t_param *param, char *file)
{
	if (init_map(&param->map, file) < 1)
		return (0);
	param->z_min = 5001;
	param->z_max = -5001;
	mlx_get_screen_size(param->mlx, &param->width, &param->height);
	param->map.matd = char_to_double(param->map.data,
			param->map.max_width, param);
	if (!param->map.matd)
	{
		free_matc(param->map.data);
		return (0);
	}
	init_param_len_and_coef(param);
	param->z = assign_param_z(*param);
	param->mat_pos = get_mat_pos(param->map, param->z);
	if (!param->mat_pos)
	{
		free_matc(param->map.data);
		return (0);
	}
	return (1);
}

int	is_pt_in_screen(t_ptdbl pt, int width, int height)
{
	if (pt.x >= 0 && pt.x <= width
		&& pt.y >= 0 && pt.y <= height)
		return (1);
	return (0);
}

t_apex	get_apex_extrem(t_disp disp, t_map map)
{
	t_apex	apex;

	apex.a.x = disp.origin.x + (-3) * disp.vect_x.x + (-3) * disp.vect_y.x;
	apex.a.y = disp.origin.y + (-3) * disp.vect_x.y
		+ (-3) * disp.vect_y.y;
	apex.b.x = disp.origin.x + (map.max_width + 3) * disp.vect_x.x
		+ (map.height + 3) * disp.vect_y.x;
	apex.b.y = disp.origin.y + (map.max_width + 3) * disp.vect_x.y
		+ (map.height + 3) * disp.vect_y.y;
	apex.c.x = disp.origin.x + (-3) * disp.vect_x.x
		+ (map.height + 3) * disp.vect_y.x;
	apex.c.y = disp.origin.y + (-3) * disp.vect_x.y
		+ (map.height + 3) * disp.vect_y.y;
	apex.d.x = disp.origin.x + (map.max_width + 3) * disp.vect_x.x
		+ (map.height + 3) * disp.vect_y.x;
	apex.d.y = disp.origin.y + (map.max_width + 3) * disp.vect_x.y
		+ (map.height + 3) * disp.vect_y.y;
	return (apex);
}

void	init_param_len_and_coef(t_param *param)
{
	t_disp	disp;
	t_apex	apex;

	param->width -= param->width / 10;
	param->height -= param->height / 10;
	param->img.coef_y = (param->height - 100) / (2 * param->map.height);
	param->img.coef_x = (param->width - 100) / (2 * param->map.max_width);
	disp = init_disp(param->img, *param);
	apex = get_apex_extrem(disp, param->map);
	while (!is_pt_in_screen(apex.a, param->width, param->height)
		|| !is_pt_in_screen(apex.b, param->width, param->height)
		|| !is_pt_in_screen(apex.c, param->width, param->height)
		|| !is_pt_in_screen(apex.d, param->width, param->height))
	{
		param->img.coef_y -= param->img.coef_y / 100;
		param->img.coef_x -= param->img.coef_x / 100;
		disp = init_disp(param->img, *param);
		apex = get_apex_extrem(disp, param->map);
	}
}

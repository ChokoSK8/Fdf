/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codeur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 11:21:58 by codeur            #+#    #+#             */
/*   Updated: 2021/10/15 05:30:22 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	init_param(t_param *param, char *file)
{
	if (init_map(&param->map, file) < 1)
		return (0);
	param->z_min = 2147483647;
	param->z_max = -2147483648;
	mlx_get_screen_size(param->mlx, &param->width, &param->height);
	param->map.mati = ft_char_to_long_mat(param->map.data,
			param->map.max_width, param);
	init_param_len_and_coef(param);
	param->map.mati = div_matl(param->map.mati, param, param->map.max_width);
	if (!param->map.mati)
	{
		free_matc(param->map.data);
		return (0);
	}
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
	if (pt.x >= 300 && pt.x <= width - 300
			&& pt.y >= 300 && pt.y <= height - 300)
		return (1);
	return (0);
}

void	init_param_len_and_coef(t_param *param)
{
	t_disp	disp;
	t_ptdbl	pt_a;
	t_ptdbl	pt_b;
	t_ptdbl	pt_c;
	t_ptdbl	pt_d;
	t_ptdbl	pt_a_p;
	t_ptdbl	pt_b_p;
	t_ptdbl	pt_c_p;
	t_ptdbl	pt_d_p;

	param->width -= 200;
	param->height -= 200;
	printf("param->w : %d\n", param->width);
	param->img.coef_y = (param->height - 100) / (2 * param->map.height);
	param->img.coef_x = (param->width - 100) / (2 * param->map.max_width);
	disp = init_disp(param->img, *param);
	pt_a.x = 0;
	pt_a.y = 0;
	pt_b.x = param->map.max_width;
	pt_b.y = 0;
	pt_c.y = param->map.height;
	pt_c.x = 0;
	pt_d.x = param->map.max_width;
	pt_d.y = param->map.height;
	pt_a_p = get_apex(disp, pt_a);
	pt_b_p = get_apex(disp, pt_b);
	pt_c_p = get_apex(disp, pt_c);
	pt_d_p = get_apex(disp, pt_d);
	while (!is_pt_in_screen(pt_a_p, param->width, param->height)
			&& !is_pt_in_screen(pt_b_p, param->width, param->height)
			&& !is_pt_in_screen(pt_c_p, param->width, param->height)
			&& !is_pt_in_screen(pt_d_p, param->width, param->height))
	{
		param->img.coef_y -= 0.5;
		param->img.coef_x -= 0.5;
		pt_a_p = get_apex(disp, pt_a);
		pt_b_p = get_apex(disp, pt_b);
		pt_c_p = get_apex(disp, pt_c);
		pt_d_p = get_apex(disp, pt_d);
		printf("hey\n");
	}
	printf("img.coef_y : %Lf\n", param->img.coef_y);
	printf("img.coef_x : %Lf\n", param->img.coef_x);
}

int	init_map(t_map *map, char *file)
{
	char		*line;
	int			fd;
	int			ret;

	fd = open(file, O_RDONLY);
	if (!fd)
		return (0);
	ret = get_next_line(fd, &line);
	if (ret < 1 || !get_map_ready(map))
		ret = -1;
	while (ret > 0)
	{
		map->data = ft_add_line_fdf(map->data, line);
		if (!map->data)
			break ;
		increase_params(map, line);
		free(line);
		ret = get_next_line(fd, &line);
	}
	free(line);
	close(fd);
	if (!map->data || !check_map_content(map->data))
		return (0);
	return (1);
}

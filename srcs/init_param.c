/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codeur <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 11:21:58 by codeur            #+#    #+#             */
/*   Updated: 2021/10/05 12:38:34 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	init_param(t_param *param, char *file)
{
	if (init_map(&param->map, file) < 1)
		return (0);
	init_param_len_and_coef(param);
	param->z_max = 0;
	param->z_min = 0;
	param->map.mati = ft_char_to_int_mat(param->map.data,
			param->map.max_width, param);
	if (!param->map.mati)
	{
		free_matc(param->map.data);
		return (0);
	}
	param->mat_pos = get_mat_pos(param->map);
	if (!param->mat_pos)
	{
		free_matc(param->map.data);
		return (0);
	}
	return (1);
}

void	init_param_len_and_coef(t_param *param)
{
	param->img.coef_x = 600 / param->map.max_width;
	param->width = param->img.coef_x * (param->map.max_width) * 2;
	param->img.coef_y = 400 / param->map.height;
	param->height = param->img.coef_y * (param->map.height) * 2;
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
	if (!map->data)
		return (0);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_param_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 11:53:31 by abrun             #+#    #+#             */
/*   Updated: 2021/10/20 19:06:39 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_map_ready(t_map *map)
{
	map->data = malloc(sizeof(char *));
	if (!map->data)
		return (0);
	map->data[0] = 0;
	map->height = 0;
	map->max_width = 0;
	return (1);
}

double	assign_param_z(t_param param)
{
	double	z;
	double	max;

	max = ft_abs(param.z_max);
	if (max < ft_abs(param.z_min))
		max = ft_abs(param.z_min);
	if (!max)
		return (0);
	z = 2.333235 / max;
	return (z);
}

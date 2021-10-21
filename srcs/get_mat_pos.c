/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mat_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 11:24:25 by abrun             #+#    #+#             */
/*   Updated: 2021/10/21 11:03:31 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_ptdbl	**get_mat_pos(t_map map, double z)
{
	t_point	pt;
	t_ptdbl	**mat;
	int		x_max;

	mat = malloc(sizeof(t_ptdbl *) * (map.height + 1));
	if (!mat)
		return (0);
	x_max = 0;
	pt.y = -1;
	while (map.matd[++pt.y])
	{
		mat[pt.y] = malloc(sizeof(t_ptdbl) * (map.max_width + 1));
		if (!mat[pt.y])
		{
			free_mat_pos(mat);
			return (0);
		}
		pt.x = -1;
		while (++pt.x < (int)map.max_width)
			assign_position(&mat[pt.y][pt.x], pt, z, map.matd[pt.y][pt.x]);
		mat[pt.y][pt.x].x = -1;
		if (x_max < pt.x)
			x_max = pt.x;
	}
	mat[pt.y] = 0;
	if (pt.y <= 1 || x_max <= 1)
	{
		free_mat_pos(mat);
		return (0);
	}
	return (mat);
}

void	assign_position(t_ptdbl *mat, t_point pt, double z, double altitude)
{
	mat->x = pt.x - z * (altitude);
	mat->y = pt.y - z * (altitude);
	if (mat->x < (double)pt.x)
		mat->up = 1;
	else
		mat->up = 0;
}

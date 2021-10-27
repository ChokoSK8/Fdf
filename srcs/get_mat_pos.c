/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mat_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 11:24:25 by abrun             #+#    #+#             */
/*   Updated: 2021/10/21 18:18:09 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_ptdbl	**get_mat_pos(t_map map, double z)
{
	t_point	pt;
	t_ptdbl	**mat;

	if (!init_param_matpos(&mat, map.height, &pt.y))
		return (0);
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
		mat[pt.y][pt.x].x = -4;
	}
	mat[pt.y] = 0;
	return (mat);
}

int	init_param_matpos(t_ptdbl ***mat, size_t height, int *y)
{
	*mat = malloc(sizeof(t_ptdbl *) * (height + 1));
	if (!*mat)
		return (0);
	*y = -1;
	return (1);
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

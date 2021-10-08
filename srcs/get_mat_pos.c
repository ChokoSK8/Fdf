/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mat_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 11:24:25 by abrun             #+#    #+#             */
/*   Updated: 2021/10/08 17:27:36 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_ptdbl	**get_mat_pos(t_map map, long double z)
{
	t_point	pt;
	t_ptdbl	**mat;

	mat = malloc(sizeof(t_ptdbl *) * (map.height + 1));
	if (!mat)
		return (0);
	pt.y = -1;
	while (map.mati[++pt.y])
	{
		mat[pt.y] = malloc(sizeof(t_ptdbl) * (map.max_width + 1));
		if (!mat[pt.y])
		{
			free_mat_pos(mat);
			return (0);
		}
		pt.x = -1;
		while (++pt.x < (int)map.max_width)
		{
			mat[pt.y][pt.x].x = pt.x - z * (map.mati[pt.y][pt.x]);
			mat[pt.y][pt.x].y = pt.y - z * (map.mati[pt.y][pt.x]);
		}
		printf("pt : (%d, %d)\n", pt.x, pt.y);
		mat[pt.y][pt.x].x = -1;
	}
	mat[pt.y] = 0;
	return (mat);
}

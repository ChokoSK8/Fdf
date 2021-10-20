/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:41:52 by abrun             #+#    #+#             */
/*   Updated: 2021/10/20 18:43:57 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_map_content(char **matc)
{
	t_point	pt;
	int		x_max;

	x_max = 0;
	pt.y = 0;
	while (matc[pt.y])
	{
		pt.x = 0;
		while (matc[pt.y][pt.x])
		{
			if (matc[pt.y][pt.x] == ' ' || ft_isdigit(matc[pt.y][pt.x])
					|| matc[pt.y][pt.x] == '+' || matc[pt.y][pt.x] == '-')
				pt.x++;
			else
				return (0);
		}
		if (x_max < pt.x)
			x_max = pt.x;
		pt.y++;
	}
	if (pt.y <= 1 || x_max <= 1)
		return (0);
	return (1);
}

char	**assign_the_line_and_z(char **new_mat, char *line, int count)
{
	new_mat[count] = ft_strdup(line);
	if (!new_mat[count++])
	{
		free_matc(new_mat);
		return (0);
	}
	new_mat[count] = 0;
	return (new_mat);
}

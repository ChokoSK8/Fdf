/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:41:52 by abrun             #+#    #+#             */
/*   Updated: 2021/10/21 11:10:19 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_map_content(t_map map)
{
	t_point	pt;

	if (map.min_width <= 1 || map.max_width <= 1)
		return (0);
	pt.y = 0;
	while (map.data[pt.y])
	{
		pt.x = 0;
		while (map.data[pt.y][pt.x])
		{
			if (map.data[pt.y][pt.x] == ' ' || ft_isdigit(map.data[pt.y][pt.x])
					|| map.data[pt.y][pt.x] == '+' || map.data[pt.y][pt.x] == '-')
				pt.x++;
			else
				return (0);
		}
		pt.y++;
	}
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

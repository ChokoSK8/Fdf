/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_param_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 11:53:31 by abrun             #+#    #+#             */
/*   Updated: 2021/10/08 14:25:05 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	**ft_add_line_fdf(char **mat, char *line)
{
	int		matlen;
	char	**new_mat;
	int		count;

	matlen = ft_matlen(mat);
	new_mat = malloc(sizeof(char *) * (matlen + 2));
	count = 0;
	if (new_mat)
	{
		while (matlen--)
		{
			new_mat[count] = ft_strdup(mat[count]);
			if (!new_mat[count++])
			{
				free_matc(new_mat);
				free_matc(mat);
				return (0);
			}
		}
		new_mat = assign_the_line_and_z(new_mat, line, count);
	}
	free_matc(mat);
	return (new_mat);
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

void	increase_params(t_map *map, char *line)
{
	if (map->max_width < ft_digitlen_in_str(line))
		map->max_width = ft_digitlen_in_str(line);
	map->height++;
}

double	assign_param_z(t_param param, t_map map)
{
	t_point	pt;
	double	z;

	pt.x = map.max_width;
	pt.y = map.height;
	z = 1;
	while (z > 0.000001 && (pt.x - z * param.z_min > param.width - 100
			|| pt.y - z * param.z_min > param.height - 100
			|| z * param.z_max > 100))
	{
		printf("z : %f\n", z);
		if (z > 0.01)
			z -= 0.01;
		else if (z > 0.0001)
			z -= 0.0001;
		else if (z > 0.000001)
			z -= 0.0000001;
	}
	return (z);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_param_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 11:53:31 by abrun             #+#    #+#             */
/*   Updated: 2021/10/05 12:40:36 by abrun            ###   ########.fr       */
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
		new_mat[count] = ft_strdup(line);
		if (!new_mat[count++])
		{
			free_matc(new_mat);
			free_matc(mat);
			return (0);
		}
		new_mat[count] = 0;
	}
	free_matc(mat);
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

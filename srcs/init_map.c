/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:38:58 by abrun             #+#    #+#             */
/*   Updated: 2021/10/21 11:21:53 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	init_map(t_map *map, char *file)
{
	int		fd;
	char	*line;

	if (!init_map_param(map, file, &line, &fd))
		return (0);
	while (line)
	{
		map->data = ft_add_line_fdf(map->data, line);
		if (!map->data)
		{
			free(line);
			break ;
		}
		increase_params(map, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (!map->data || !check_map_content(*map))
	{
		free_matc(map->data);
		return (0);
	}
	return (1);
}

int	init_map_param(t_map *map, char *file, char **line, int *fd)
{
	*fd = open(file, O_RDONLY);
	if (!*fd)
		return (0);
	if (!get_map_ready(map))
	{
		close(*fd);
		return (0);
	}
	*line = get_next_line(*fd);
	if (!*line)
		return (0);
	return (1);
}

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

void	increase_params(t_map *map, char *line)
{
	if (map->max_width < ft_digitlen_in_str(line))
		map->max_width = ft_digitlen_in_str(line);
	if (map->min_width > ft_digitlen_in_str(line))
		map->min_width = ft_digitlen_in_str(line);
	map->height++;
}

char	*get_next_line(int fd)
{
	char	*line;
	int		ret;
	char	buf[2];

	line = malloc(1);
	if (!line)
		return (0);
	*line = 0;
	ret = read(fd, buf, 1);
	buf[1] = 0;
	while (ret > 0 && *buf != '\n')
	{
		line = ft_strjoin_free(line, buf);
		ret = read(fd, buf, 1);
		buf[1] = 0;
	}
	if (ret < 1)
	{
		free(line);
		return (0);
	}
	return (line);
}

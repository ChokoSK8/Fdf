#include "fdf.h"

int		init_param(t_param *param, char *file)
{
	int		ret;

	ret = init_map(&param->map, file);
	if (ret < 1)
		return (ret);
	init_param_len(param);
	return (1);
}

void	init_param_len(t_param *param)
{
	int		w;
	int		h;

	w = 1000 / param->map.width;
	param->width = w * param->map.width;
	h = 700 / param->map.max_height;
	param->height = h * param->map.max_height;
}

int		init_map(t_map *map, char *file)
{
	char		*line;
	int			fd;
	int			ret;
	int			count;

	count = 0;
	fd = open(file, O_RDONLY);
	if (!fd)
		return (-1);
	ret = get_next_line(fd, &line);
	if (ret < 1)
		return (ret);
	map->data = malloc(sizeof(char *));
	if (!map->data)
		return (-1);
	map->data[0] = 0;
	map->max_height = 0;
	map->width = 0;
	while (ret)
	{
		map->data = ft_add_line(map->data, line);
		if (map->max_height < ft_strlen(line))
			map->max_height = ft_strlen(line);
		if (!map->data)
			return (-1);
		free(line);
		ret = get_next_line(fd, &line);
		count++;
		map->width++;
	}
	free(line);
	close(fd);
	return (1);
}

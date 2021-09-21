#include "fdf.h"

void	display_squares(t_img *img, t_map map, int height, int width)
{
	t_point		pt;
	t_point		map_pt;
	int			pos;

	map_pt.x = 0;
	while (map_pt.x < map.height)
	{
		map_pt.y = 0;
		while (map_pt.y < map.width)
		{
			if (map.data[map_pt.x][map_pt.y] > 0)
				print_case(&img->data, map_pt, img->size_line);
			map_pt.y++;
		}
		map_pt.x++;
	}
}

void	print_cases(char **data, t_point map_pt, int size_line)
{
	int		pos;

	pos = map_pt.x * 4 + size_line * map_pt.y;
	*data[pos] = 100;
	*data[pos + 1] = 50;
	*data[pos + 2] = 90;
}

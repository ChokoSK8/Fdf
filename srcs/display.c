#include "fdf.h"

void	display_squares(char **data, t_map map, int height, int width)
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
				print_case(data, map_pt);
			map_pt.y++;
		}
		map_pt.x++;
	}
}

void	print_cases(char **data, t_point map_pt)
{


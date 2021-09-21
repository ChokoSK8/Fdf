#include "fdf.h"

int		ft_close_window(int key, t_param *param)
{
	if (key == 53)
	{
		mlx_destroy_window(param->mlx, param->win);
		free_param(param);
		printf("\nTest des leaks\n");
		system("leaks fdf | grep leaked\n");
		exit(0);
	}
	return (1);
}

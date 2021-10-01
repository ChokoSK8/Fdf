#include "fdf.h"

int	ft_close_window(int key, t_param *param)
{
	if (key == 65307)
	{
		free_param(param);
		mlx_destroy_window(param->mlx, param->win);
		mlx_destroy_display(param->mlx);
		free(param->mlx);
		exit(0);
	}
	return (1);
}

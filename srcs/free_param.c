#include "fdf.h"

void	free_param(t_param *param)
{
	free(param->img.data);
}

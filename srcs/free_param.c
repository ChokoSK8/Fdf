#include "fdf.h"

void	free_param(t_param *param)
{
	free(param->img.data);
}

void	free_matc(char **matc)
{
	int		n;

	n = 0;
	while (matc[n])
	{
		free(matc[n]);
		n++;
	}
	free(matc);
}

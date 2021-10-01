#include "fdf.h"

void	free_param(t_param *param)
{
	free(param->img.data);
	free_mati(param->map.mati);
}

void	free_mati(int **mati)
{
	int		n;

	n = 0;
	while (mati[n])
	{
		free(mati[n]);
		n++;
	}
	free(mati);
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

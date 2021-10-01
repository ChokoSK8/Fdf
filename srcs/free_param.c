#include "fdf.h"

void	free_param(t_param *param)
{
	free_matc(param->map.data);
	mlx_destroy_image(param->mlx, param->img.image);
	free_mati(param->map.mati);
	free_mat_pos(param->mat_pos);
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

void	free_mat_pos(t_ptdouble **mat_pos)
{
	int	n;

	n = 0;
	while (mat_pos[n])
	{
		free(mat_pos[n]);
		n++;
	}
	free(mat_pos);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 11:26:17 by abrun             #+#    #+#             */
/*   Updated: 2021/10/20 17:51:17 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_param(t_param *param)
{
	free_matc(param->map.data);
	mlx_destroy_image(param->mlx, param->img.image);
	free_matd(param->map.matd);
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

void	free_matd(double **matd)
{
	int		n;

	n = 0;
	while (matd[n])
	{
		free(matd[n]);
		n++;
	}
	free(matd);
}

void	free_mat_pos(t_ptdbl **mat_pos)
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

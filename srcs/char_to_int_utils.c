/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_to_int_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 10:52:19 by abrun             #+#    #+#             */
/*   Updated: 2021/10/14 14:06:54 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	assign_param_z_limits(t_param *param, long double n)
{
	if (param->z_max < n)
		param->z_max = n;
	if (param->z_min > n)
		param->z_min = n;
}

int	get_next_pt_x(char **matc, t_point pt, int config)
{
	if (config == 1)
	{
		while (matc[pt.y][pt.x] && !(ft_is_sign_digit(matc[pt.y][pt.x],
						matc[pt.y][pt.x + 1])))
			pt.x++;
	}
	else
	{
		while (matc[pt.y][pt.x] && ft_is_sign_digit(matc[pt.y][pt.x],
						matc[pt.y][pt.x + 1]))
			pt.x++;
	}
	return (pt.x);
}

long double	**div_matl(long double **matl, t_param *param, int len)
{
	long double	div;
	t_point		pt;

	div = 1;
	while (param->z_min/div < -30 || param->z_max/div > 30)
		div += 0.1;
	pt.y = 0;
	param->z_min /= div;
	param->z_max /= div;
	while (matl[pt.y])
	{
		pt.x = 0;
		while (pt.x < len)
		{
			matl[pt.y][pt.x] /= div;
			pt.x++;
		}
		pt.y++;
	}
	return (matl);
}

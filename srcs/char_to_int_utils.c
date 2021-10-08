/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_to_int_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 10:52:19 by abrun             #+#    #+#             */
/*   Updated: 2021/10/08 12:09:52 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	assign_param_z_limits(t_param *param, int n)
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

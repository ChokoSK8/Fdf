/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_one_lign_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:50:54 by abrun             #+#    #+#             */
/*   Updated: 2021/10/21 10:38:15 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

double	assign_one_digit(char **matc, t_point pt)
{
	char	*digit;
	double	num;

	digit = get_digit_from_str(matc[pt.y], pt.x);
	if (!digit)
	{
		free(digit);
		return (5001);
	}
	num = ft_atoi_ldb(digit);
	free(digit);
	return (num);
}

void	assign_param_z_limits(t_param *param, double n)
{
	if (param->z_max < n)
		param->z_max = n;
	if (param->z_min > n)
		param->z_min = n;
}

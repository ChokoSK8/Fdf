/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_to_double.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 11:22:28 by abrun             #+#    #+#             */
/*   Updated: 2021/10/21 10:36:39 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	**char_to_double(char **matc, int max_width, t_param *param)
{
	double	**matd;
	t_point	pt;

	matd = malloc(sizeof(double *) * (ft_matlen(matc) + 1));
	if (!matd)
		return (0);
	pt.y = 0;
	while (matc[pt.y])
	{
		pt.x = 0;
		matd[pt.y] = fill_one_lign(matc, pt, max_width, param);
		if (!matd[pt.y])
		{
			free_matd(matd);
			return (0);
		}
		pt.y++;
	}
	matd[pt.y] = 0;
	return (matd);
}

double	*fill_one_lign(char **matc, t_point pt, int max_width, t_param *param)
{
	int		count;
	double	*tabd;

	count = 0;
	tabd = malloc(sizeof(double) * (max_width + 1));
	if (!tabd)
		return (0);
	while (matc[pt.y][pt.x])
	{
		pt.x = get_next_pt_x(matc, pt, 1);
		if (matc[pt.y][pt.x])
		{
			tabd[count] = assign_one_digit(matc, pt);
			if (tabd[count++] == 5001)
			{
				free(tabd);
				return (0);
			}
			assign_param_z_limits(param, tabd[count - 1]);
		}
		pt.x = get_next_pt_x(matc, pt, 2);
	}
	while (count < max_width)
		tabd[count++] = 0;
	return (tabd);
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

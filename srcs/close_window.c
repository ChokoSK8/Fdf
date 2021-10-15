/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 12:05:25 by abrun             #+#    #+#             */
/*   Updated: 2021/10/14 09:58:39 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_close_window(int key, t_param *param)
{
	if (key == 65307)
	{
		free_param(param);
		mlx_destroy_window(param->mlx, param->win);
//		mlx_destroy_display(param->mlx);
		free(param->mlx);
		exit(0);
	}
	return (1);
}

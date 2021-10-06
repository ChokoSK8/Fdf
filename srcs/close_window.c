/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 12:05:25 by abrun             #+#    #+#             */
/*   Updated: 2021/10/05 12:09:53 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_close_window(int key, t_param *param)
{
	if (key == 53)
	{
		free_param(param);
		mlx_destroy_window(param->mlx, param->win);
		free(param->mlx);
		printf("\nTest des leaks\n");
		system("leaks fdf | grep leaked\n");
		exit(0);
	}
	return (1);
}

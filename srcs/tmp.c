/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:06:29 by abrun             #+#    #+#             */
/*   Updated: 2021/10/20 16:54:02 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_print_matl(double **mat, int max_width)
{
	int	x;
	int	y;

	y = 0;
	while (mat[y])
	{
		x = 0;
		while (x < max_width)
		{
			printf("mat[%d][%d] : %f\n", y, x, mat[y][x]);
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
}

void	print_matc(char **mat)
{
	int	x;
	int	y;

	y = 0;
	while (mat[y])
	{
		x = 0;
		while (mat[y][x])
		{
			printf("%c ", mat[y][x]);
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
}

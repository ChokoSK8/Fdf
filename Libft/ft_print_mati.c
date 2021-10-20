/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_mati.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 19:10:19 by abrun             #+#    #+#             */
/*   Updated: 2021/10/20 19:10:21 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_mati(int**mat, int max_width)
{
	int	x;
	int	y;

	y = 0;
	while (mat[y])
	{
		x = 0;
		while (x < max_width)
		{
			ft_putnbr_fd(mat[y][x], 1);
			x++;
			if (x < max_width)
				write(1, " ", 1);
		}
		write(1, "\n", 1);
		y++;
	}
}

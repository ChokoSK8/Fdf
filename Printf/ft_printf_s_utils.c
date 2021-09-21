/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:52:50 by abrun             #+#    #+#             */
/*   Updated: 2021/01/14 16:47:20 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		print_s_npt(int n_point, const char *s, int puissance, char *num)
{
	int		counter;

	counter = 0;
	if (!is_flag_point(num))
		ft_putstr_fd(s, 1);
	else
	{
		while (n_point > 0 && n_point-- && s[counter])
		{
			ft_putchar_fd(s[counter], 1);
			counter++;
			puissance--;
		}
		while (n_point > 0 &&n_point-- && puissance)
		{
			ft_putchar_fd(32, 1);
			puissance--;
		}
		while (puissance--)
			ft_putchar_fd(32, 1);
	}
}

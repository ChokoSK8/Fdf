/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 10:00:39 by abrun             #+#    #+#             */
/*   Updated: 2021/10/08 18:04:40 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_digit_lint(char *digit)
{
	size_t		digit_len;

	digit_len = ft_strlen(digit);
	if (digit_len < 19)
		return (1);
	if (digit_len >= 21)
		return (0);
	if (digit_len == 20 && *digit != '-')
		return (0);
	if (digit_len == 20 && ft_strncmp(digit, "-9223372036854775808", 20) > 0)
		return (0);
	if (digit_len == 19 && ft_strncmp(digit, "9223372036854775807", 19) > 0)
		return (0);
	return (1);
}

int	check_map_content(char **matc)
{
	t_point	pt;

	pt.y = 0;
	while (matc[pt.y])
	{
		pt.x = 0;
		while (matc[pt.y][pt.x])
		{
			if (matc[pt.y][pt.x] == ' ' || ft_isdigit(matc[pt.y][pt.x])
					|| matc[pt.y][pt.x] == '+' || matc[pt.y][pt.x] == '-')
				pt.x++;
			else
				return (0);
		}
		pt.y++;
	}
	return (1);
}

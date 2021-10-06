/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 10:00:39 by abrun             #+#    #+#             */
/*   Updated: 2021/10/05 11:01:47 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_digit_int(char *digit)
{
	size_t		digit_len;

	digit_len = ft_strlen(digit);
	if (digit_len < 10)
		return (1);
	if (digit_len >= 12)
		return (0);
	if (digit_len == 11 && *digit != '-')
		return (0);
	if (digit_len == 11 && ft_strncmp(digit, "-2147483647", 11) > 0)
		return (0);
	if (digit_len == 10 && ft_strncmp(digit, "2147483647", 10) > 0)
		return (0);
	return (1);
}

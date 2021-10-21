/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_to_double_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 10:52:19 by abrun             #+#    #+#             */
/*   Updated: 2021/10/21 10:38:29 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*get_digit_from_str(char *str, int count)
{
	char	*digit;
	size_t	len;
	int		c;

	len = get_digit_len(str, count);
	digit = malloc(len + 1);
	if (!digit)
		return (0);
	c = 0;
	while (str[count] && ft_is_sign_digit(str[count], str[count + 1]))
		digit[c++] = str[count++];
	digit[c] = 0;
	if (!check_digit_lint(digit))
	{
		free(digit);
		return (0);
	}
	return (digit);
}

size_t	get_digit_len(char *str, int count)
{
	int	len;

	len = 0;
	while (str[count] && ft_is_sign_digit(str[count], str[count + 1]))
	{
		count++;
		len++;
	}
	return (len);
}

int	check_digit_lint(char *digit)
{
	size_t		digit_len;

	digit_len = ft_strlen(digit);
	if (digit_len < 4)
		return (1);
	if (digit_len >= 6)
		return (0);
	if (digit_len == 4 && *digit != '-')
		return (1);
	if (digit_len == 5 && ft_strncmp(digit, "-5000", 5) > 0)
		return (0);
	if (digit_len == 4 && ft_strncmp(digit, "5000", 4) > 0)
		return (0);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_to_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 11:22:28 by abrun             #+#    #+#             */
/*   Updated: 2021/10/08 18:15:49 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

long double	**ft_char_to_long_mat(char **matc, int max_width, t_param *param)
{
	long double	**matl;
	t_point		pt;

	matl = malloc(sizeof(long double *) * (ft_matlen(matc) + 1));
	if (!matl)
		return (0);
	pt.y = 0;
	while (matc[pt.y])
	{
		pt.x = 0;
		matl[pt.y] = fill_one_lign(matc, pt, max_width, param);
		if (!matl[pt.y])
		{
			free_matldb(matl);
			return (0);
		}
		pt.y++;
	}
	matl[pt.y] = 0;
	return (matl);
}

long double	*fill_one_lign(char **matc, t_point pt, int max_width, t_param *param)
{
	int			count;
	long double	*tabi;

	count = 0;
	tabi = malloc(sizeof(long double) * (max_width + 1));
	if (!tabi)
		return (0);
	while (matc[pt.y][pt.x])
	{
		pt.x = get_next_pt_x(matc, pt, 1);
		if (matc[pt.y][pt.x])
		{
			tabi[count] = assign_one_digit(matc, pt);
			if (tabi[count++] == LONG_MAX)
			{
				free(tabi);
				return (0);
			}
			assign_param_z_limits(param, tabi[count - 1]);
		}
		pt.x = get_next_pt_x(matc, pt, 2);
	}
	while (count < max_width)
		tabi[count++] = 0;
	return (tabi);
}

long double	assign_one_digit(char **matc, t_point pt)
{
	char		*digit;
	long double	num;

	digit = get_digit_from_str(matc[pt.y], pt.x);
	if (!digit)
	{
		free(digit);
		return (LONG_MAX);
	}
	num = ft_atoi_ldb(digit);
	printf("num : %Lf\ndigit : %s\n", num, digit);
	free(digit);
	return (num);
}

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
		return (0);
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

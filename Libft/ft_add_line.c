/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 19:09:13 by abrun             #+#    #+#             */
/*   Updated: 2021/10/20 19:09:15 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_add_line(char **mat, char *line)
{
	int		matlen;
	char	**new_mat;
	int		count;

	matlen = ft_matlen(mat);
	new_mat = malloc(sizeof(char *) * (matlen + 2));
	count = 0;
	while (mat[count])
	{
		new_mat[count] = ft_strdup(mat[count]);
		if (!new_mat[count])
			return (0);
		count++;
	}
	new_mat[count] = ft_strdup(line);
	if (!new_mat[count++])
		return (0);
	new_mat[count] = 0;
	return (new_mat);
}

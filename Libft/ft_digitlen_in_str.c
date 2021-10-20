/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digitlen_in_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 19:09:41 by abrun             #+#    #+#             */
/*   Updated: 2021/10/20 19:09:47 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_digitlen_in_str(char *str)
{
	size_t	len;

	len = 0;
	while (*str)
	{
		while (*str && !ft_is_sign_digit(*str, *str + 1))
			str++;
		if (!*str)
			return (len);
		while (*str && ft_is_sign_digit(*str, *str + 1))
			str++;
		len++;
	}
	return (len);
}

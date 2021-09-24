#include "libft.h"

size_t	ft_digitlen_in_str(char *str)
{
	size_t	len;

	len = 0;
	while (*str)
	{
		while (*str && !ft_is_sign_digit(*str, *str + 1))
			str++;
		if (*str)
			len++;
		while (*str && ft_is_sign_digit(*str, *str + 1))
			*str++;
	}
	return (len);
}

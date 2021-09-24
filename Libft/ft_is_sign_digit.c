#include "libft.h"

int	ft_is_sign_digit(char c, char d)
{
	if (ft_isdigit(c))
		return (1);
	if (c == '-' || c == '+')
		if (ft_isdigit(d))
			return (1);
	return (0);
}

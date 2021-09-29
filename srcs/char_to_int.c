#include "fdf.h"

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

char	*get_digit_from_str(char *str, int count)
{
	char	*digit;
	size_t	len;
	int	c;

	len = get_digit_len(str, count);
	digit = malloc(len + 1);
	if (!digit)
		return (0);
	c = 0;
	while (str[count] && ft_is_sign_digit(str[count], str[count + 1]))
		digit[c++] = str[count++];
	digit[c] = 0;
	return (digit);
}

int	**ft_char_to_int_mat(char **matc, int max_width)
{
	int		**mati;
	t_point		pt;
	int		count;
	char		*digit;

	mati = malloc(sizeof(int *) * (ft_matlen(matc) +  1));
	if (!mati)
		return (0);
	 pt.y = 0;
	while (matc[pt.y])
	{
		pt.x = 0;
		count = 0;
		mati[pt.y] = malloc(sizeof(int) * (max_width + 1));
		if (!mati[pt.y])
			return (0);
		while (matc[pt.y][pt.x])
		{
			while (matc[pt.y][pt.x] && !(ft_is_sign_digit(matc[pt.y][pt.x], matc[pt.y][pt.x + 1])))
				pt.x++;
			if (matc[pt.y][pt.x])
			{
				digit = get_digit_from_str(matc[pt.y], pt.x);
				mati[pt.y][count++] = ft_atoi(digit);
				free(digit);
			}
			while (matc[pt.y][pt.x] && ft_is_sign_digit(matc[pt.y][pt.x], matc[pt.y][pt.x + 1]))
				pt.x++;
		}
		while (count < max_width)
			mati[pt.y][count++] = 0;
		pt.y++;
	}
	mati[pt.y] = 0;
	free_matc(matc);
	return (mati);
}

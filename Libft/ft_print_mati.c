#include "libft.h"

void	ft_print_mati(int**mat, int max_width)
{
	int	x;
	int	y;

	y = 0;
	while(mat[y])
	{
		x = 0;
		while(x < max_width)
		{
			printf("%d ", mat[y][x]);
			x++;
		}
		printf("\n");
	y++;
	}
}

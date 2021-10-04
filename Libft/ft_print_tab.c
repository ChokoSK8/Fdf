#include "libft.h"

void	print_tab(int *tab, int tab_len)
{
	int	c;

	c = 0;
	while (c < tab_len)
	{
		ft_putnbr_fd(tab[c], 1);
		c++;
		if (c < tab_len)
			write(1, " ", 1);
	}
	write(1, "\n", 1);
}

#include "fdf.h"

t_tab	get_altz(int **mati, int max_width)
{
	t_tab	altz;
	t_point	pt;

	altz.data = malloc(sizeof(int));
	altz.len = 0;
	if (!altz.data)
		return (altz);
	altz.data = 0;
	pt.y = 0;
	while (mati[pt.y])
	{
		pt.x = 0;
		while (pt.x < max_width)
		{
			if (!is_n_in_tab(mati[pt.y][pt.x], altz.data, altz.len))
			{
				altz.data = add_n_in_tab(altz.data, mati[pt.y][pt.x], altz.len);
				altz.len++;
			}
			pt.x++;
		}
		pt.y++;
	}
	organize_in_order_tab(&altz.data, altz.len);
	return (altz);
}

int	is_n_in_tab(int n, int *tab, int tab_len)
{
	int	count;

	count = 0;
	while (count < tab_len)
	{
		if (n == tab[count])
			return (1);
		count++;
	}
	return (0);
}

int	*add_n_in_tab(int *tab, int n, int tab_len)
{
	int	*new_tab;
	int	count;

	new_tab = malloc(sizeof(int) * (tab_len + 1));
	if (!new_tab)
		return (0);
	count = -1;
	while (++count < tab_len)
		new_tab[count] = tab[count];
	free(tab);
	new_tab[count] = n;
	return (new_tab);
}

void	organize_in_order_tab(int **tab, int tab_len)
{
	int	round;
	int	count;

	round = tab_len - 1;
	print_tab(*tab, tab_len);
	while (round)
	{
		count = 0;
		while (count < round)
		{
			if (*(*tab + count) > *(*tab + count + 1))
				swap_in_tab(*tab + count, *tab + count + 1);
			count++;
		}
		round--;
	}
}

void	swap_in_tab(int *a, int *b)
{
	int	tmp;

	tmp = *b;
	*b = *a;
	*a = tmp;
}

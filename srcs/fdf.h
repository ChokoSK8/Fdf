#ifndef FDF_H

# define FDF_H

# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include "../Mlx_fcts/mlx.h"
# include "../Libft/libft.h"

typedef struct	s_point
{
	int		x;
	int		y;
}				t_point;

typedef struct	s_map
{
	int		**data;
	int		width;
	int		height;
}				t_map;

typedef struct	s_img
{
	int		bpp;
	int		size_line;
	int		endian;
	char	*data;
	void	*image;
}				t_img;

typedef struct	s_param
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	t_img	img;
	t_map	map;
}				t_param;

int		ft_close_window(int key, t_param *param);

void	free_param(t_param *param);
#endif

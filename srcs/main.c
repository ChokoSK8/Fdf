#include "fdf.h"

int		main(int ac, char **av)
{
	t_param		param;

	(void)ac;
	(void)av;

	if (ac < 2)
		return (0);
	init_map(&param.map);
	param.mlx = mlx_init();
	param.img.image = mlx_new_image(param.mlx, param.width, param.height);
	param.img.data = mlx_get_data_addr(param.img.image, &param.img.bpp, &param.img.size_line, &param.img.endian);
	param.win = mlx_new_window(param.mlx, param.width, param.height, "Fdf");
	mlx_put_image_to_window(param.mlx, param.win, param.img.image, 0, 0);
	mlx_hook(param.win, 2, 1L << 0, ft_close_window, &param);
	mlx_loop(param.mlx);
	return (1);
}

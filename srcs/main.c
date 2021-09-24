#include "fdf.h"

int		main(int ac, char **av)
{
	t_param		param;

	(void)ac;
	(void)av;

	if (ac < 2)
		return (0);
	init_param(&param, av[1]);
	ft_print_mat(param.map.data);
	printf("max_width : %zu\n", param.map.max_width);

	int	**mati = ft_char_to_int_mat(param.map.data, param.map.max_width);
	ft_print_mati(mati, param.map.max_width);
	
	//get_mat_pos
/*	t_ptdouble	**mat_pos = get_mat_pos(param.map);
	print_mat_pos(mat_pos);

	param.mlx = mlx_init();
	param.img.image = mlx_new_image(param.mlx, param.width, param.height);
	param.img.data = mlx_get_data_addr(param.img.image, &param.img.bpp, &param.img.size_line, &param.img.endian);
	param.win = mlx_new_window(param.mlx, param.width, param.height, "Fdf");
	display_squares(&param.img, mat_pos);
	mlx_put_image_to_window(param.mlx, param.win, param.img.image, 0, 0);
	mlx_hook(param.win, 2, 1L << 0, ft_close_window, &param);
	mlx_loop(param.mlx);*/
	return (1);
}

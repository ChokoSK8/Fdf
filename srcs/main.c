/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 11:22:42 by abrun             #+#    #+#             */
/*   Updated: 2021/10/08 11:41:12 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_param		param;

	if (ac < 2)
		return (0);
	if (!init_param(&param, av[1]))
	{
		printf("\nTest des leaks\n");
		system("leaks fdf | grep leaked\n");
		return (0);
	}
	param.mlx = mlx_init();
	param.img.image = mlx_new_image(param.mlx, param.width, param.height);
	printf("param.len : (%zu, %zu)\n", param.width, param.height);
	param.img.data = mlx_get_data_addr(param.img.image,
			&param.img.bpp, &param.img.size_line, &param.img.endian);
	param.win = mlx_new_window(param.mlx, param.width, param.height, "Fdf");
	display_squares(&param.img, param.mat_pos);
	mlx_put_image_to_window(param.mlx, param.win, param.img.image, 0, 0);
	mlx_hook(param.win, 2, 1L << 0, ft_close_window, &param);
	mlx_loop(param.mlx);
	return (1);
}

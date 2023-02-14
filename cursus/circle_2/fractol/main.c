/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 09:55:31 by daewoole          #+#    #+#             */
/*   Updated: 2023/02/14 09:56:18 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

int	main(int argc, char *argv[])
{
	t_img	img;
	t_vars	vars;
	t_set	set;

	if (!validate_param(argc, argv, &vars))
		exit(0);
	vars.mlx = mlx_init();
	img.img = mlx_new_image(vars.mlx, W_WIDTH, W_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
			&img.line_length, &img.endian);
	initializing(&img, &vars, &set);
	into_fractal(argc, argv, &vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 17, 0, ft_exit, &vars);
	mlx_loop(vars.mlx);
	return (0);
}

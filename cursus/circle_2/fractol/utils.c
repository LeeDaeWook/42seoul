/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:00:49 by daewoole          #+#    #+#             */
/*   Updated: 2023/02/14 10:15:04 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

int	ft_exit(t_vars *vars)
{
	(void) vars;
	exit(0);
}

void	print_list(void)
{
	printf("Availiable fractal list\n");
	printf("-> Mandelbrot Set\n");
	printf("-> Julia Set\n");
	printf("-> Burning ship\n");
}

int	validate_param(int argc, char *argv[], t_vars *vars)
{
	if (argc == 2 && (!ft_strncmp(argv[1], "Mandelbrot", \
					ft_strlen("Mandelbrot"))))
	{
		vars->which_set = 'm';
		return (1);
	}
	else if ((argc == 2 && !ft_strncmp(argv[1], "Julia", ft_strlen("Julia"))) \
			|| (argc == 3 && !ft_strncmp(argv[1], "Julia", ft_strlen("Julia"))))
	{
		vars->which_set = 'j';
		return (1);
	}
	else if (argc == 2 && !ft_strncmp(argv[1], "Burningship", \
				ft_strlen("Burningship")))
	{
		vars->which_set = 'b';
		return (1);
	}
	else
	{
		print_list();
		return (0);
	}
}

void	initializing(t_img *img, t_vars *vars, t_set *set)
{
	vars->img_width = IMG_WIDTH;
	vars->img_height = IMG_HEIGHT;
	vars->img = img;
	vars->set = set;
	vars->max_width = MAX_WIDTH;
	vars->min_width = MIN_WIDTH;
	vars->max_height = MAX_HEIGHT;
	vars->min_height = MIN_HEIGHT;
	vars->color_mul = COLOR_MUL;
	vars->redraw = 0;
}

void	into_fractal(int argc, char *argv[], t_vars *vars)
{
	if (vars->which_set == 'm')
	{
		vars->win = mlx_new_window(vars->mlx, W_WIDTH, W_HEIGHT, "Mandelbrot");
		mandelbrot(vars);
	}
	else if (vars->which_set == 'j')
	{
		if (argc == 2)
			vars->random_num = RANDOM_SEED;
		else if (argc == 3)
			vars->random_num = (unsigned int)ft_atoi(argv[2]);
		vars->win = mlx_new_window(vars->mlx, W_WIDTH, W_HEIGHT, "Julia");
		julia(vars);
	}
	else if (vars->which_set == 'b')
	{
		vars->win = mlx_new_window(vars->mlx, W_WIDTH, W_HEIGHT, "Burningship");
		burningship(vars);
	}
}

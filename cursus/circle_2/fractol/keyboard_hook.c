/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 09:52:41 by daewoole          #+#    #+#             */
/*   Updated: 2023/02/14 10:10:24 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == ESC_KEY)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	else if (keycode == LEFT_KEY || keycode == RIGHT_KEY \
			|| keycode == DOWN_KEY || keycode == UP_KEY)
	{
		arrow_move(keycode, vars);
		vars->redraw = 1;
		redrawing(vars);
	}
	else if (keycode == C_KEY)
	{
		vars->color_mul = (vars->color_mul * RANDOM_A + RANDOM_C) \
						% (ITERATION + 1);
		vars->redraw = 1;
		redrawing(vars);
	}
	return (0);
}

void	arrow_move(int keycode, t_vars *vars)
{
	double	ax;
	double	ay;

	ax = (vars->max_width - vars->min_width) / IMG_WIDTH;
	ay = (vars->max_height - vars->min_height) / IMG_HEIGHT;
	if (keycode == LEFT_KEY || keycode == RIGHT_KEY)
	{
		if (keycode == LEFT_KEY)
			ax *= -1;
		vars->min_width = vars->min_width + ax * MOVE_RATE;
		vars->max_width = vars->max_width + ax * MOVE_RATE;
	}
	else if (keycode == DOWN_KEY || keycode == UP_KEY)
	{
		if (keycode == DOWN_KEY)
			ay *= -1;
		vars->min_height = vars->min_height + ay * MOVE_RATE;
		vars->max_height = vars->max_height + ay * MOVE_RATE;
	}
}

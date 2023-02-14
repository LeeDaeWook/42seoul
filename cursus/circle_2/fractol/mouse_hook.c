/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daewoole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 09:58:47 by daewoole          #+#    #+#             */
/*   Updated: 2023/02/14 10:10:57 by daewoole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

int	mouse_zoom(t_vars *vars)
{
	double	ax;
	double	ay;

	ax = (vars->max_width - vars->min_width) / IMG_WIDTH;
	ay = (vars->max_height - vars->min_height) / IMG_HEIGHT;
	if (vars->button == SCROLL_DOWN)
	{
		vars->min_width = (vars->min_width + (ax * vars->x * ZOOM_RATE));
		vars->max_width = (vars->max_width - (ax * (IMG_WIDTH - vars->x) \
					* ZOOM_RATE));
		vars->max_height = (vars->max_height - (ay * vars->y * ZOOM_RATE));
		vars->min_height = (vars->min_height + (ay * (IMG_HEIGHT - vars->y) \
					* ZOOM_RATE));
	}
	else if (vars->button == SCROLL_UP)
	{
		vars->min_width = vars->min_width - ZOOM_RATE;
		vars->max_width = vars->max_width + ZOOM_RATE;
		vars->max_height = vars->max_height + ZOOM_RATE;
		vars->min_height = vars->min_height - ZOOM_RATE;
	}
	redrawing(vars);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	if (button == SCROLL_UP || button == SCROLL_DOWN)
	{
		vars->button = button;
		vars->x = x;
		vars->y = y;
		vars->redraw = 1;
		mouse_zoom(vars);
	}
	return (0);
}

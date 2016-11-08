/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_key_pt2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpichon <anpichon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 17:23:55 by anpichon          #+#    #+#             */
/*   Updated: 2016/11/08 02:48:46 by anpichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		key_scroll(int key, int x, int y, t_fractol *e)
{
	double		xt;
	double		yt;

	if (y > 0)
	{
		xt = ((double)x / e->zoom) + e->x1;
		yt = ((double)y / e->zoom) + e->y1;
		if (key == 4)
		{
			e->zoom *= 1.1;
			e->x1 = xt - ((double)x / e->zoom);
			e->y1 = yt - ((double)y / e->zoom);
		}
		else if (key == 5)
		{
			e->zoom *= 0.9;
			e->x1 = xt - ((double)x / e->zoom);
			e->y1 = yt - ((double)y / e->zoom);
		}
		draw(e, 1);
	}
	return (0);
}

int		motion(int x, int y, t_fractol *e)
{
	e->mx = x;
	if (e->mx < 0)
		e->mx = 0;
	if (e->mx >= e->img_x)
		e->mx = e->img_x - 1;
	e->my = y;
	if (e->my < 0)
		e->my = 0;
	if (e->my >= e->img_y)
		e->my = e->img_y - 1;
	if (!e->mo % 2)
	{
		e->c_r = (float)(x + 400 - y) / 300;
		e->c_i = (float)(x + 400 - y) / 300;
		draw(e, 1);
	}
	return (0);
}

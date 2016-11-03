/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_view.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpichon <anpichon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 17:53:09 by anpichon          #+#    #+#             */
/*   Updated: 2016/11/03 10:21:09 by anpichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static t_cal	cal_i(int y, int x, int z, t_fdf *e)
{
	t_cal	cal;

	init_color(e, z);
	cal.x_cal = e->mv_x + ((x * e->zoom) - (y * e->zoom));
	cal.y_cal = e->mv_y - ((sqrt(2.0 / 3.0) * (z * e->zoom / e->deep)) -
			((1 / sqrt(e->incl)) * (e->zoom * (x + y))));
	return (cal);
}

void			tab_to_iso(t_fdf *e)
{
	t_cal	p;
	t_cal	p2;

	e->x = 0;
	e->y = 0;
	while (e->y < e->y_max)
	{
		while (e->x < e->x_max[e->y])
		{
			p = cal_i(e->y, e->x, e->data[e->y][e->x], e);
			e->x++;
			if (e->x < e->x_max[e->y])
			{
				p2 = cal_i(e->y, e->x, e->data[e->y][e->x], e);
				print_line(p, p2, e);
			}
			if (e->y < e->y_max - 1)
			{
				p2 = cal_i(e->y + 1, e->x - 1, e->data[e->y + 1][e->x - 1], e);
				print_line(p, p2, e);
			}
		}
		e->x = 0;
		e->y++;
	}
}

static t_cal	cal_pa(int y, int x, int z, t_fdf *e)
{
	t_cal	cal;

	cal.x_cal = e->mv_x + ((1.2 * x) - (0.1 * (z * e->deep))) * e->zoom;
	cal.y_cal = e->mv_y + ((1.0 * y) - (0.1 * (z * e->deep))) * e->zoom;
	return (cal);
}

void			tab_to_para(t_fdf *e)
{
	t_cal	p;
	t_cal	p2;

	e->x = 0;
	e->y = 0;
	while (e->y < e->y_max)
	{
		while (e->x < e->x_max[e->y])
		{
			p = cal_pa(e->y, e->x, e->data[e->y][e->x], e);
			e->x++;
			if (e->x < e->x_max[e->y])
			{
				p2 = cal_pa(e->y, e->x, e->data[e->y][e->x], e);
				print_line(p, p2, e);
			}
			if (e->y < e->y_max - 1)
			{
				p2 = cal_pa(e->y + 1, e->x - 1, e->data[e->y + 1][e->x - 1], e);
				print_line(p, p2, e);
			}
		}
		e->x = 0;
		e->y++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpichon <anpichon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 07:25:48 by anpichon          #+#    #+#             */
/*   Updated: 2016/11/04 18:10:50 by anpichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	new_img(t_fdf *e)
{
	e->img = mlx_new_image(e->mlx, W, H);
	e->data_img = mlx_get_data_addr(e->img, &(e->bpp), &(e->sl), &(e->en));
	if (e->iso == 1 && e->para == 0)
		tab_to_iso(e);
	else if (e->iso == 0 && e->para == 1)
		tab_to_para(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	display_menu(e);
	mlx_destroy_image(e->mlx, e->img);
}

void	print_line(t_cal p1, t_cal p2, t_fdf *e)
{
	t_bress		a;

	a.dx = abs((p2.x_cal - p1.x_cal));
	a.sx = p1.x_cal < p2.x_cal ? 1 : -1;
	a.dy = abs((p2.y_cal - p1.y_cal));
	a.sy = p1.y_cal < p2.y_cal ? 1 : -1;
	a.err = (a.dx > a.dy ? a.dx : -a.dy) / 2;
	while (!(p1.x_cal == p2.x_cal && p1.y_cal == p2.y_cal))
	{
		mlx_print_pixel(p1.x_cal, p1.y_cal, e);
		a.e2 = a.err;
		if (a.e2 > -a.dx)
		{
			a.err -= a.dy;
			p1.x_cal += a.sx;
		}
		if (a.e2 < a.dy)
		{
			a.err += a.dx;
			p1.y_cal += a.sy;
		}
	}
}

void	mlx_print_pixel(int x, int y, t_fdf *e)
{
	if (x >= 0 && y >= 0 && x < W && y < H)
	{
		e->data_img[(e->sl * y) + (4 * x) + e->var] = e->c_r;
		e->data_img[(e->sl * y) + (4 * x) + e->var1] = e->c_g;
		e->data_img[(e->sl * y) + (4 * x) + e->var2] = e->c_b;
	}
}

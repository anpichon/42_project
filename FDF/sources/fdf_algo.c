/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpichon <anpichon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 07:25:48 by anpichon          #+#    #+#             */
/*   Updated: 2016/11/03 10:16:20 by anpichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	new_img(t_fdf *e)
{
	e->m->img = mlx_new_image(e->m->mlx, W, H);
	e->m->data = mlx_get_data_addr(e->m->img,
			&(e->m->bpp), &(e->m->sl), &(e->m->en));
	if (e->iso == 1 && e->para == 0)
		tab_to_iso(e);
	else if (e->iso == 0 && e->para == 1)
		tab_to_para(e);
	mlx_put_image_to_window(e->m->mlx, e->m->win, e->m->img, 0, 0);
	display_menu(e);
	mlx_destroy_image(e->m->mlx, e->m->img);
}

void	print_line(t_cal p1, t_cal p2, t_fdf *e)
{
	e->b->dx = abs((p2.x_cal - p1.x_cal));
	e->b->sx = p1.x_cal < p2.x_cal ? 1 : -1;
	e->b->dy = abs((p2.y_cal - p1.y_cal));
	e->b->sy = p1.y_cal < p2.y_cal ? 1 : -1;
	e->b->err = (e->b->dx > e->b->dy ? e->b->dx : -e->b->dy) / 2;
	while (!(p1.x_cal == p2.x_cal && p1.y_cal == p2.y_cal))
	{
		mlx_print_pixel(p1.x_cal, p1.y_cal, e);
		e->b->e2 = e->b->err;
		if (e->b->e2 > -e->b->dx)
		{
			e->b->err -= e->b->dy;
			p1.x_cal += e->b->sx;
		}
		if (e->b->e2 < e->b->dy)
		{
			e->b->err += e->b->dx;
			p1.y_cal += e->b->sy;
		}
	}
}

void	mlx_print_pixel(int x, int y, t_fdf *e)
{
	if (x >= 0 && y >= 0 && x < W && y < H)
	{
		e->m->data[(e->m->sl * y) + (4 * x) + e->var] = e->m->c_r;
		e->m->data[(e->m->sl * y) + (4 * x) + e->var1] = e->m->c_g;
		e->m->data[(e->m->sl * y) + (4 * x) + e->var2] = e->m->c_b;
	}
}

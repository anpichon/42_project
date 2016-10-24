/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 07:25:48 by anpichon          #+#    #+#             */
/*   Updated: 2016/10/05 07:25:53 by anpichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			new_img(t_fdf *e)
{
	e->img = mlx_new_image(e->mlx, WDH, HGHT);
	e->data_img = mlx_get_data_addr(e->img, &(e->bpp), &(e->s_l), &(e->endian));
	if (e->iso == 1 && e->para == 0)
		tab_to_iso(e);
	else if (e->iso == 0 && e->para == 1)
		tab_to_para(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	display_menu(e);
	mlx_destroy_image(e->mlx, e->img);
}

void print_line(int x0, int x1, int y0, int y1, t_fdf *info)
{
    info->dx = abs(x1-x0);
    info->dy = abs(y1-y0);
    info->sx = x0<x1 ? 1 : -1;
    info->sy = y0<y1 ? 1 : -1;
    info->err = (dx>dy ? dx : -dy);
    while (x0 != x1 && y0 != y1)
    {
      mlx_print_pixel(x0, y0, &info);
      e2 = err;
      if (e2 > -dx)
      {
        err -= dy;
        x0 +=sx;
      }
      if (e2 < dy)
      {
        err += dx;
        y0 += sy;
      }
    }
}

void mlx_print_pixel(int x, int y, t_fdf info)
{
  if (x >= 0 && y >= 0 && x < WIDTH && y < HEIGHT)
	{
		e->data_img[(info->m->size_line * y) + (4 * x) + e->c.var] = e->c_r;
		e->data_img[(info->m->size_line * y) + (4 * x) + e->c.var1] = e->c_g;
		e->data_img[(info->m->size_line * y) + (4 * x) + e->c.var2] = e->c_b;
	}
}

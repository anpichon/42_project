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
	e->m->img = mlx_new_image(e->mlx, W, H);
	e->m->data = mlx_get_data_addr(e->img, &(e->m->bpp), &(e->m->sl), &(e->m->en));
	mlx_put_image_to_window(e->m->mlx, e->m->win, e->m->img, 0, 0);
	//display_menu(e);
	mlx_destroy_image(e->m->mlx, e->m->img);
}

void print_line(t_fdf *info)
{
    info->dx = abs(info->l->x1 - info->l->x0);
    info->dy = abs(info->l->y1 - info->l->y0);
    info->sx = info->l->x0 < info->l->x1 ? 1 : -1;
    info->sy = info->l->y0 < info->l->y1 ? 1 : -1;
    info->err = (info->dx > info->dy ? info->dx : -info->dy);
    while (x0 != x1 && y0 != y1)
    {
      mlx_print_pixel(info->l->x0, info->l->y0, &info);
      info->e2 = info->err;
      if (info->e2 > -info->dx)
      {
        info->err -= info->dy;
        info->l->x0 += info->sx;
      }
      if (info->e2 < info->dy)
      {
        info->err += info->dx;
        info->l->y0 += info->sy;
      }
    }
}

void mlx_print_pixel(int x, int y, t_fdf e)
{
  if (x >= 0 && y >= 0 && x < W && y < H)
	{
		e->data_img[(info->m->size_line * y) + (4 * x) + 2] = e->r;
		e->data_img[(info->m->size_line * y) + (4 * x) + 1] = e->g;
		e->data_img[(info->m->size_line * y) + (4 * x)] = e->b;
	}
}

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
  info->m->
}

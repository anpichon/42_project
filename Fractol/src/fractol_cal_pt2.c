/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_cal_pt2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpichon <anpichon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 18:33:42 by anpichon          #+#    #+#             */
/*   Updated: 2016/11/08 03:36:02 by anpichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	burning(t_fractol *e)
{
	e->img_x = W;
	e->img_y = H;
	e->x = -1;
	while (++e->x < e->img_x)
	{
		e->y = -1;
		while (++e->y < e->img_y)
		{
			e->c_r = (double)e->x / e->zoom + e->x1;
			e->c_i = (double)e->y / e->zoom + e->y1;
			e->z_r = 0;
			e->z_i = 0;
			e->i = -1;
			while (e->z_r * e->z_r + e->z_i * e->z_i < 4 && ++e->i < e->it_max)
			{
				e->tmp = e->z_r;
				e->z_r = fabs(e->z_r * e->z_r - e->z_i * e->z_i + e->c_r);
				e->z_i = fabs(2 * e->z_i * e->tmp + e->c_i);
				e->i++;
			}
			choice_color(e);
		}
	}
}

void	my_fractal(t_fractol *e)
{
	e->img_x = W;
	e->img_y = H;
	e->x = -1;
	while (++e->x < e->img_x)
	{
		e->c_r = (double)e->x / e->zoom + e->x1;
		e->y = -1;
		while (++e->y < e->img_y)
		{
			e->c_i = (double)e->y / e->zoom + e->y1;
			e->z_r = 0;
			e->z_i = 0;
			e->i = -1;
			while (e->z_r * e->z_r + e->z_i * e->z_i < 4 && ++e->i < e->it_max)
			{
				e->tmp = e->z_r;
				e->z_r = e->z_r * e->z_r - e->z_i * e->z_i + e->c_r;
				e->z_i = 2 * e->z_i * e->tmp + e->c_i;
			}
			choice_color(e);
		}
	}
}

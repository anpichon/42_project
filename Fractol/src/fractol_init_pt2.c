/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init_pt2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpichon <anpichon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 17:56:35 by anpichon          #+#    #+#             */
/*   Updated: 2016/11/08 03:55:23 by anpichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_julia(t_fractol *e)
{
	ft_putstr("Fractol : Your choice is : [Julia] !\n");
	e->x1 = -3.3;
	e->x2 = 2.0;
	e->y1 = -2.2;
	e->y2 = 1.2;
	e->c_r = -0.64;
	e->c_i = -0.38;
	e->zoom = 130;
	e->x1 -= 1.20 / (e->zoom / 100);
	e->y1 -= 0.90 / (e->zoom / 100);
}

void	init_julia1(t_fractol *e)
{
	ft_putstr("Fractol : Your choice is : [Julia1] !\n");
	e->x1 = -3.5;
	e->x2 = 2.5;
	e->y1 = -2.5;
	e->y2 = 3;
	e->c_r = 0.286;
	e->c_i = 0.01;
	e->zoom = 130;
	e->x1 -= 1 / (e->zoom / 100);
	e->y1 -= 0.70 / (e->zoom / 100);
}

void	init_julia2(t_fractol *e)
{
	ft_putstr("Fractol : Your choice is : [Julia2] !\n");
	e->x1 = -3.3;
	e->x2 = 2.5;
	e->y1 = -2.5;
	e->y2 = 2.4;
	e->c_r = -0.11;
	e->c_i = -0.24;
	e->zoom = 130;
	e->x1 -= 1.20 / (e->zoom / 100);
	e->y1 -= 0.70 / (e->zoom / 100);
}

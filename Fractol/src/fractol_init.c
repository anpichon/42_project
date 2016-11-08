/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpichon <anpichon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:47:42 by anpichon          #+#    #+#             */
/*   Updated: 2016/11/08 05:38:44 by anpichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_mandelbrot(t_fractol *e)
{
	ft_putstr("Fractol : Your choice is : [Mandelbrot] !\n");
	e->x1 = -3.1;
	e->x2 = 1.0;
	e->y1 = -2.6;
	e->y2 = 1.9;
	e->zoom = 130;
	e->it_max = 150;
	e->x1 -= 1 / (e->zoom / 100);
	e->y1 -= 0.80 / (e->zoom / 100);
}

void	init_burning(t_fractol *e)
{
	ft_putstr("Fractol : Your choice is : [Burning] !\n");
	e->x1 = -3.0;
	e->x2 = 2.5;
	e->y1 = -2.6;
	e->y2 = 3;
	e->zoom = 130;
	e->it_max = 300;
	e->x1 -= 1.60 / (e->zoom / 100);
	e->y1 -= 0.50 / (e->zoom / 100);
}

void	init_create_perso(t_fractol *e)
{
	ft_putstr("Fractol : Your choice is : [My Fractal] !\n");
	e->x1 = -1.6;
	e->x2 = 1.5;
	e->y1 = -0.2;
	e->y2 = 1.5;
	e->zoom = 130;
	e->x1 -= 3.10 / (e->zoom / 100);
	e->y1 -= 3 / (e->zoom / 100);
}

void	init_tools(t_fractol *e)
{
	e->m.red = 10;
	e->m.green = 170;
	e->zoom = 130;
	e->m.blue = 90;
	e->c2 = 1;
	e->mo = 0;
	e->it_max = 150;
	if (e->ch == 1)
		init_mandelbrot(e);
	if (e->ch == 2)
		init_julia(e);
	if (e->ch == 3)
		init_julia1(e);
	if (e->ch == 4)
		init_julia2(e);
	if (e->ch == 5)
		init_burning(e);
	if (e->ch == 6)
		init_create_perso(e);
}

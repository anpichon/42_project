/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpichon <anpichon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 17:05:12 by anpichon          #+#    #+#             */
/*   Updated: 2016/11/08 06:10:44 by anpichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	key_iter(int key, t_fractol *e)
{
	if (key == 69 || key == 34)
		e->it_max += 2;
	else if (key == 78 || key == 32)
	{
		e->it_max -= 2;
		if (e->it_max == 0)
			e->it_max = 2;
	}
}

void	key_move_zoom(int key, t_fractol *e)
{
	if (key == 123)
		e->x1 += 0.25 / (e->zoom / 100);
	else if (key == 124)
		e->x1 -= 0.25 / (e->zoom / 100);
	else if (key == 126)
		e->y1 += 0.5 / (e->zoom / 100);
	else if (key == 125)
		e->y1 -= 0.5 / (e->zoom / 100);
	else if (key == 3)
	{
		if (e->ch == 6)
			e->ch = 1;
		else
			e->ch++;
		draw(e, 3);
	}
}

void	key_choice_color(int key, t_fractol *e)
{
	if (key == 9)
	{
		e->c2++;
		if (e->c2 > 9)
			e->c2 = 1;
	}
	else if (key == 8)
	{
		if (e->c1 == 1)
			e->c1 -= 1;
		else
			e->c1 += 1;
	}
	else if (key == 83)
		e->m.red += 2;
	else if (key == 84)
		e->m.green += 2;
	else if (key == 85)
		e->m.blue += 2;
}

void	key_zoom(int key, t_fractol *e)
{
	if (key == 24)
		e->zoom += 10;
	else if (key == 27)
	{
		if (e->zoom - 10 != 0)
			e->zoom -= 10;
	}
}

int		key(int key, t_fractol *e)
{
	if (key == 53)
		die("Fractol : Générate successful ! Exiting ...", EXIT_SUCCESS);
	else if (key == 15)
		draw(e, 3);
	else if (key == 69 || key == 32 || key == 34 || key == 78)
		key_iter(key, e);
	else if (key == 46)
		e->mo++;
	else if (key == 123 || key == 124 || key == 125 || key == 126 || key == 3)
		key_move_zoom(key, e);
	else if (key == 27 || key == 24)
		key_zoom(key, e);
	else if (key == 8 || key == 9 || key == 83 || key == 84 || key == 85)
		key_choice_color(key, e);
	draw(e, 1);
	return (1);
}

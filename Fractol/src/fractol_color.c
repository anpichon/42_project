/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpichon <anpichon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 17:41:05 by anpichon          #+#    #+#             */
/*   Updated: 2016/11/07 23:12:59 by anpichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	color(int i, t_fractol *e)
{
	if (i == 1)
		WHITE;
	if (i == 2)
		BLACK;
	if (i == 3)
		C1BR;
	if (i == 4)
		C1BG;
	if (i == 5)
		C1RG;
	if (i == 6)
		CRAD;
	if (i == 7)
		CRAD1;
	if (i == 8)
		CRAD2;
	if (i == 9)
		CRAD3;
	if (i == 10)
		C1BR1;
}

void	choice_color(t_fractol *e)
{
	if (e->i == e->it_max && e->c1 == 0)
		color(1, e);
	else if (e->i == e->it_max && e->c1 == 1)
		color(2, e);
	else if (e->i != e->it_max && e->c2 == 1)
		color(3, e);
	else if (e->i != e->it_max && e->c2 == 2)
		color(4, e);
	else if (e->i != e->it_max && e->c2 == 3)
		color(5, e);
	else if (e->i != e->it_max && e->c2 == 4)
		color(6, e);
	else if (e->i != e->it_max && e->c2 == 5)
		color(7, e);
	else if (e->i != e->it_max && e->c2 == 6)
		color(8, e);
	else if (e->i != e->it_max && e->c2 == 7)
		color(9, e);
	else if (e->i != e->it_max && e->c2 == 8)
		color(10, e);
	else if (e->i != e->it_max && e->c2 == 9)
		CDBR;
}

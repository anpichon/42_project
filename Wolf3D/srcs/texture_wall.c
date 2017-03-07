/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpichon <anpichon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 18:46:14 by anpichon          #+#    #+#             */
/*   Updated: 2017/03/07 08:48:06 by anpichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		drawmap(t_wolf *e)
{
	int 	i;
	int 	j;
	int		k;

	i = -1;
	while (++i < MH - 1)
	{
		j = -1;
		while (++j < MW)
		{
			if (e->m.map[i][j] > 0)
				setcolor(e, 128, 128, 128);
			else
				setcolor(e, 255, 255, 255);
			k = -1;
			while (++k != 25)
				drawpoint(e, j * 5 + k % 5, i * 5 + k / 5);
		}
	}
	setcolor(e, 255, 0, 0);
	k = -1;
	while (++k != 25)
		drawpoint(e, e->m.p_y * 5 + k % 5, e->m.p_x * 5 + k / 5);

}

void		drawpoint(t_wolf *e, int x, int y)
{
	int				index;
	unsigned char	*pix;

	pix = (unsigned char *)e->s.srf->pixels;
	index = ((y * W + x) * 4);
	pix[index] = e->rgb[2];
	pix[index + 1] = e->rgb[1];
	pix[index + 2] = e->rgb[0];
	pix[index + 3] = 255;
}

void		drawline(t_wolf *e, int x, int y1, int y2)
{
	while (y1 < y2)
	{
		if (y1 >= 0 && y1 < H)
			drawpoint(e, x, y1);
		y1++;
	}
}

void		setcolor(t_wolf *e, int r, int g, int b)
{
	e->rgb[0] = r;
	e->rgb[1] = g;
	e->rgb[2] = b;
}

void		color(t_wolf *e)
{
	setcolor(e, 0, 255, 255);
	drawline(e, e->x, 0, e->r.dr_s);
	if (e->side == 0 && e->r.dx > 0)
		setcolor(e, 240, 210, 70);
	else if (e->side == 0 && e->r.dx < 0)
		setcolor(e, 223, 109, 20);
	else if (e->side == 1 && e->r.dy > 0)
		setcolor(e, 200, 173, 127);
	else
		setcolor(e, 98, 91, 72);
	drawline(e, e->x, e->r.dr_s, e->r.dr_e);
	setcolor(e, 155, 155, 155);
	drawline(e, e->x, e->r.dr_e, H);
}

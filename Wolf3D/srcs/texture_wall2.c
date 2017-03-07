/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_wall2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpichon <anpichon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 03:02:03 by anpichon          #+#    #+#             */
/*   Updated: 2017/03/07 07:41:20 by anpichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void	drawlinetexwall(t_wolf *e, int x, int y1, int y2)
{
	int				i;
	int				th;
	int				ty;
	unsigned char	*pix;
	int				index;

	pix = (unsigned char *)e->s.wall->pixels;
	th = y2 - y1;
	i = -1;
	while (++i < th)
	{
		if (y1 + i < 0 || y1 + i >= H)
			continue ;
		ty = (int)((float)i / (float)th * (float)e->s.wall->h);
		index = (ty * e->s.wall->w + e->tx) * e->s.wall->format->BytesPerPixel;
		setcolor(e, pix[index + 2], pix[index + 1], pix[index]);
		drawpoint(e, x, y1 + i);
	}
}

static void	drawlinetexfloor(t_wolf *e, int x, int y1, int y2)
{
	int				ty;
	int				id;
	unsigned char	*pix;

	pix = (unsigned char *)e->s.floor->pixels;
	e->fl[0] = (e->r.dx > 0) ? e->m.x : e->m.x + 1.0;
	e->fl[1] = e->m.y + e->wallx;
	if (e->side == 1)
	{
		e->fl[0] = e->m.x + e->wallx;
		e->fl[1] = (e->r.dy > 0) ? e->m.y : e->m.y + 1.0;
	}
	while (y1 < y2)
	{
		if (y1 < 0 || y1 >= H)
			continue ;
		e->weight = (H / (2.0 * y1 - H) / (e->r.pwd));
		e->tx = (int)((e->weight * e->fl[0] + (1.0 - e->weight) * e->m.p_x)
			* (float)e->s.floor->w) % e->s.floor->w;
		ty = (int)((e->weight * e->fl[1] + (1.0 - e->weight) * e->m.p_y)
			* (float)e->s.floor->h) % e->s.floor->h;
		id = (ty * e->s.floor->w + e->tx) * e->s.floor->format->BytesPerPixel;
		setcolor(e, pix[id + 2], pix[id + 1], pix[id]);
		drawpoint(e, x, y1++);
	}
}

static void	drawlinetexceiling(t_wolf *e, int x, int y1, int y2)
{
	int				ty;
	int				id;
	unsigned char	*pix;

	pix = (unsigned char *)e->s.ceil->pixels;
	e->fl[0] = (e->r.dx > 0) ? e->m.x : e->m.x + 1.0;
	e->fl[1] = e->m.y + e->wallx;
	if (e->side == 1)
	{
		e->fl[0] = e->m.x + e->wallx;
		e->fl[1] = (e->r.dy > 0) ? e->m.y : e->m.y + 1.0;
	}
	while (y1 < y2)
	{
		if (y1 < 0 || y1 >= H)
			continue ;
		e->weight = ((H / (2.0 * (H - y1) - H)) / (e->r.pwd));
		e->tx = (int)((e->weight * e->fl[0] + (1.0 - e->weight) * e->m.p_x)
			* (float)e->s.ceil->w) % e->s.ceil->w;
		ty = (int)((e->weight * e->fl[1] + (1.0 - e->weight) * e->m.p_y)
			* (float)e->s.ceil->h) % e->s.ceil->h;
		id = (ty * e->s.ceil->w + e->tx) * e->s.ceil->format->BytesPerPixel;
		setcolor(e, pix[id + 2], pix[id + 1], pix[id]);
		drawpoint(e, x, y1++);
	}
}

void		color2(t_wolf *e)
{
	if (e->side == 0)
		e->wallx = e->r.py + e->r.pwd * e->r.dy;
	else
		e->wallx = e->r.px + e->r.pwd * e->r.dx;
	e->wallx -= floor(e->wallx);
	e->tx = (int)(e->wallx * (float)e->s.wall->w);
	if ((e->side == 0 && e->r.dx > 0) || (e->side == 1 && e->r.dy < 0))
		e->tx = e->s.wall->w - e->tx - 1;
	drawlinetexwall(e, e->x, e->r.dr_s, e->r.dr_e);
	drawlinetexfloor(e, e->x, e->r.dr_e, H);
	drawlinetexceiling(e, e->x, 0, e->r.dr_s);
}

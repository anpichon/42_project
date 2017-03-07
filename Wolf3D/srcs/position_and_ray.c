/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_and_ray.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpichon <anpichon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 19:16:04 by anpichon          #+#    #+#             */
/*   Updated: 2017/03/07 08:59:36 by anpichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void			dda(t_wolf *e)
{
	while (e->r.hit == 0)
	{
		if (e->r.sdx < e->r.sdy)
		{
			e->r.sdx += e->r.ddx;
			e->m.x += e->r.sx;
			e->side = 0;
		}
		else
		{
			e->r.sdy += e->r.ddy;
			e->m.y += e->r.sy;
			e->side = 1;
		}
		if (e->m.map[e->m.x][e->m.y] > 0)
			e->r.hit = 1;
	}
}

static void			ray_d(t_wolf *e)
{
	if (e->r.dx < 0)
	{
		e->r.sx = -1;
		e->r.sdx = (e->r.px - e->m.x) * e->r.ddx;
	}
	else
	{
		e->r.sx = 1;
		e->r.sdx = (e->m.x + 1.0 - e->r.px) * e->r.ddx;
	}
	if (e->r.dy < 0)
	{
		e->r.sy = -1;
		e->r.sdy = (e->r.py - e->m.y) * e->r.ddy;
	}
	else
	{
		e->r.sy = 1;
		e->r.sdy = (e->m.y + 1.0 - e->r.py) * e->r.ddy;
	}
}

static void			calcul_proj(t_wolf *e)
{
	if (e->side == 0)
		e->r.pwd = (e->m.x - e->r.px + (1 - e->r.sx) / 2) / e->r.dx;
	else
		e->r.pwd = (e->m.y - e->r.py + (1 - e->r.sy) / 2) / e->r.dy;
	e->r.lh = (int)(H / e->r.pwd);
	e->r.dr_s = -e->r.lh / 2 + H / 2;
	e->r.dr_e = e->r.lh / 2 + H / 2;
}

static void			ray_i(t_wolf *e)
{
	e->r.camx = 2 * e->x / (double)W - 1;
	e->r.px = e->m.p_x;
	e->r.py = e->m.p_y;
	e->r.dx = e->d.dix + e->d.plx * e->r.camx;
	e->r.dy = e->d.diy + e->d.ply * e->r.camx;
	e->m.x = (int)e->r.px;
	e->m.y = (int)e->r.py;
	e->r.ddx = sqrt(1 + (e->r.dy * e->r.dy) / (e->r.dx * e->r.dx));
	e->r.ddy = sqrt(1 + (e->r.dx * e->r.dx) / (e->r.dy * e->r.dy));
	e->r.hit = 0;
}

void				ray(t_wolf *e)
{
	while (!e->loop)
	{
		event(e);
		e->x = -1;
		while (++e->x < W)
		{
			ray_i(e);
			ray_d(e);
			dda(e);
			calcul_proj(e);
			if (e->tex % 2 == 1)
				color2(e);
			else
				color(e);
		}
		if (e->map)
			drawmap(e);
		SDL_UpdateWindowSurface(e->s.win);
	}
}

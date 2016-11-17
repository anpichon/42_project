/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_and_event.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpichon <anpichon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 19:10:06 by anpichon          #+#    #+#             */
/*   Updated: 2016/11/17 19:39:01 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void			sdlk1(t_wolf *e, short i)
{
	if (i)
	{
		if (!e->m.map[(int)(e->m.p_x + e->d.dix * e->d.ru)][(int)e->m.p_y])
			e->m.p_x += e->d.dix * e->d.ru;
		if (!e->m.map[(int)e->m.p_x][(int)(e->m.p_y + e->d.diy * e->d.ru)])
			e->m.p_y += e->d.diy * e->d.ru;
	}
	else
	{
		if (!e->m.map[(int)(e->m.p_x - e->d.dix * e->d.ru)][(int)e->m.p_y])
			e->m.p_x -= e->d.dix * e->d.ru;
		if (!e->m.map[(int)e->m.p_x][(int)(e->m.p_y - e->d.diy * e->d.ru)])
			e->m.p_y -= e->d.diy * e->d.ru;
	}
}

static void			sdlk2(t_wolf *e, short i)
{
	e->d.odx = e->d.dix;
	e->d.opx = e->d.plx;
	if (i)
	{
		e->d.dix = e->d.dix * cos(-e->d.rru) - e->d.diy * sin(-e->d.rru);
		e->d.diy = e->d.odx * sin(-e->d.rru) + e->d.diy * cos(-e->d.rru);
		e->d.plx = e->d.plx * cos(-e->d.rru) - e->d.ply * sin(-e->d.rru);
		e->d.ply = e->d.opx * sin(-e->d.rru) + e->d.ply * cos(-e->d.rru);
	}
	else
	{
		e->d.dix = e->d.dix * cos(e->d.rru) - e->d.diy * sin(e->d.rru);
		e->d.diy = e->d.odx * sin(e->d.rru) + e->d.diy * cos(e->d.rru);
		e->d.plx = e->d.plx * cos(e->d.rru) - e->d.ply * sin(e->d.rru);
		e->d.ply = e->d.opx * sin(e->d.rru) + e->d.ply * cos(e->d.rru);
	}
}

static void			sdlk3(t_wolf *e, short i)
{
	if (i)
	{
		if (!e->m.map[(int)(e->m.p_x + e->d.diy * e->d.ru)][(int)e->m.p_y])
			e->m.p_x += e->d.diy * e->d.ru;
		if (!e->m.map[(int)e->m.p_x][(int)(e->m.p_y - e->d.dix * e->d.ru)])
			e->m.p_y -= e->d.dix * e->d.ru;
	}
	else
	{
		if (!e->m.map[(int)(e->m.p_x - e->d.diy * e->d.ru)][(int)e->m.p_y])
			e->m.p_x -= e->d.diy * e->d.ru;
		if (!e->m.map[(int)e->m.p_x][(int)(e->m.p_y + e->d.dix * e->d.ru)])
			e->m.p_y += e->d.dix * e->d.ru;
	}
}

void				event(t_wolf *e)
{
	e->key = SDL_GetKeyboardState(NULL);
	SDL_PollEvent(&e->s.ev);
	if (e->key[SDL_SCANCODE_RIGHT])
		sdlk2(e, 1);
	if (e->key[SDL_SCANCODE_LEFT])
		sdlk2(e, 0);
	if (e->key[SDL_SCANCODE_UP] || e->key[SDL_SCANCODE_W])
		sdlk1(e, 1);
	if (e->key[SDL_SCANCODE_DOWN] || e->key[SDL_SCANCODE_S])
		sdlk1(e, 0);
	if (e->key[SDL_SCANCODE_A])
		sdlk3(e, 0);
	if (e->key[SDL_SCANCODE_D])
		sdlk3(e, 1);
	if (e->s.ev.key.keysym.sym == SDLK_r)
		init_game(e);
	if (e->s.ev.type == SDL_QUIT || e->s.ev.key.keysym.sym == SDLK_ESCAPE)
		e->loop = 1;
}

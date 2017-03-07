/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_and_event.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpichon <anpichon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 19:10:06 by anpichon          #+#    #+#             */
/*   Updated: 2017/03/07 08:54:33 by anpichon         ###   ########.fr       */
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
	double mcos;
	double msin;
	double pcos;
	double psin;

	mcos = cos(-e->d.rru);
	msin = sin(-e->d.rru);
	pcos = cos(e->d.rru);
	psin = sin(e->d.rru);
	e->d.odx = e->d.dix;
	e->d.opx = e->d.plx;
	if (i)
	{
		e->d.dix = e->d.dix * mcos - e->d.diy * msin;
		e->d.diy = e->d.odx * msin + e->d.diy * mcos;
		e->d.plx = e->d.plx * mcos - e->d.ply * msin;
		e->d.ply = e->d.opx * msin + e->d.ply * mcos;
	}
	else
	{
		e->d.dix = e->d.dix * pcos - e->d.diy * psin;
		e->d.diy = e->d.odx * psin + e->d.diy * pcos;
		e->d.plx = e->d.plx * pcos - e->d.ply * psin;
		e->d.ply = e->d.opx * psin + e->d.ply * pcos;
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

static void			event_bonus(t_wolf *e)
{
	if (e->s.ev.type == SDL_KEYDOWN)
	{
		if (e->s.ev.key.keysym.scancode == SDL_SCANCODE_T)
			e->tex = !e->tex;
		if (e->s.ev.key.keysym.scancode == SDL_SCANCODE_M)
			e->map = !e->map;
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
	event_bonus(e);
	e->d.ru = 0.040;
	if (e->key[SDL_SCANCODE_LSHIFT])
		e->d.ru = 0.080;
	if (e->s.ev.key.keysym.sym == SDLK_r)
		init_game(e);
	if (e->s.ev.type == SDL_QUIT || e->s.ev.key.keysym.sym == SDLK_ESCAPE)
		e->loop = 1;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpichon <anpichon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 18:48:58 by anpichon          #+#    #+#             */
/*   Updated: 2017/03/07 08:54:12 by anpichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void		map_cpy(int tmp[MH][MW], t_wolf *e)
{
	int		i;
	int		j;

	i = -1;
	while (++i < MH)
	{
		j = -1;
		while (++j < MW)
			e->m.map[i][j] = tmp[i][j];
	}
}

void			map(t_wolf *e)
{
	static int	map[22][23] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 2, 2, 2, 2, 0, 2, 0, 2, 0, 0, 2, 0, 2, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 2, 0, 2, 0, 2, 0, 0, 0, 0, 2, 0, 2, 2, 2, 2, 2, 1},
		{1, 2, 2, 2, 2, 0, 0, 0, 2, 0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 2, 2, 2, 0, 1},
		{1, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 2, 0, 0, 0, 2, 2, 0, 0, 0, 0, 2, 0, 0, 2, 0, 2, 2, 2, 2, 1},
		{1, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 2, 2, 0, 0, 2, 2, 0, 0, 0, 0, 2, 0, 0, 2, 2, 0, 0, 0, 0, 1},
		{1, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 1},
		{1, 2, 0, 0, 2, 2, 2, 2, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 1},
		{1, 2, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 2, 0, 0, 0, 0, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 1},
		{1, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 1},
		{1, 0, 0, 2, 0, 2, 0, 0, 2, 0, 0, 2, 0, 0, 2, 0, 0, 2, 2, 2, 2, 0, 1},
		{1, 0, 0, 2, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

	map_cpy(map, e);
}

static void		load_text(t_wolf *e)
{
	if ((e->s.wall = SDL_LoadBMP("srcs/texture/stone.bmp")))
		ft_putstr("Init Wall TEXTURE Success [OK]\n");
	else
		die("Init Wall TEXTURE failure !", e, EXIT_FAILURE);
	if ((e->s.floor = SDL_LoadBMP("srcs/texture/floor.bmp")))
		ft_putstr("Init Floor TEXTURE Success [OK]\n");
	else
		die("Init Floor TEXTURE failure !", e, EXIT_FAILURE);
	if ((e->s.ceil = SDL_LoadBMP("srcs/texture/ceiling.bmp")))
		ft_putstr("Init Ceiling TEXTURE Success [OK]\n");
	else
		die("Init Ceiling TEXTURE failure !", e, EXIT_FAILURE);
}

void			init_game(t_wolf *e)
{
	if (e->s.init != 1)
	{
		if (SDL_Init(SDL_INIT_VIDEO))
			die("Init SDL failure !", e, EXIT_FAILURE);
		e->s.init = 1;
		ft_putstr("Init SLD Success [OK]\n");
		e->s.win = SDL_CreateWindow("Wolf3D - anpichon", SDL_WINDOWPOS_CENTERED,
				SDL_WINDOWPOS_CENTERED, W, H, 0);
		ft_putstr("Init WIN Success [OK]\n");
		e->s.srf = SDL_GetWindowSurface(e->s.win);
		load_text(e);
	}
	e->m.p_x = 19;
	e->m.p_y = 5;
	map(e);
	e->d.dix = -1;
	e->d.diy = 0.0;
	e->d.plx = 0.0;
	e->d.ply = 0.66;
	e->d.ru = 0.040;
	e->d.rru = 0.05;
	ft_putstr("Init PARAM_MAP Success [OK]\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpichon <anpichon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 09:28:17 by anpichon          #+#    #+#             */
/*   Updated: 2017/03/07 08:54:52 by anpichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include <math.h>
# include <SDL2/SDL.h>
# include "../srcs/libft/libft.h"

# define W 1280
# define H 720
# define MH 22
# define MW 23

typedef struct		s_dir
{
	double			ru;
	double			dix;
	double			diy;
	double			plx;
	double			ply;
	double			rru;
	double			odx;
	double			opx;
}					t_dir;

typedef struct		s_map
{
	int				x;
	int				y;
	int				map[MH][MW];
	double			p_x;
	double			p_y;
}					t_map;

typedef struct		s_ray
{
	int				lh;
	int				sx;
	int				sy;
	int				hit;
	int				dr_e;
	int				dr_s;
	double			dx;
	double			dy;
	double			px;
	double			py;
	double			ddx;
	double			ddy;
	double			sdx;
	double			sdy;
	double			pwd;
	double			camx;
}					t_ray;

typedef struct		s_sdl
{
	int				init;
	SDL_Event		ev;
	SDL_Surface		*srf;
	SDL_Surface		*wall;
	SDL_Surface		*floor;
	SDL_Surface		*ceil;
	SDL_Window		*win;
}					t_sdl;

typedef struct		s_wolf
{
	int				x;
	int				tx;
	int				rgb[3];
	int				map;
	int				tex;
	t_sdl			s;
	t_map			m;
	t_ray			r;
	t_dir			d;
	short			side;
	short			loop;
	float			wallx;
	double			fl[2];
	double			weight;
	const Uint8		*key;
}					t_wolf;

void				map(t_wolf *e);
void				ray(t_wolf *e);
void				color(t_wolf *e);
void				event(t_wolf *e);
void				color2(t_wolf *e);
void				drawmap(t_wolf *e);
void				init_game(t_wolf *e);
void				drawpoint(t_wolf *e, int x, int y);
void				die(char *str, t_wolf *e, int exit_code);
void				setcolor(t_wolf *e, int r, int g, int b);
void				drawline(t_wolf *e, int x, int y1, int y2);

#endif

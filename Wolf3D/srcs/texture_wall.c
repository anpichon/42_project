/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpichon <anpichon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 18:46:14 by anpichon          #+#    #+#             */
/*   Updated: 2016/11/18 19:47:35 by anpichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	color(t_wolf *e)
{
	SDL_SetRenderDrawColor(e->s.ren, 0, 255, 255, 100);
	SDL_RenderDrawLine(e->s.ren, e->x, 0, e->x, e->r.dr_s);
	if (e->side == 0 && e->r.dx > 0)
		SDL_SetRenderDrawColor(e->s.ren, 240, 210, 70, 0);
	else if (e->side == 0 && e->r.dx < 0)
		SDL_SetRenderDrawColor(e->s.ren, 223, 109, 20, 0);
	else if (e->side == 1 && e->r.dy > 0)
		SDL_SetRenderDrawColor(e->s.ren, 200, 173, 127, 23);
	else
		SDL_SetRenderDrawColor(e->s.ren, 98, 91, 72, 110);
	SDL_RenderDrawLine(e->s.ren, e->x, e->r.dr_s, e->x, e->r.dr_e);
	SDL_SetRenderDrawColor(e->s.ren, 155, 155, 155, 100);
	SDL_RenderDrawLine(e->s.ren, e->x, e->r.dr_e, e->x, H);
}

void	color2(t_wolf *e)
{
	SDL_SetRenderDrawColor(e->s.ren, 0, 255, 255, 100);
	SDL_RenderDrawLine(e->s.ren, e->x, 0, e->x, e->r.dr_s);
	if (e->side == 0 && e->r.dx > 0)
		SDL_SetRenderDrawColor(e->s.ren, 0, 255, 0, 100);
	else if (e->side == 0 && e->r.dx < 0)
		SDL_SetRenderDrawColor(e->s.ren, 255, 0, 127, 100);
	else if (e->side == 1 && e->r.dy > 0)
		SDL_SetRenderDrawColor(e->s.ren, 255, 255, 5, 100);
	else
		SDL_SetRenderDrawColor(e->s.ren, 98, 91, 72, 110);
	SDL_RenderDrawLine(e->s.ren, e->x, e->r.dr_s, e->x, e->r.dr_e);
	SDL_SetRenderDrawColor(e->s.ren, 0, 255, 255, 100);
	SDL_RenderDrawLine(e->s.ren, e->x, e->r.dr_e, e->x, H);
}

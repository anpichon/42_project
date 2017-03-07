/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpichon <anpichon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 08:50:42 by anpichon          #+#    #+#             */
/*   Updated: 2017/03/07 02:11:26 by anpichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		die(char *str, t_wolf *e, int exit_code)
{
	if (e->s.init == 1)
	{
		SDL_FreeSurface(e->s.srf);
		SDL_DestroyWindow(e->s.win);
		SDL_Quit();
	}
	ft_putendl(str);
	exit(exit_code);
}

static void	help(void)
{
	ft_putstr("./wolf3d Usage : <- without argument - Default maps\n");
	ft_putstr("                 <- GoodGame !\n");
	die("", NULL, EXIT_FAILURE);
}

int			main(int ac, char **av)
{
	t_wolf	e;

	if (ac == 1 && av && ft_memset(&e, 0, sizeof(e)))
	{
		init_game(&e);
		ray(&e);
	}
	else
		help();
	return (0);
}

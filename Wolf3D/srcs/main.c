/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpichon <anpichon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 08:50:42 by anpichon          #+#    #+#             */
/*   Updated: 2016/11/14 09:36:12 by anpichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	die(char *str, t_wolf *e, int exit_code)
{
	ft_putendl(str);
	exit(exit_code);
}

void	help(void)
{
	ft_putstr("./wolf3d Usage : <- without argument - Default maps\n");
	ft_putstr("                 <- with arguments - <filename.wolf3d>\n");
	ft_putstr("                 <- Map parsing is strict !\n");
	ft_putstr("                 <- 0 = Empty\n1 = Principal piece\n");
	ft_putstr("                 <- 2 = Piece in principal piece\n");
	ft_putstr("                 <- 3 = Obstacle\n4 = Secret passage");
	ft_putstr("                 <- 5 = Ennemy\n");
	ft_putstr("                 <- GoodGame !\n");
	die("", NULL, EXIT_FAILURE);
}

int		main(int ac, char **av)
{
	t_wolf		e;

	(void)e;
	if (ac == 2 && ft_strcmp(av[1], "--Help")
		help();
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpichon <anpichon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 07:25:59 by anpichon          #+#    #+#             */
/*   Updated: 2016/11/02 05:50:20 by anpichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	die(char *s, t_fdf *e, int exit_code)
{
	ft_putendl(s);
	if (e)
	{
		mlx_destroy_image(e->m.mlx, e->m.img);
	}
	exit(exit_code);
}

t_fdf	*fdf(t_fdf *e)
{
	static t_fdf	*pe = NULL;

	if (e)
		pe = e;
	return (pe);
}

void	*try(size_t size)
{
	void	*p;

	if ((p = ft_memalloc(size)) == NULL)
		die("Not enough memory", fdf(NULL), EXIT_FAILURE);
	return (p);
}

int   main(int ac, char **av)
{
	t_fdf   e;

	ft_bzero(&e, sizeof(t_fdf));
	if (ac == 1)
		die("Missing File !", &e, EXIT_FAILURE);
	fdf(&e);
	e.m.filename = av[0];
	e.s_y = countreadfile(av[1]);
	e.map = ft_memalloc(e.s_y);
	check_fdf(av[1]);
	die("All completed ! Exiting...", &e, EXIT_SUCCESS);
	return (0);
}

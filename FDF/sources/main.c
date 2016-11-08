/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpichon <anpichon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 07:25:59 by anpichon          #+#    #+#             */
/*   Updated: 2016/11/04 18:11:04 by anpichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	die(char *s, int exit_code)
{
	ft_putendl(s);
	exit(exit_code);
}

void	free_tab(t_fdf *e)
{
	int		y;

	y = 0;
	while (y <= e->y_max)
	{
		free(e->data[y]);
		y++;
	}
	ft_memdel((void **)&e->data);
}

int		main(int ac, char **av)
{
	t_fdf	e;
	char	**buf;

	ft_bzero(&e, sizeof(e));
	if (ac != 2)
		die("./fdf : Usage ./fdf <filename.fdf>", EXIT_FAILURE);
	check_extension(av[1], ".fdf");
	buf = get_data(av[1]);
	e.y_max = nb_lines(buf);
	e.x_max = nb_points(buf, e.y_max);
	e.data = read_map(buf, e.x_max, e.y_max);
	e.cal_data = NULL;
	init_param(&e);
	display_init(&e);
	free_tab(&e);
	die("All completed ! Exiting...", EXIT_SUCCESS);
	return (0);
}

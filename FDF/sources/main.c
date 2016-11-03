/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpichon <anpichon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 07:25:59 by anpichon          #+#    #+#             */
/*   Updated: 2016/11/03 10:30:03 by anpichon         ###   ########.fr       */
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
	t_fdf	*e;
	char	**buf;

	e = (t_fdf*)malloc(sizeof(t_fdf));
	e->m = (t_mlx*)malloc(sizeof(t_mlx));
	e->l = (t_line*)malloc(sizeof(t_line));
	e->b = (t_bress*)malloc(sizeof(t_bress));
	if (ac == 1)
		die("./fdf : Usage ./fdf <filename.fdf>", EXIT_FAILURE);
	check_extension(av[1], ".fdf", e);
	buf = get_data(av[1]);
	e->y_max = nb_lines(buf);
	e->x_max = nb_points(buf, e->y_max);
	e->data = read_map(buf, e->x_max, e->y_max);
	e->iso = 1;
	e->para = 0;
	e->cal_data = NULL;
	init_param(e);
	display_init(e);
	free_tab(e);
	die("All completed ! Exiting...", EXIT_SUCCESS);
	return (0);
}

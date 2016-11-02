/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_pars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpichon <anpichon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 07:26:13 by anpichon          #+#    #+#             */
/*   Updated: 2016/11/02 05:50:18 by anpichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		countreadfile(char *file)
{
	int		i;
	int		fd;
	char	*c;
	char	*ext;

	if (!(fd = open(file, O_RDONLY)))
		return (0);
	i = 0;
	while (get_next_line(fd, &c) > 0)
		i++;
	close(fd);
	return (i);
}

int		check_map(int size)
{
	t_fdf	e;

	fdf(&e);
	if (e.s_x == 0)
		e.s_x = size;
	if (e.s_x != size)
		return (0);
	else
		return (1);
}

void	check_fdf(char *file)
{
	int		i;
	int		fd;
	t_fdf	e;
	char	*str;

	fdf(&e);
	e.y = 0;
	e.s_x = 0;
	i = 0;
	if (!(fd = open(file, O_RDONLY)))
		die("Fdf : Don't have access file", &e, EXIT_FAILURE);
	while (get_next_line(fd, &str) > 0)
	{
		while (str[i])
		{
			if ((str[i] >= '0' && str[i] <= '9') || str[i] == ' ')
				i++;
			else
				die("Fdf : Map Error -> Invalid Character!", &e, EXIT_FAILURE);
		}
		if (check_map(ft_getnbr(&(e.map)[e.y++], str, ' ')) == 0)
			die("Fdf : Map Error -> Size line invalid !", &e, EXIT_FAILURE);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpichon <anpichon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 02:52:50 by anpichon          #+#    #+#             */
/*   Updated: 2016/11/04 18:10:13 by anpichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	points_counter(char *line)
{
	size_t		i;
	int			nb;

	i = 0;
	nb = 0;
	while (i < ft_strlen(line))
	{
		if (ft_isdigit(line[i]) == 1)
			nb++;
		while (ft_isdigit(line[i]) == 1)
			i++;
		if (line[i] == ',')
		{
			i += 4;
			while (line[i] == 'F')
				i++;
		}
		i++;
	}
	return (nb);
}

int			*nb_points(char **tab, int y_max)
{
	int			*x_max;
	int			y;

	y = 0;
	x_max = (int *)malloc(sizeof(int) * y_max);
	if (x_max == NULL)
		die("./fdf : Malloc invalid", EXIT_FAILURE);
	while (tab[y])
	{
		x_max[y] = points_counter(tab[y]);
		if (y > 0)
			if (x_max[y] != x_max[y - 1])
				die("./fdf : Lines in file is not equals !", EXIT_FAILURE);
		y++;
	}
	return (x_max);
}

int			nb_lines(char **tab)
{
	int		nb;

	nb = 0;
	while (tab[nb])
		nb++;
	return (nb);
}

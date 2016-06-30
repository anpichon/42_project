/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpichon <anpichon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 03:44:56 by anpichon          #+#    #+#             */
/*   Updated: 2016/06/24 08:56:30 by anpichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Library/libfillit.h"

int				ft_error(void)
{
	ft_putstr("error\n");
	exit(1);
}

static void		ft_free_all(char *map, t_tetri *tetri, char **split)
{
	map = NULL;
	free(map);
	tetri = NULL;
	free(tetri);
	split = NULL;
	free(split);
}

static void		ft_print_map(char *map)
{
	ft_putendl(map);
}

int				main(int ac, char **av)
{
	char		**split;
	t_tetri		*tetri;
	char		*map;

	if (ac == 2)
	{
		split = ft_split_tetri(ft_readfile(av[1]));
		if (split && ft_all_split_verif(split))
		{
			tetri = ft_all_split_pos(split);
			if (tetri)
			{
				map = ft_resolve(tetri);
				ft_print_map(map);
				ft_free_all(map, tetri, split);
			}
			else
				ft_error();
		}
		else
			ft_error();
	}
	else
		ft_error();
	return (0);
}

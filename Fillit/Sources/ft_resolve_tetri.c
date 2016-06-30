/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_tetri.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpichon <anpichon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 18:04:34 by anpichon          #+#    #+#             */
/*   Updated: 2016/06/24 09:02:16 by anpichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Library/libfillit.h"

int				ft_nb_max_tetri(t_tetri *tetri)
{
	int		i;

	i = 0;
	while (tetri[i].x != -1)
		i++;
	return (i);
}

char			*ft_resolve(t_tetri *tetri)
{
	char	*tmp_map;

	tmp_map = ft_init_map(2);
	tmp_map = ft_resolve_tetri(tmp_map, tetri, 0);
	return (tmp_map);
}

char			*ft_resolve_tetri(char *map, t_tetri *tetri, int nb_item)
{
	int		i;

	if (nb_item == ft_nb_max_tetri(tetri))
		return (map);
	i = -1;
	while (map[++i])
	{
		if (ft_mv_tetri(map, &tetri[nb_item],
					i, 'A' + nb_item))
		{
			map = ft_resolve_tetri(map, tetri, nb_item + 1);
			if (ft_tetri_nbr(map) == ft_nb_max_tetri(tetri))
				return (map);
		}
		if (!map[i + 1] && nb_item == 0)
		{
			i = -1;
			map = ft_upsize_map(map);
		}
	}
	return (map);
}

static int		ft_ctr_pos_pt2(char *split, int *x, int i)
{
	int				blocks;

	blocks = 0;
	x[blocks++] = 0;
	if (P_CENTER_R == '#')
		x[blocks++] = 3;
	if (P_CENTER_DL == '#')
		x[blocks++] = 6;
	if (P_CENTER_D == '#')
		x[blocks++] = 5;
	if (P_CENTER_DR == '#')
		x[blocks++] = 4;
	if (P_CENTER_L == '#')
		x[blocks++] = 7;
	if (P_CENTER_UR == '#')
		x[blocks++] = 2;
	if (P_CENTER_U == '#')
		x[blocks++] = 1;
	if (P_CENTER_UL == '#')
		x[blocks++] = 8;
	return ((blocks == 4) ? 1 : 0);
}

int				*ft_ctr_pos(char *split)
{
	int				*x;
	int				i;

	if (!(x = (int *)malloc(sizeof(int) * 4)) || !split)
		return (NULL);
	i = -1;
	while (split[++i])
		if (split[i] == '#')
			if (ft_ctr_pos_pt2(split, x, i))
				return (x);
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mv_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpichon <anpichon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 07:07:30 by anpichon          #+#    #+#             */
/*   Updated: 2016/06/24 09:03:07 by anpichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Library/libfillit.h"

static int	ft_ctr_mv_pt2(int *data, char *map, int i, char id)
{
	if (*data == 0 && CENTER_M == '.')
		CENTER_M = id;
	else if (*data == 1 && CENTER_U == '.' && CENTER_LIM_U_UR)
		CENTER_U = id;
	else if (*data == 2 && CENTER_UR == '.' && CENTER_LIM_U_UR)
		CENTER_UR = id;
	else if (*data == 3 && CENTER_R == '.')
		CENTER_R = id;
	else if (*data == 4 && CENTER_DR == '.')
		CENTER_DR = id;
	else if (*data == 5 && CENTER_D == '.')
		CENTER_D = id;
	else if (*data == 6 && CENTER_DL == '.')
		CENTER_DL = id;
	else if (*data == 7 && CENTER_L == '.')
		CENTER_L = id;
	else if (*data == 8 && CENTER_UL == '.' && CENTER_LIM_UL)
		CENTER_UL = id;
	else
		return (0);
	return (1);
}

int			ft_ctr_mv(char *map, int *t, int x, char id)
{
	int			blocks;

	blocks = -1;
	ft_clean_map(map, id);
	if (x > ft_strlen(map))
		return (0);
	while (++blocks < 4
			&& ft_ctr_mv_pt2(&t[blocks], map, x, id))
		;
	if (blocks == 4)
		return (1);
	ft_clean_map(map, id);
	return (0);
}

int			ft_lnr_mv(char *map, int *t, int x, char id)
{
	int			blocks;

	blocks = -1;
	ft_clean_map(map, id);
	if (x > ft_strlen(map))
		return (0);
	while (++blocks < 4)
	{
		if (t[blocks] == 0 && LINEAR_B == '.')
			LINEAR_B = id;
		else if (t[blocks] == 1 && LINEAR_R == '.')
		{
			LINEAR_R = id;
			x++;
		}
		else if (t[blocks] == 2 && LINEAR_D == '.')
		{
			LINEAR_D = id;
			x += (ft_size_map(map) + 1);
		}
		else
			break ;
	}
	(blocks < 4) ? ft_clean_map(map, id) : 1;
	return ((blocks == 4) ? 1 : 0);
}

int			ft_mv_tetri(char *map, t_tetri *tetri, int x, char id)
{
	if (tetri->x == 1)
		return (ft_lnr_mv(map, tetri->data, x, id));
	else if (tetri->x == 0)
		return (ft_ctr_mv(map, tetri->data, x, id));
	return (0);
}

int			*ft_lnr_pos(char *split)
{
	int				i;
	int				j;
	int				*x;

	i = 0;
	j = 0;
	if (!(x = (int *)malloc(sizeof(int) * 4)))
		return (NULL);
	while (split[i])
	{
		(split[i] == '#' && j == 0) ? (x[j++] = 0) : 1;
		if (split[i] == '#' && split[i + 1] == '#')
		{
			x[j++] = 1;
			i++;
		}
		else if (split[i] == '#' && split[i + 4] == '#')
		{
			x[j++] = 2;
			i += 4;
		}
		else
			i++;
	}
	return ((j == 4) ? x : NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tetri.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpichon <anpichon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 08:52:20 by anpichon          #+#    #+#             */
/*   Updated: 2016/06/24 08:59:44 by anpichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Library/libfillit.h"

int					ft_all_split_verif(char **split)
{
	int		i;

	i = 0;
	if (!split)
		return (0);
	while (split[i])
	{
		if (!ft_split_verif(split[i]))
			return (0);
		i++;
	}
	return (1);
}

int					ft_split_verif(char *split)
{
	int		i;
	int		nb_blocks;

	if (ft_strlen(split) != 16)
		return (0);
	i = 0;
	nb_blocks = 0;
	while (split[i])
	{
		if (split[i] == '#')
		{
			if (split[i + 1] == '#'
					|| split[i - 1] == '#'
					|| split[i + 4] == '#'
					|| split[i - 4] == '#')
				nb_blocks++;
		}
		i++;
	}
	return ((nb_blocks == 4) ? 1 : 0);
}

t_tetri				*ft_all_split_pos(char **split)
{
	t_tetri			*tetri;
	int				i;
	int				limit;

	limit = ft_split_nbr(split);
	if (!(tetri = (t_tetri *)malloc(sizeof(t_tetri) * (limit + 1))))
		return (NULL);
	i = 0;
	while (i < limit)
	{
		if ((tetri[i].data = ft_lnr_pos(split[i])))
			tetri[i].x = 1;
		else if ((tetri[i].data = ft_ctr_pos(split[i])))
			tetri[i].x = 0;
		else
			return (NULL);
		i++;
	}
	tetri[i].x = -1;
	tetri[i].data = NULL;
	return (tetri);
}

int					ft_split_nbr(char **split)
{
	int				i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

int					ft_tetri_nbr(char *map)
{
	int		i;
	char	tmp;

	i = 0;
	tmp = 0;
	while (map[i])
	{
		if ((map[i] >= 'A' && map[i] <= 'Z') && tmp < map[i])
			tmp = map[i];
		i++;
	}
	if (tmp >= 'A' && tmp <= 'Z')
		return ((tmp - 'A') + 1);
	else
		return (0);
}

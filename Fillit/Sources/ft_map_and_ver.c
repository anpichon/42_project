/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_and_ver.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpichon <anpichon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/20 15:01:40 by anpichon          #+#    #+#             */
/*   Updated: 2016/06/24 08:56:45 by anpichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Library/libfillit.h"

char		*ft_upsize_map(char *map)
{
	int		i;
	int		j;
	int		end;
	char	*new_map;

	if (!(new_map = (char *)malloc(sizeof(char)
					* (ft_recursive_power(ft_size_map(map) + 1, 2) + 26))))
		return (NULL);
	i = -1;
	j = 0;
	end = -1;
	while (map[++i])
	{
		(map[i] == '\n')
			? (new_map[j++] = '.') : 1;
		new_map[j++] = (map[i] == '\n')
			? '\n' : map[i];
	}
	new_map[j++] = '.';
	new_map[j++] = '\n';
	while (++end < ft_size_map(map) + 1)
		new_map[j++] = '.';
	new_map[j] = '\0';
	return (new_map);
}

int			ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * ft_recursive_power(nb, power - 1));
}

char		*ft_init_map(int size)
{
	int		i;
	char	*map;

	i = -1;
	if (!(map = (char *)malloc(sizeof(char)
					* (ft_recursive_power(size, 2) + 1 + size))))
		return (NULL);
	while (++i < (ft_recursive_power(size, 2) + size - 1))
		map[i] = ((i + 1) % (size + 1) == 0) ? '\n' : '.';
	map[i] = '\0';
	return (map);
}

int			ft_size_map(char *map)
{
	int		i;

	i = 0;
	while (map[i] != '\n')
		i++;
	return (i);
}

void		ft_clean_map(char *map, char id)
{
	int		i;
	int		blocks;

	i = 0;
	blocks = 0;
	while (map[i])
	{
		if (map[i] == id)
		{
			map[i] = '.';
			blocks++;
		}
		if (blocks == 4)
			return ;
		i++;
	}
}

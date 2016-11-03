/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpichon <anpichon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 07:18:35 by anpichon          #+#    #+#             */
/*   Updated: 2016/10/28 11:32:17 by anpichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_getnbr(int **tab, char *str, char c)
{
	int		i;
	char	**tmp;

	i = 0;
	if (!(tmp = ft_strsplit(str, c)))
		return (0);
	while (tmp[i])
		i++;
	if (!(*tab = (int*)malloc(sizeof(int) * i)))
		return (0);
	i = 0;
	while (tmp[i])
	{
		(*tab)[i] = ft_atoi(tmp[i]);
		i++;
	}
	return (i);
}

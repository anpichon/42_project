/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 05:34:12 by anpichon          #+#    #+#             */
/*   Updated: 2015/12/01 03:40:29 by anpichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	while ((char)*str)
	{
		if ((char)*str == (char)c)
			return ((char *)str);
		str++;
	}
	if ((char)*str == (char)c)
		return ((char *)str);
	return (NULL);
}

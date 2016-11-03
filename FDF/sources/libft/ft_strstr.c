/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 06:27:04 by anpichon          #+#    #+#             */
/*   Updated: 2015/12/07 02:30:02 by anpichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	char	*str1;
	char	*str2;
	int		i;

	str1 = (char *)s1;
	str2 = (char *)s2;
	if (!*str2)
		return (str1);
	while (*str1)
	{
		i = 0;
		while (str1[i] != '\0' && str1[i] == str2[i])
			i++;
		if (!str2[i])
			return (str1);
		++str1;
	}
	return (NULL);
}

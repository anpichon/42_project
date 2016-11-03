/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 10:22:45 by anpichon          #+#    #+#             */
/*   Updated: 2015/12/07 07:12:36 by anpichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	while (*s1 && n > 0)
	{
		i = 0;
		while (s2[i] != '\0' && s1[i] == s2[i] && n > 0)
		{
			i += 1;
			--n;
		}
		if (!s2[i])
			return ((char *)s1);
		n += i;
		--n;
		++s1;
	}
	return (NULL);
}

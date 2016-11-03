/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 08:41:16 by anpichon          #+#    #+#             */
/*   Updated: 2015/12/01 09:09:06 by anpichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	ts1;
	unsigned char	ts2;

	while (n > 0)
	{
		ts1 = *(unsigned char *)s1;
		ts2 = *(unsigned char *)s2;
		if (ts1 != ts2)
			return (ts1 - ts2);
		s1++;
		s2++;
		n--;
	}
	return (0);
}

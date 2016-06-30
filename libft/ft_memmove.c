/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 07:02:19 by anpichon          #+#    #+#             */
/*   Updated: 2015/12/01 07:39:24 by anpichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*tmpsrc;
	char		*tmpdst;

	if (src > dst)
		ft_memcpy(dst, src, len);
	else
	{
		tmpdst = dst + len - 1;
		tmpsrc = src + len - 1;
		while (len > 0)
		{
			*tmpdst = *tmpsrc;
			tmpsrc--;
			tmpdst--;
			len--;
		}
	}
	return (dst);
}

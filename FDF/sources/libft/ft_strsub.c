/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 13:55:37 by anpichon          #+#    #+#             */
/*   Updated: 2015/12/07 05:33:28 by anpichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*ptr;

	if (s == NULL)
		return (NULL);
	i = 0;
	if (!(ptr = ft_strnew(len)))
		return (NULL);
	while (len != i)
	{
		ptr[i] = s[start];
		start++;
		i++;
	}
	ptr[++i] = '\0';
	return (ptr);
}

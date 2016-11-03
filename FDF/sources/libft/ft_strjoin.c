/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 14:19:20 by anpichon          #+#    #+#             */
/*   Updated: 2015/12/04 04:31:26 by anpichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;

	if (s1 == NULL || s2 == NULL)
		return (ft_strnew(0));
	ptr = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (ptr == NULL)
		return (NULL);
	ptr = ft_strcat(ptr, s1);
	ptr = ft_strcat(ptr, s2);
	return (ptr);
}

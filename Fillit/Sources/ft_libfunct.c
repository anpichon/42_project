/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libfunct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpichon <anpichon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 09:39:48 by anpichon          #+#    #+#             */
/*   Updated: 2016/06/24 09:53:05 by anpichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Library/libfillit.h"

int			ft_strlen(const char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putendl(char const *s)
{
	ft_putstr(s);
	ft_putchar('\n');
}

void		ft_putstr(char const *s)
{
	write(1, s, ft_strlen(s));
}

char		*ft_strstr(const char *s1, const char *s2)
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

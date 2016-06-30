/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_tetrimino.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpichon <anpichon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 06:57:45 by anpichon          #+#    #+#             */
/*   Updated: 2016/06/24 08:57:30 by anpichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Library/libfillit.h"

static int	ft_pattern(char *s1, char *s2)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = s1;
	while ((tmp = ft_strstr(&tmp[ft_strlen(s2)], s2)))
		i++;
	return (i);
}

static char	**ft_init_split_tetri(char *form, int *a, int *j, int *k)
{
	int		i;
	char	**split;

	i = 0;
	*a = -1;
	*j = 0;
	*k = 0;
	if (!(split = (char **)malloc(sizeof(char *)
					* (ft_pattern(form, "\n\n") + 2))))
		return (NULL);
	while (i < (ft_pattern(form, "\n\n") + 1))
	{
		if (!(split[i] = (char *)malloc(sizeof(char) * 17)))
			return (NULL);
		i++;
	}
	split[i] = NULL;
	return (split);
}

char		**ft_split_tetri(char *form)
{
	char	**split;
	int		i;
	int		j;
	int		k;

	split = ft_init_split_tetri(form, &i, &j, &k);
	while (++i < (ft_pattern(form, "\n\n") + 1))
	{
		while (j < 16)
		{
			if (form[k] != '.' && form[k] != '#' && form[k] != '\n')
				return (NULL);
			if (form[k] != '\n' && (k - i) % 5 != 4)
				split[i][j++] = form[k];
			k += (j == 16) ? 2 : 1;
		}
		if (((((ft_pattern(form, "\n\n") + 1) * 20) + ft_pattern(form, "\n\n"))
				!= ft_strlen(form)) || (form[k] != '\0' && form[k] != '\n'))
			return (NULL);
		split[i][j] = '\0';
		j = 0;
	}
	return (split);
}

static int	ft_countreadfile(char *file)
{
	int		fd;
	int		i;
	char	c;

	if (!(fd = open(file, O_RDONLY)))
	{
		return (0);
	}
	i = 0;
	while (read(fd, &c, 1) > 0)
		i++;
	close(fd);
	return (i);
}

char		*ft_readfile(char *file)
{
	int		fd;
	int		i;
	char	*result;
	char	c;

	if (!(result = (char *)malloc(sizeof(char)
					* (ft_countreadfile(file) + 1))))
		return (NULL);
	if (!(fd = open(file, O_RDONLY)))
		return (NULL);
	i = 0;
	while (read(fd, &c, 1) > 0)
		result[i++] = c;
	result[i] = '\0';
	close(fd);
	return (result);
}

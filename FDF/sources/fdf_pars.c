/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_pars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpichon <anpichon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 07:26:13 by anpichon          #+#    #+#             */
/*   Updated: 2016/11/03 10:31:24 by anpichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			check_extension(char *filename, char *extension, t_fdf *e)
{
	int		i;
	int		fd;
	char	*str;

	i = 0;
	if ((fd = open(filename, O_RDONLY)) < 0)
		die("./fdf : Access file denied !", EXIT_FAILURE);
	str = ft_strrchr(filename, '.');
	if (str == NULL)
		die("./fdf Usage <filename.fdf>", EXIT_FAILURE);
	while (str[i] && extension[i])
	{
		if (str[i] == extension[i])
			i++;
		else
			die("./fdf Usage <filename.fdf>", EXIT_FAILURE);
	}
	e->m->filename = filename;
}

static size_t	get_len(const char *file)
{
	int		fd;
	size_t	len;
	char	*line;

	len = 1;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		check_line(line);
		len++;
	}
	close(fd);
	return (len);
}

char			**get_data(char *file)
{
	int		y;
	int		fd;
	size_t	len;
	char	*line;
	char	**data;

	y = 0;
	len = get_len(file);
	fd = open(file, O_RDONLY);
	data = (char **)malloc(sizeof(char *) * len);
	while (get_next_line(fd, &line))
	{
		data[y] = ft_strdup(line);
		y++;
	}
	data[y] = NULL;
	close(fd);
	return (data);
}

static int		*store_split_line(char *line, int x_max)
{
	int		j;
	int		x;
	int		*data;

	j = 0;
	x = 0;
	if ((data = (int *)malloc(sizeof(int) * x_max)) == NULL)
		die("./fdf : malloc invalid !", EXIT_FAILURE);
	while (x < x_max)
	{
		if (ft_isdigit(line[j]) == 1 || line[j] == '-')
		{
			data[x] = ft_atoi(line + j);
			x++;
		}
		while (ft_isdigit(line[j]) || line[j] == '-')
			j++;
		if (line[j] == ',')
			j += 4;
		while (line[j] == ' ' || line[j] == 'F')
			j++;
	}
	return (data);
}

int				**read_map(char **tab, int *x_max, int y_max)
{
	int		y;
	int		i;
	int		**data;
	int		flag;

	y = 0;
	i = 0;
	data = (int **)malloc(sizeof(int *) * ft_max(x_max[y], y_max));
	if (data == NULL)
		die("./fdf : malloc invalid !", EXIT_FAILURE);
	flag = 1;
	while (flag)
	{
		data[y] = store_split_line(tab[y], x_max[y]);
		if (y < y_max)
			y++;
		if (y >= y_max)
		{
			flag = 0;
			break ;
		}
	}
	data[y] = NULL;
	return (data);
}

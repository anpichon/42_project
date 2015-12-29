/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpichon <anpichon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 03:44:56 by anpichon          #+#    #+#             */
/*   Updated: 2015/12/29 04:07:53 by anpichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Library/libfillit.h"
#include <stdio.h>

void	ft_error(void)
{
	ft_putstr("error\n");
}

void		ft_get_file(char *file)
{
	int		i;
	int		fd;
	size_t	item;
	char	*buffer;
	t_list	*lsttetri;

	i = 0;
	item = 0;
	if ((buffer = ft_memalloc(21)) == NULL)
		ft_error();
	fd = open(file, O_RDONLY);
	while ( (i = read(fd, buffer, 21)) > 0 && item <= 26)
	{
		if (i == 21 && (item != 0 && item <= 26))
			ft_lstadd(&lsttetri, ft_lstnew(buffer, 21));
		else if (i == 21 && item == 0)
			lsttetri = ft_lstnew(buffer, 21);
		else
			ft_error();
		item++;
	}
	if (i == -1 || item > 26)
		ft_error();
	close(fd);
}

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		ft_get_file(av[1]);
	}
	else
		ft_error();
	return (0);
}

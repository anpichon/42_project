/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpichon <anpichon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 11:05:42 by anpichon          #+#    #+#             */
/*   Updated: 2016/10/28 11:26:30 by anpichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_gnl		*lstnew(int fd)
{
	t_gnl	*info;

	if (fd < 0)
		return (NULL);
	if (!(info = (t_gnl *)ft_memalloc(sizeof(t_gnl))))
		return (NULL);
	info->next = NULL;
	info->prev = NULL;
	info->fd = fd;
	if (!(info->data = (char *)ft_memalloc(sizeof(char*) * (BUFF_SIZE + 1))))
		return (NULL);
	return (info);
}

t_gnl		*check_lst(t_gnl **first, t_gnl *lst, int fd)
{
	lst = *first;
	while (lst && lst->next)
	{
		if (lst->fd == fd)
			return (lst);
		lst = lst->next;
	}
	if (lst->fd == fd)
		return (lst);
	lst->next = lstnew(fd);
	lst->next->prev = lst;
	return (lst->next);
}

int			gnl_check_buffer(char *buff, char **data, char **l)
{
	char	*tmp;
	char	*tmp2;

	if (!*data)
		return (0);
	if ((buff && (tmp = ft_strchr(buff, '\n')))
		|| (tmp = ft_strchr(*data, '\n')))
	{
		*tmp = '\0';
		if (!buff)
			*l = ft_strdup(*data);
		else
			*l = ft_strjoin(*data, buff);
		tmp2 = ft_strdup(tmp + 1);
		free(*data);
		*data = tmp2;
		return (1);
	}
	return (0);
}

static int	gnl_split(t_gnl *lst, int i, char **line, char *tmp)
{
	if (i == -1)
		return (-1);
	if (lst->data && *lst->data)
	{
		ft_bzero(tmp, BUFF_SIZE + 1);
		*line = ft_strdup(lst->data);
		free(lst->data);
		lst->data = NULL;
		return (1);
	}
	if (i == 0 && lst->data == NULL)
	{
		if (lst->prev)
			lst->prev->next = lst->next;
		if (lst->next)
			lst->next->prev = lst->prev;
		return (0);
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static t_gnl	*first = NULL;
	t_gnl			*lst;
	char			tmp[BUFF_SIZE + 1];

	if (!first)
		first = lstnew(fd);
	if (!first || line == NULL || fd < 0)
		return (-1);
	lst = first;
	lst = check_lst(&first, lst, fd);
	if (gnl_check_buffer(NULL, &lst->data, line))
		return (1);
	ft_bzero(tmp, BUFF_SIZE + 1);
	while ((lst->i = read(fd, tmp, BUFF_SIZE)) > 0)
	{
		if (gnl_check_buffer(tmp, &lst->data, line))
			return (1);
		lst->tmp = lst->data;
		lst->data = ft_strjoin(lst->data, tmp);
		free(lst->tmp);
		ft_bzero(tmp, BUFF_SIZE + 1);
	}
	return (gnl_split(lst, lst->i, line, tmp));
}

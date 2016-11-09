/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 04:21:37 by anpichon          #+#    #+#             */
/*   Updated: 2016/10/28 04:22:45 by anpichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct		s_gnl
{
	int				fd;
	int				read;
	int				i;
	int				check;
	char			*data;
	char			*tmp;
	struct s_gnl	*next;
	struct s_gnl	*prev;
}					t_gnl;
int					get_next_line(const int fd, char **line);
int					gnl_check_buffer(char *buf, char **data, char **l);
int					gnl_check_data(char **buffer, char **line);
void				lstappend(t_gnl **first, t_gnl *new);
t_gnl				*check_lst(t_gnl **first, t_gnl *lst, int fd);
t_gnl				*lstnew(int fd);

#endif

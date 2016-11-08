/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpichon <anpichon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 11:06:06 by anpichon          #+#    #+#             */
/*   Updated: 2016/11/04 17:39:59 by anpichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1
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
t_gnl				*check_lst(t_gnl **first, t_gnl *lst, int fd);
t_gnl				*lstnew(int fd);

#endif

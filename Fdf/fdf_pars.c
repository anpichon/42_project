/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_pars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpichon <anpichon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 07:26:13 by anpichon          #+#    #+#             */
/*   Updated: 2016/10/28 11:26:21 by anpichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	    ft_countreadfile(char *file)
{
  int		i;
	int		fd;
	char	*c;

	if (!(fd = open(file, O_RDONLY)))
			return (0);
	i = 0;
	while (get_next_line(fd, &c) > 0)
		i++;
	close(fd);
	return (i);
}

int   ft_check_fdf(int fd, t_fdf *e)
{

}

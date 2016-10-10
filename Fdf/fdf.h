/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpichon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 07:25:01 by anpichon          #+#    #+#             */
/*   Updated: 2016/10/05 07:25:08 by anpichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WIDTH 1280
# define HEIGHT 720
# include <mlx.h>
# include "sources/libft/libft.h"
typedef struct		s_mlx
{
  void  *mlx;
  void  *win;
  void  *img;
  char  *filename;
}                 t_mlx

typedef struct		s_fdf
{
  int   dx;
  int   dy;
  int   sx;
  int   sy;
  int   err;
  int   e2;
  t_mlx *m;
}					s_fdf;
#endif

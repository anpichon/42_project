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
# define W 1280
# define H 720
# include "sources/minilibx/mlx.h"
# include "sources/libft/libft.h"

typedef struct    s_line
{
  int x0;
  int x1;
  int y0;
  int y1;
}                t_line;

typedef struct		s_mlx
{
  int   r;
  int   g;
  int   b;
  int   en;
  int   bpp;
  int   sl;
  void  *mlx;
  void  *win;
  void  *img;
  char  *data;
  char  *filename;
}                 t_mlx;
typedef struct    s_fdf
{
  int   x;
  int   y;
  int   z;
  int   zoom;
  t_line  *l;
  t_mlx   *m;
  t_bress *b;
}                 t_fdf;
typedef struct		s_bress
{
  int   dx;
  int   dy;
  int   sx;
  int   sy;
  int   err;
  int   e2;
}					t_bress;
#endif

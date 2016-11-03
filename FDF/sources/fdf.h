/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpichon <anpichon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 07:25:01 by anpichon          #+#    #+#             */
/*   Updated: 2016/11/03 10:29:32 by anpichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define W 1280
# define H 720
# define BLUE	{ e->m->c_r = 44; e->m->c_g = 117; e->m->c_b = 255; }
# define GREEN	{ e->m->c_r = 51; e->m->c_g = 255; e->m->c_b = 51; }
# define WHITE	{ e->m->c_r = 255; e->m->c_g = 255; e->m->c_b = 255; }
# define BROWN	{ e->m->c_r = 153; e->m->c_g = 102; e->m->c_b = 0; }
# define GREY	{ e->m->c_r = 96; e->m->c_g = 96; e->m->c_b = 96; }
# define YELLOW	{ e->m->c_r = 255; e->m->c_g = 255; e->m->c_b = 0; }
# define BROW	{ e->m->c_r = 203; e->m->c_g = 122; e->m->c_b = 0; }
# include "minilibx/mlx.h"
# include "libft/libft.h"
# include <math.h>

typedef struct		s_cal
{
	int				x_cal;
	int				y_cal;
}					t_cal;
typedef struct		s_line
{
	int				x0;
	int				x1;
	int				y0;
	int				y1;
}					t_line;
typedef struct		s_mlx
{
	int				c_r;
	int				c_g;
	int				c_b;
	int				en;
	int				bpp;
	int				sl;
	void			*mlx;
	void			*win;
	void			*img;
	char			*data;
	char			*filename;
}					t_mlx;
typedef struct		s_bress
{
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				err;
	int				e2;
}					t_bress;
typedef struct		s_fdf
{
	int				x;
	int				y;
	int				z;
	int				zoom;
	int				mv_x;
	int				mv_y;
	int				*x_max;
	int				y_max;
	int				opt;
	int				para;
	int				iso;
	int				deep;
	int				s_x;
	int				s_y;
	int				**data;
	int				**map;
	float			incl;
	int				var;
	int				var1;
	int				var2;
	int				pos;
	t_line			*l;
	t_mlx			*m;
	t_bress			*b;
	t_cal			**cal_data;
}					t_fdf;

int					nb_lines(char **tab);
int					key(int key, t_fdf *e);
int					countreadfile(char *file);
int					*nb_points(char **tab, int y_max);
int					**read_map(char **tab, int *x_max, int y_max);
char				**get_data(char *file);
void				*try(size_t size);
void				new_img(t_fdf *e);
void				init_param(t_fdf *e);
void				tab_to_iso(t_fdf *e);
void				tab_to_para(t_fdf *e);
void				free_tab(t_fdf *e);
void				display_menu(t_fdf *e);
void				display_init(t_fdf *e);
void				check_line(char *line);
void				init_color(t_fdf *e, int z);
void				die(char *s, int exit_code);
void				mlx_print_pixel(int x, int y, t_fdf *e);
void				print_line(t_cal p1, t_cal p2, t_fdf *e);
void				check_extension(char *filename, char *extension, t_fdf *e);
t_fdf				*fdf(t_fdf *e);

#endif

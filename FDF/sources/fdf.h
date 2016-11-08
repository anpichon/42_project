/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpichon <anpichon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 07:25:01 by anpichon          #+#    #+#             */
/*   Updated: 2016/11/04 15:32:37 by anpichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define W 1280
# define H 720
# define BLUE	{ e->c_r = 44; e->c_g = 117; e->c_b = 255; }
# define GREEN	{ e->c_r = 51; e->c_g = 255; e->c_b = 51; }
# define WHITE	{ e->c_r = 255; e->c_g = 255; e->c_b = 255; }
# define BROWN	{ e->c_r = 153; e->c_g = 102; e->c_b = 0; }
# define GREY	{ e->c_r = 96; e->c_g = 96; e->c_b = 96; }
# define YELLOW	{ e->c_r = 255; e->c_g = 255; e->c_b = 0; }
# define BROW	{ e->c_r = 203; e->c_g = 122; e->c_b = 0; }
# include "minilibx/mlx.h"
# include "libft/libft.h"
# include <math.h>

typedef struct		s_cal
{
	int				x_cal;
	int				y_cal;
}					t_cal;
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
	int				para;
	int				iso;
	int				deep;
	int				**data;
	int				c_r;
	int				c_g;
	int				c_b;
	int				en;
	int				bpp;
	int				sl;
	void			*mlx;
	void			*win;
	void			*img;
	char			*data_img;
	float			incl;
	int				var;
	int				var1;
	int				var2;
	int				pos;
	t_cal			**cal_data;
}					t_fdf;

int					nb_lines(char **tab);
int					key(int key, t_fdf *e);
int					main(int ac, char **ar);
int					countreadfile(char *file);
int					*nb_points(char **tab, int y_max);
int					**read_map(char **tab, int *x_max, int y_max);
char				**get_data(char *file);
void				*try(size_t size);
void				new_img(t_fdf *e);
void				free_tab(t_fdf *e);
void				init_param(t_fdf *e);
void				tab_to_iso(t_fdf *e);
void				tab_to_para(t_fdf *e);
void				free_struct(t_fdf *e);
void				display_menu(t_fdf *e);
void				display_init(t_fdf *e);
void				check_line(char *line);
void				init_color(t_fdf *e, int z);
void				die(char *s, int exit_code);
void				mlx_print_pixel(int x, int y, t_fdf *e);
void				print_line(t_cal p1, t_cal p2, t_fdf *e);
void				check_extension(char *filename, char *extension);
t_cal				cal_pa(int y, int x, int z, t_fdf *e);
t_cal				cal_i(int y, int x, int z, t_fdf *e);

#endif

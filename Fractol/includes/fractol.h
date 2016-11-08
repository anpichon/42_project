/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpichon <anpichon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 10:43:43 by anpichon          #+#    #+#             */
/*   Updated: 2016/11/08 06:54:03 by anpichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../src/libft/libft.h"
# include "../src/minilibx/mlx.h"
# include <math.h>
# include <stdlib.h>

# define W 1200
# define H 800
# define I 255
# define I1 0
# define I2 1
# define I3 2
# define R e->m.red
# define G e->m.green
# define B e->m.blue
# define CA 4 * e->x
# define C1(I3, I) e->m.dmg[(e->m.sl * e->y) + (CA) + I3] = I;
# define C2(I3) e->m.dmg[(e->m.sl * e->y) + (CA) + I3] = (e->i * I / e->it_max)
# define C3(I3)	e->m.dmg[(e->m.sl * e->y) + (CA) + I3] = (e->i / I * e->it_max)

# define WHITE	C1(I3, I) C1(I2, I) C1(I1, I)
# define BLACK	C1(I3, I1) C1(I2, I1) C1(I1, I1)
# define C1BR	C2(I3) + R; C1(I2, I1) C2(I1) * B
# define C1BR1	C2(I3) * R; C1(I2, I1) C2(I1) + B
# define C1BG	C1(I3, I1) C2(I2) * G + G; C2(I1) * B
# define C1RG	C2(I3) * R; C2(I2) * G * G; C2(I1) * B * B * B
# define CRAD	C2(I3) * R * R ; C2(I2) * G * G * G; C1(I1, I)
# define CRAD1	C2(I3) * R * R * R; C1(I2, I) C2(I1) * B
# define CRAD2	C3(I3) * R; C3(I2) * G * G; C3(I1) * B * B * B
# define CRAD3	C3(I3) * R * R; C2(I2) * G * G * G; C2(I1) * B
# define CDBR	C2(I3) * R * R * R; C3(I2) * G; C3(I1) * B * B

typedef struct		s_mlx
{
	int				en;
	int				sl;
	int				bbp;
	int				red;
	int				green;
	int				blue;
	void			*mlx;
	void			*win;
	void			*img;
	char			*dmg;
	char			*name;
}					t_mlx;

typedef struct		s_fractol
{
	t_mlx			m;
	int				x;
	int				y;
	int				mx;
	int				my;
	int				ch;
	int				mo;
	int				c1;
	int				c2;
	int				zoom;
	int				img_x;
	int				img_y;
	int				it_max;
	double			i;
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	double			c_r;
	double			c_i;
	double			z_r;
	double			z_i;
	double			tmp;

}					t_fractol;
int					main(int ac, char **av);
int					key(int key, t_fractol *e);
int					motion(int x, int y, t_fractol *e);
int					key_scroll(int key, int x, int y, t_fractol *e);
void				julia(t_fractol *e);
void				julia1(t_fractol *e);
void				julia2(t_fractol *e);
void				burning(t_fractol *e);
void				init_mlx(t_fractol *e);
void				print_instruction(void);
void				my_fractal(t_fractol *e);
void				init_tools(t_fractol *e);
void				mandelbrot(t_fractol *e);
void				init_julia(t_fractol *e);
void				draw(t_fractol *e, int i);
void				mandelbrot1(t_fractol *e);
void				init_julia1(t_fractol *e);
void				init_julia2(t_fractol *e);
void				choice_color(t_fractol *e);
void				init_burning(t_fractol *e);
void				die(char *str, int exit_code);
void				init_mandelbrot(t_fractol *e);
void				init_mandelbrot1(t_fractol *e);
void				init_create_perso(t_fractol *e);
void				key_zoom(int key, t_fractol *e);
void				key_iter(int key, t_fractol *e);
void				mlx_select(t_fractol *e, int i);
void				choice_fract(t_fractol *e, int i);
void				key_move_zoom(int key, t_fractol *e);
void				key_choice_color(int key, t_fractol *e);

#endif

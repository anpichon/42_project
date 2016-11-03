/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpichon <anpichon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 16:52:59 by anpichon          #+#    #+#             */
/*   Updated: 2016/11/03 10:32:35 by anpichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	display_init(t_fdf *e)
{
	if ((e->m->mlx = mlx_init()) == NULL)
		die("./Fdf : MLX initiation failure !\n", EXIT_FAILURE);
	else
		ft_putstr("Fdf : initiation succes !\n");
	if ((e->m->win = mlx_new_window(e->m->mlx, W, H, "FDF 42")) == NULL)
		die("./Fdf : MLX WIN initiation failure !\n", EXIT_FAILURE);
	else
		ft_putstr("Fdf : Windows initiation succes !\n");
	new_img(e);
	mlx_hook(e->m->win, 2, 3, key, e);
	mlx_loop(e->m->mlx);
}

void	init_param(t_fdf *e)
{
	e->mv_x = 200;
	e->mv_y = 200;
	e->deep = 5;
	e->zoom = 20;
	e->m->c_r = 255;
	e->m->c_b = 27;
	e->m->c_g = 199;
	e->incl = 6;
	e->var = 2;
	e->var1 = 1;
	e->var2 = 0;
}

void	init_color(t_fdf *e, int z)
{
	if (z >= 0 && z <= 3)
		BLUE;
	if (z >= 4 && z <= 6)
		GREY;
	if (z >= 6 && z <= 13)
		BROWN;
	if (z >= 13 && z <= 25)
		YELLOW;
	if (z >= 4 && z <= 6)
		BROW;
	if (z >= 26 && z <= 40)
		GREEN;
	if (z >= 41 && z <= 80)
		BROWN;
	if (z >= 81 && z <= 94)
		GREY;
	if (z > 95)
		WHITE;
}

void	display_menu(t_fdf *e)
{
	if (e->para == 1)
	{
		mlx_string_put(e->m->mlx, e->m->win, 40, 40, 0xFFFFFF,
				"Projection parallele");
		mlx_string_put(e->m->mlx, e->m->win, 40, 60, 0xFFFFFF,
				"Changer de mode : [i]");
	}
	if (e->iso == 1)
	{
		mlx_string_put(e->m->mlx, e->m->win, 40, 40, 0xFFFFFF,
				"Projection isometrique");
		mlx_string_put(e->m->mlx, e->m->win, 40, 60, 0xFFFFFF,
				"Changer de mode : [p]");
	}
	mlx_string_put(e->m->mlx, e->m->win,
					40, 80, 0xFFFFFF, "Zoom : [+] || [-]");
	mlx_string_put(e->m->mlx, e->m->win, 1230, 22, 0xFFFFFF, "^");
	mlx_string_put(e->m->mlx, e->m->win,
					1070, 40, 0xFFFFFF, "Deplacement : <   >");
	mlx_string_put(e->m->mlx, e->m->win, 1230, 58, 0xFFFFFF, "v");
	mlx_string_put(e->m->mlx, e->m->win,
					40, 100, 0xFFFFFF, "Hauteur : [q] || [a]");
	mlx_string_put(e->m->mlx, e->m->win, 40, 120, 0xFFFFFF,
			"Revenir aux parametres par defaut : [space]");
}

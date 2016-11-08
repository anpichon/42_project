/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_display.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpichon <anpichon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:02:43 by anpichon          #+#    #+#             */
/*   Updated: 2016/11/08 06:10:35 by anpichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_mlx(t_fractol *e)
{
	print_instruction();
	ft_putstr("\n**************** Console Log ****************\n\n");
	if (!(e->m.mlx = mlx_init()))
		die("./fractol : initiation mlx failed !", -1);
	else
		ft_putstr("Fractol : MLX              [OK!]\n");
	if (!(e->m.win = mlx_new_window(e->m.mlx, W, H, "Fractol 42 By Anpichon")))
		die("./fractol : initiation window failed !", -1);
	else
		ft_putstr("Fractol : WINDOW           [OK!]\n");
	e->m.img = mlx_new_image(e->m.mlx, W, H);
	ft_putstr("Fractol : IMG              [OK!]\n");
	e->m.dmg = mlx_get_data_addr(e->m.img, &(e->m.bbp), &(e->m.sl), &(e->m.en));
}

void	mlx_select(t_fractol *e, int i)
{
	if ((e->ch == 5 || e->ch == 6 || e->ch == 7) && i != 0)
	{
		mlx_hook(e->m.win, 2, 3, key, e);
		mlx_mouse_hook(e->m.win, key_scroll, e);
		mlx_put_image_to_window(e->m.mlx, e->m.win, e->m.img, 0, 0);
	}
	else if ((e->ch == 1 || e->ch == 2 || e->ch == 3 || e->ch == 4) && i != 0)
	{
		mlx_hook(e->m.win, 6, 1L << 6, motion, e);
		mlx_hook(e->m.win, 2, 3, key, e);
		mlx_mouse_hook(e->m.win, key_scroll, e);
		mlx_put_image_to_window(e->m.mlx, e->m.win, e->m.img, 0, 0);
	}
	else
	{
		mlx_destroy_image(e->m.mlx, e->m.img);
		mlx_destroy_window(e->m.mlx, e->m.win);
		die("Fractol : Error select to function mlx_select !", EXIT_FAILURE);
	}
}

void	draw(t_fractol *e, int i)
{
	if (i != 3)
	{
		if (e->ch == 1)
			mandelbrot(e);
		else if (e->ch == 2)
			julia(e);
		else if (e->ch == 3)
			julia1(e);
		else if (e->ch == 4)
			julia2(e);
		else if (e->ch == 5)
			burning(e);
		else if (e->ch == 6)
			my_fractal(e);
		mlx_select(e, 1);
	}
	else
		choice_fract(e, e->ch);
}

void	choice_fract(t_fractol *e, int i)
{
	e->ch = i;
	init_tools(e);
	if (i == 1)
		mandelbrot(e);
	else if (i == 2)
		julia(e);
	else if (i == 3)
		julia1(e);
	else if (i == 4)
		julia2(e);
	else if (i == 5)
		burning(e);
	else if (i == 6)
		my_fractal(e);
	mlx_select(e, 1);
}

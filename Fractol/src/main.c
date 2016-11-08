/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpichon <anpichon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 09:25:50 by anpichon          #+#    #+#             */
/*   Updated: 2016/11/08 06:54:38 by anpichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	die(char *str, int exit_code)
{
	ft_putendl(str);
	if (exit_code == 1)
	{
		ft_putendl("Help : ./fractol [YOUR CHOICE]");
		ft_putendl("[1] Mandelbrot");
		ft_putendl("[2] Julia");
		ft_putendl("[3] Julia 1");
		ft_putendl("[4] Julia 2");
		ft_putendl("[5] Burning");
		ft_putendl("[6] Mon Fractol");
		exit(EXIT_FAILURE);
	}
	else if (exit_code == -1)
		exit(EXIT_FAILURE);
	else
		exit(EXIT_SUCCESS);
}

void	print_instruction(void)
{
	ft_putstr("\n************* Command Fractol'42 ************\n\n");
	ft_putstr("Move Up                     [^]\n");
	ft_putstr("Move Down                   [v]\n");
	ft_putstr("Move Left                   [<]\n");
	ft_putstr("Move Right                  [>]\n");
	ft_putstr("Change Fractal              [F]\n");
	ft_putstr("Add Itération               [+][I]\n");
	ft_putstr("Del Itération               [-][U]\n");
	ft_putstr("Reset Fractal               [R]\n");
	ft_putstr("Stop Fractal                [M]\n");
	ft_putstr("Change Color                [C][V]\n");
	ft_putstr("Change Red, Green, Blue     [1][2][3]\n");
}

int		main(int ac, char **av)
{
	char		*tmp;
	t_fractol	e;

	ft_memset(&e, 0, sizeof(e));
	if (ac != 2 && ac != 3)
		die("./fractol : Usage : Please place your choice after exec !", 1);
	tmp = av[1];
	if ((ft_strlen(tmp) != 1) || (ft_isdigit(tmp[0]) != 1))
		die("./fractol : Usage : Please select valid choice after exec !", 1);
	e.ch = ft_atoi(av[1]);
	if (e.ch < 0 || e.ch > 6)
		die("./fractol : Usage : Please select valid choice after exec !", 1);
	init_mlx(&e);
	choice_fract(&e, e.ch);
	mlx_loop(e.m.mlx);
	return (0);
}

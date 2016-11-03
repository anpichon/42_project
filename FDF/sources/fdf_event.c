/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpichon <anpichon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 07:26:05 by anpichon          #+#    #+#             */
/*   Updated: 2016/11/03 10:32:55 by anpichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		key1(int key, t_fdf *e)
{
	if (key == 126)
		e->mv_y -= 10;
	else if (key == 125)
		e->mv_y += 10;
	else if (key == 124)
		e->mv_x += 10;
	else if (key == 123)
		e->mv_x -= 10;
	else if (key == 84)
		e->incl += 0.05;
	else if (key == 85)
		e->incl -= 0.05;
}

static void		key_vue(int key, t_fdf *e)
{
	if (key == 35)
	{
		e->para = 1;
		e->iso = 0;
	}
	else if (key == 34)
	{
		e->para = 0;
		e->iso = 1;
	}
}

static void		key_zd_and_colr(int key, t_fdf *e)
{
	if (key == 69 || key == 24)
		e->zoom += 1;
	else if (key == 78 || key == 27)
	{
		if (e->zoom - 1 != 0)
			e->zoom -= 1;
	}
	else if (key == 83)
	{
		if (e->var2 == 0)
			e->var2 = 1;
		else
		{
			e->var2--;
			e->var1++;
			if (e->var1 == 20)
				e->var1 = 0;
		}
	}
}

static void		key_deep(int key, t_fdf *e)
{
	if (key == 12)
	{
		if (e->deep + 1 == 0)
			e->deep = 1;
		else
			e->deep += 1;
	}
	else if (key == 0)
	{
		if (e->deep - 1 == 0)
			e->deep -= 2;
		else
			e->deep -= 1;
	}
}

int				key(int key, t_fdf *e)
{
	if (key == 53)
		die("Fdf : All completed ! Exiting...", EXIT_SUCCESS);
	else if ((key >= 123 && key <= 126) || key == 84 || key == 85)
		key1(key, e);
	else if (key == 35 || key == 34)
		key_vue(key, e);
	else if (key == 69 || key == 27 || key == 24 || key == 78 || key == 83)
		key_zd_and_colr(key, e);
	else if (key == 12 || key == 0)
		key_deep(key, e);
	else if (key == 49)
		init_param(e);
	new_img(e);
	return (1);
}

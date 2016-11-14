/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpichon <anpichon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 09:28:17 by anpichon          #+#    #+#             */
/*   Updated: 2016/11/14 10:35:23 by anpichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include "libft/libft.h"
# include "minilibx/mlx.h"
typedef struct		s_wolf
{
	int				**map; //map[y][0] == Taille de la ligne !
	int				len_y; // Nombre de ligne
	char			*filename; // Nom de la map donnée en para !
	t_mlx			*mlx; // Mlx init
	t_color			wallcolor; // definir la couleur du mur !
	t_matrice		ply; // Matrice de rotation et deplacement
	struct s_wolf	*prev; // Linked list en cas de multi map !
	struct s_wolf	*next;
}					t_wolf;

// Fonction principal

// Fonction parsing && init

// Fonction Calcule

#endif

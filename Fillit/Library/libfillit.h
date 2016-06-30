/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfillit.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpichon <anpichon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 03:40:12 by anpichon          #+#    #+#             */
/*   Updated: 2016/06/24 09:47:47 by anpichon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFILLIT_H
# define LIBFILLIT_H
# define CENTER_M map[i]
# define CENTER_U map[i - (ft_size_map(map) + 1)]
# define CENTER_UR map[i - (ft_size_map(map) + 1) + 1]
# define CENTER_R map[i + 1]
# define CENTER_DR map[i + (ft_size_map(map) + 1) + 1]
# define CENTER_D map[i + (ft_size_map(map) + 1)]
# define CENTER_DL map[i + (ft_size_map(map) + 1) - 1]
# define CENTER_L map[i - 1]
# define CENTER_UL map[i - (ft_size_map(map) + 1) - 1]
# define CENTER_LIM_UL (i > (ft_size_map(map) - 1))
# define CENTER_LIM_U_UR (i > (ft_size_map(map)))
# define LINEAR_B map[x]
# define LINEAR_R map[x + 1]
# define LINEAR_D map[x + ft_size_map(map) + 1]
# define P_CENTER_R split[i + 1]
# define P_CENTER_DL split[i + 3]
# define P_CENTER_D split[i + 4]
# define P_CENTER_DR split[i + 5]
# define P_CENTER_L split[i - 1]
# define P_CENTER_UR split[i - 3]
# define P_CENTER_U split[i - 4]
# define P_CENTER_UL split[i - 5]
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

typedef struct		s_tetri
{
	int				x;
	int				*data;
}					t_tetri;
int					ft_error(void);
int					ft_size_map(char *map);
int					ft_tetri_nbr(char *map);
int					ft_strlen(const char *s);
int					*ft_ctr_pos(char *split);
int					*ft_lnr_pos(char *split);
int					ft_split_nbr(char **split);
int					ft_split_verif(char *split);
int					ft_nb_max_tetri(t_tetri *tetri);
int					ft_all_split_verif(char **split);
int					ft_recursive_power(int nb, int power);
int					ft_ctr_mv(char *map, int *t, int x, char id);
int					ft_lnr_mv(char *map, int *t, int x, char id);
int					ft_mv_tetri(char *map, t_tetri *tetri, int x, char id);
char				*ft_init_map(int size);
char				*ft_readfile(char *file);
char				*ft_upsize_map(char *map);
char				*ft_resolve(t_tetri *tetri);
char				**ft_split_tetri(char *form);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_resolve_tetri(char *map, t_tetri *tetri, int nb_item);
void				ft_putchar(char c);
void				ft_putstr(const char *s);
void				ft_putendl(char const *s);
void				ft_clean_map(char *map, char id);
t_tetri				*ft_all_split_pos(char **split);

#endif

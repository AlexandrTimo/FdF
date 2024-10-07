/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                               :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: atimoshenko <atimoshenko@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 21:05:01 by atimoshenko       #+#    #+#             */
/*   Updated: 2020/03/01 22:26:10 by atimoshenko      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include "minilibx/mlx.h"
# include "libft/libft.h"
# include "libft/get_next_line.h"
# include <fcntl.h>

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define NOEVENTMASK 0L
# define DESTROYNOTIFY 17

typedef struct		s_line
{
	char			**str;
	int				x_str;
	struct s_line	*next;
}					t_line;

typedef struct		s_parse
{
	int				**tab;
	int				x_tab;
	int				y_tab;
}					t_parse;

typedef struct		s_img
{
	void			*img_ptr;
	int				*data;
	int				bpp;
	int				s_l;
	int				endian;
}					t_img;

typedef struct		s_coord
{
	int				x1;
	int				y1;
	int				x2;
	int				y2;
	int				gap_x;
	int				gap_y;
	int				gap_z;
	int				offset_x;
	int				offset_y;
}					t_coord;

typedef struct		s_mlx
{
	void			*ptr;
	void			*wdw;
	int				init;
	int				check;
	int				color;
	char			proj;
	int				count;
	t_img			img;
	t_parse			map;
	t_coord			p;
}					t_mlx;

t_line				*get_map(int fd);
void				check_map(t_line *line, t_parse *map);
t_parse				get_tab(t_line *line);
void				proj_iso(t_mlx *mlx, int *xyz);
void  				proj_p(t_mlx *mlx, int *xyz);
void				draw_map(t_mlx *mlx);
void				swap_xy(int *x1, int *y1, int *x2, int *y2);
void				line(t_mlx *mlx, int color);
int					keyboard(int key, t_mlx *mlx);
int					ft_exit(t_mlx *mlx);
void				init_map(t_mlx *mlx);
void				error_map(int index);
void				define_gap(t_mlx *mlx);
void				menu(t_mlx *mlx);
int					color(t_mlx *mlx, int z1, int z2);
int					in_scr(t_mlx *mlx, char c, int i);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                          :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: atimoshenko <atimoshenko@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 20:05:01 by atimoshenko       #+#    #+#             */
/*   Updated: 2020/03/01 21:26:10 by atimoshenko      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	new_img(t_mlx *mlx)
{
	ft_bzero(mlx->img.data, WIN_WIDTH * WIN_HEIGHT * sizeof(int));
	mlx_clear_window(mlx->ptr, mlx->wdw);
	init_map(mlx);
	mlx_put_image_to_window(mlx->ptr, mlx->wdw, mlx->img.img_ptr, 0, 0);
	menu(mlx);
	return (0);
}

void	move_map(int key, t_mlx *mlx)
{
	if (key == 125)
		mlx->p.offset_y += 5;
	if (key == 126)
		mlx->p.offset_y -= 5;
	if (key == 124)
		mlx->p.offset_x += 5;
	if (key == 123)
		mlx->p.offset_x -= 5;
}

void	change_proj(t_mlx *mlx)
{
	if (mlx->proj == 'i')
		mlx->proj = 'p';
	else if (mlx->proj == 'p')
		mlx->proj = 'i';
	mlx->init = 0;
}

int			keyboard(int key, t_mlx *mlx)
{
	if (key == 53)
		ft_exit(mlx);
	if (key == 69 || key == 24)
	{
		mlx->p.gap_x += 2;
		mlx->p.gap_y += 2;
	}
	if ((key == 78 || key == 27) && mlx->p.gap_x > 2 && mlx->p.gap_y > 2)
	{
		mlx->p.gap_x -= 2;
		mlx->p.gap_y -= 2;
	}
	if (key == 4)
		mlx->p.gap_z++;
	if (key == 37)
		mlx->p.gap_z--;
	if (key >= 123 && key <= 126)
		move_map(key, mlx);
	if (key == 2)
		mlx->color = -1;
	if (key == 8)
		mlx->color = rand();
	if (key == 35)
		change_proj(mlx);
	return (new_img(mlx));
}

void	menu(t_mlx *mlx)
{
	mlx_string_put(mlx->ptr, mlx->wdw, 10, 10, 0xFFFFFF, "Commands:");
	mlx_string_put(mlx->ptr, mlx->wdw, 10, 30, 0xFFFFFF, "Zoom          : +/-");
	mlx_string_put(mlx->ptr, mlx->wdw, 10, 50, 0xFFFFFF, "+/- altitude  : H/L");
	mlx_string_put(mlx->ptr, mlx->wdw, 10, 70, 0xFFFFFF, "Color         : C/D");
	mlx_string_put(mlx->ptr, mlx->wdw, 10, 90, 0xFFFFFF,
			"Move the map  : arrows");
}

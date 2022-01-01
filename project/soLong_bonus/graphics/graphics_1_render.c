/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_1_render.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdulcie <mdulcie@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 00:00:53 by mdulcie           #+#    #+#             */
/*   Updated: 2021/12/28 00:00:58 by mdulcie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "soLong.h"

/*****************************
*   6.5. render_next_frame   *
******************************
*/
/*
 * Description:
 *      This function creates next frame.
 * Return value:
 * 		0.
 * Contains functions:
 * 		6.5.1. move_correct;
 * 		6.5.2. drow_map;
 * 		6.5.3. move_correct_sprites_go;
 * 		5. error_occurse;
 * 		
*/

int	render_next_frame(t_mlx *all)
{
	mlx_do_sync(all->mlx);
	move_correct(all);
	move_correct_sprites_go(all);
	all->frame.img = mlx_new_image(all->mlx, all->map_lenght * BLOCK_SIZE,
		all->map_height * BLOCK_SIZE);
	if (!all->frame.img)
		error_occurse(all, ERROR_MLX_NEW_IMAGE);
	drow_map(all);
	return (0);
}

void	drow_map(t_mlx *all)
{
	int	x;
	int	y;

	(*all).frame.addr = mlx_get_data_addr((*all).frame.img,
			&(*all).frame.b_p_p, &(*all).frame.line_l, &(*all).frame.endian);
	x = 0;
	while (x < all->map_height)
	{
		y = 0;
		while (y < all->map_lenght)
		{
			if (ft_strchr_i("01CE", (*all).map[x][y]) != ft_strlen("01CE"))
				ft_mlx_one_bloke(all, x, y, (*all).map[x][y]);
			++y;
		}
		++x;
	}
	ft_mlx_one_bloke(all, (*all).x_pl, (*all).y_pl, 'P');
	sprites_go_drow(all);
	counters_print_img(all);
	win_img(all);
	mlx_put_image_to_window((*all).mlx, (*all).win, (*all).frame.img, 0, 0);
	mlx_destroy_image((*all).mlx, (*all).frame.img);
	(*all).frame.img = NULL;
}

void	ft_mlx_one_bloke(t_mlx *all, int x, int y, char c)
{
	if (c == '0')
		drow_one_block(all, x, y, all->texture_arrays.floor, -1);
	if (c == '1')
	{
		drow_one_block(all, x, y, all->texture_arrays.floor, -1);
		drow_one_block(all, x, y, all->texture_arrays.wall, COLOR_SKIP);
    }
	if (c == 'C')
    {
		drow_one_block(all, x, y, all->texture_arrays.floor, -1);
        drow_one_block(all, x, y, all->texture_arrays.collect, COLOR_SKIP);
    }
	if (c == 'P')
        drow_one_block(all, x, y, all->texture_arrays.player[all->nb_texture_pl], COLOR_SKIP);
    if (c == 'E')
    {
		drow_one_block(all, x, y, all->texture_arrays.floor, -1);
        drow_one_block(all, x, y, all->texture_arrays.e_exit, COLOR_SKIP);
    }
	if (c == 's')
	{
		drow_one_block(all, x, y, all->texture_arrays.floor, -1);
		gettimeofday(&all->tv, NULL);
        drow_one_block(all, x, y, all->texture_arrays.sprite_s[all->tv.tv_sec % 2], COLOR_SKIP);
	}
}

void    drow_one_block(t_mlx *all, int x, int y,
		int array_to_fill[BLOCK_SIZE][BLOCK_SIZE], int color_skip)
{
	int	i;
	int	j;
	int	color;

	i = 0;
	j = 0;
	while (i < BLOCK_SIZE)
	{
		j = -1;
		while (++j < BLOCK_SIZE)
		{
			color = array_to_fill[i][j];
			if (color != color_skip)
				my_mlx_pix_put(&all->frame, y * all->scale + i,
					x * all->scale + j, color);
		}
		i++;
	}
}

/*****************************************
*		1.4.6.2.1.3.2. my_mlx_pix_put    *
******************************************
* Put color every pix to image.
*/

void	my_mlx_pix_put(t_img *map, int x, int y, int color)
{
	char	*dst;

	dst = map->addr + (x * map->b_p_p / 8 + y * map->line_l);
	*(unsigned int *)dst = color;
}

void	win_img(t_mlx *all)
{
	int	i;
	int	j;
	int	color;

	if (all->collect == all->collect_total)
	{
		i = 0;
		j = 0;
		while (i < BLOCK_SIZE_X4)
		{
			j = -1;
			while (++j < BLOCK_SIZE)
			{
				color = all->texture_arrays.won[i][j];
				if (color != COLOR_SKIP)
					my_mlx_pix_put(&all->frame,
						all->map_lenght / 2 * all->scale - 2 * all->scale + i,
						all->map_height / 2 * all->scale - all->scale / 2 + j,
						color);
			}
			i++;
		}
	}
}

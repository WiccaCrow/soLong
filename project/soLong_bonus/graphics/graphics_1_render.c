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

#include "../soLong.h"

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

/**********************
*   6.5.2. drow_map   *
***********************
*/
/*
 * Description:
 *      The function draws a frame on the image 
 *      in accordance with the specified conditions 
 *      and places the finished image in the game 
 *      window.
 * Contains functions:
 * 		6.5.2.1. ft_mlx_one_bloke;
 * 		6.5.2.2. drow_map_01ces;
 * 		6.5.2.3. sprites_go_drow;
 * 		6.5.2.4. counters_print_img;
 * 		6.5.2.5. win_img;
*/

void	drow_map(t_mlx *all)
{
	all->frame.addr = mlx_get_data_addr(all->frame.img,
			&all->frame.b_p_p, &all->frame.line_l, &all->frame.endian);
	drow_map_01ces(all);
	ft_mlx_one_bloke(all, all->x_pl, all->y_pl, 'P');
	sprites_go_drow(all);
	win_img(all);
	mlx_put_image_to_window(all->mlx, all->win, all->frame.img, 0, 0);
	counters_print_img(all);
	mlx_destroy_image(all->mlx, all->frame.img);
	all->frame.img = NULL;
}

/***************************
*   6.5.2. drow_map_01ces  *
****************************
*/
/*
 * Description:
 *      The function fills the image from the map 
 *      for characters from the string "01CEs"
 * Contains functions:
 * 		6.5.2.1. ft_mlx_one_bloke;
 * 		3.3.1.1. ft_strchr_int;
 * 		gnl. ft_strlen;
*/

void	drow_map_01ces(t_mlx *all)
{
	int	x;
	int	y;

	x = 0;
	while (x < all->map_height)
	{
		y = 0;
		while (y < all->map_lenght)
		{
			if (ft_strchr_int("01CEs", all->map[x][y]) != ft_strlen("01CEs"))
				ft_mlx_one_bloke(all, x, y, all->map[x][y]);
			++y;
		}
		++x;
	}
}

/********************************
*   6.5.2.1. ft_mlx_one_bloke   *
*********************************
*/
/*
 * Description:
 *      The function analyzes the kind of the block and 
 *      draws one block at a time in the corresponding 
 *      coordinates of the image.
 * Contains functions:
 * 		6.5.2.1.1. drow_one_block;
*/

void	ft_mlx_one_bloke(t_mlx *all, int x, int y, char c)
{
	if (c != 'P')
	{
		all->color_skip = -1;
		drow_one_block(all, x, y, all->texture_arrays.floor);
	}
	all->color_skip = COLOR_SKIP;
	if (c == '1')
		drow_one_block(all, x, y, all->texture_arrays.wall);
	if (c == 'C')
		drow_one_block(all, x, y, all->texture_arrays.collect);
	if (c == 'P')
		drow_one_block(all, x, y,
			all->texture_arrays.player[all->nb_texture_pl]);
	if (c == 'E')
		drow_one_block(all, x, y, all->texture_arrays.e_exit);
	if (c == 's')
	{
		gettimeofday(&all->tv, NULL);
		drow_one_block(all, x, y,
			all->texture_arrays.sprite_s[all->tv.tv_sec % 2]);
	}
}

/********************************
*   6.5.2.1.1. drow_one_block   *
*********************************
*/
/*
 * Description:
 * 		The function draws one block at a 
 * 		time in the corresponding coordinates 
 * 		of the image.
 * Contains functions:
 * 		6.5.2.1.1.1. my_mlx_pix_put;
*/

void	drow_one_block(t_mlx *all, int x, int y,
			int array_to_fill[BLOCK_SIZE][BLOCK_SIZE])
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
			if (color != all->color_skip)
				my_mlx_pix_put(&all->frame, y * all->scale + i,
					x * all->scale + j, color);
		}
		i++;
	}
}

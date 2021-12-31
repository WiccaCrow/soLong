/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_1_render  .c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdulcie <mdulcie@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 00:00:53 by mdulcie           #+#    #+#             */
/*   Updated: 2021/12/28 00:00:58 by mdulcie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "soLong.h"
// void    drow_floor(t_mlx *all, int x, int y);

int	render_next_frame(t_mlx *all)
{
	mlx_do_sync(all->mlx);
	move_correct(all);
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
	mlx_put_image_to_window((*all).mlx, (*all).win, (*all).frame.img, 0, 0);
	mlx_destroy_image((*all).mlx, (*all).frame.img);
	(*all).frame.img = NULL;
}

void	ft_mlx_one_bloke(t_mlx *all, int x, int y, char c)
{
	if (c == '0')
		drow_floor(all, x, y, all->texture_arrays.floor, -1);
	if (c == '1')
    {
		drow_floor(all, x, y, all->texture_arrays.floor, -1);
        drow_floor(all, x, y, all->texture_arrays.wall, 0x00FFFFFF);
    }
	if (c == 'C')
    {
		drow_floor(all, x, y, all->texture_arrays.floor, -1);
        drow_floor(all, x, y, all->texture_arrays.collect, 0x00FFFFFF);
    }
	if (c == 'P')
        drow_floor(all, x, y, all->texture_arrays.player, 0x00FFFFFF);
    if (c == 'E')
    {
		drow_floor(all, x, y, all->texture_arrays.floor, -1);
        drow_floor(all, x, y, all->texture_arrays.e_exit, 0x00FFFFFF);
    }
}

void    drow_floor(t_mlx *all, int x, int y, int array_to_fill[BLOCK_SIZE][BLOCK_SIZE], int color_skip)
{
    int	i;
	int	j;
    int color;

	i = 0;
	j = 0;
	while (i < BLOCK_SIZE)
	{
		j = -1;
		while (++j < BLOCK_SIZE)
        {
			color = array_to_fill[i][j];
            // color = color_take(&all->texture_floor, i, j);
            // color = COLOR_SKIP;
			if (color != color_skip)
				my_mlx_pix_put(&all->frame, y * all->scale + i,
					x * all->scale + j, color);
        }
		i++;
	}
}

unsigned int	my_mlx_pix_take(t_img *map, int x, int y)
{
	char	*dst;

	dst = map->addr + (x * map->b_p_p / 8 + y * map->line_l);
	return (*(unsigned int *)dst);
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


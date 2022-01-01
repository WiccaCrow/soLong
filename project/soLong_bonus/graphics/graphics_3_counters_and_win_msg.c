/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_3_counters_and_win_msg.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdulcie <mdulcie@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 00:00:53 by mdulcie           #+#    #+#             */
/*   Updated: 2021/12/28 00:00:58 by mdulcie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../soLong.h"

/*********************************
*   6.5.2.4. counters_print_img  *
**********************************
*/
/*
 * Description:
 *      This function creates next frame.
 * Return value:
 * 		0.
 * Contains functions:
 * 		6.5.2.4.1. ft_itoa;
 *      gnl. ft_strlen;
*/

void	counters_print_img(t_mlx *all)
{
	char	*s_nb;

	s_nb = NULL;
	mlx_string_put(all->mlx, all->win, 10, 16, 0x00FF2566, COUNTERS_STEP);
	s_nb = ft_itoa(all->steps);
	mlx_string_put(all->mlx, all->win,
		ft_strlen(COUNTERS_STEP) * 6 + 16, 16, 0x00FF0066, s_nb);
	free(s_nb);
	mlx_string_put(all->mlx, all->win, 10, 32, 0x00FF2566, COUNTERS_COLLECT);
	s_nb = ft_itoa(all->collect);
	mlx_string_put(all->mlx, all->win,
		ft_strlen(COUNTERS_COLLECT) * 6 + 16, 32, 0x00FF0066, s_nb);
	free(s_nb);
}

/***********************
*   6.5.2.5. win_img   *
************************
*/
/*
 * Description:
 *        The function draws a message about winning 
 *        approximately in the middle of the image.
 * Contains functions:
 * 		  6.5.2.1.1.1. my_mlx_pix_put;
*/

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

/**********************************
*   6.5.2.1.1.1. my_mlx_pix_put   *
***********************************
*/
/*
 * Description:
 * 		Put color every pix to image.
*/

void	my_mlx_pix_put(t_img *map, int x, int y, int color)
{
	char	*dst;

	dst = map->addr + (x * map->b_p_p / 8 + y * map->line_l);
	*(unsigned int *)dst = color;
}

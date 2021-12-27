/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdulcie <mdulcie@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 00:00:53 by mdulcie           #+#    #+#             */
/*   Updated: 2021/12/28 00:00:58 by mdulcie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "soLong.h"


void	graphics(t_mlx *al)
{
	(*al).sprite_data = (t_spr *)malloc(((*al).nb_sprite + 1) * sizeof(t_spr));
	(*al).dist_wall = (float *)malloc(((*al).r_xy[0] + 1) * sizeof(float));
	if (!(*al).sprite_data || !(*al).dist_wall)
	{
		write(1, "Error\nmalloc error.\n", 21);
		exit_clean(al, -1, 0);
	}
	sprite_wall_zero(al);
	find_x_y_player(al, 0, 0);
	if ((*al).win)
	{
		mlx_hook((*al).win, X11_EVENTS_KEYPRESS, 1L << 0, key_press, al);
		mlx_hook((*al).win, X11_EVENTS_KEYREL, 1L << 1, key_release, al);
		mlx_hook((*al).win, X11_EVENTS_EXIT, 0, exit_clean, al);
		mlx_loop_hook((*al).mlx, render_next_frame, al);
		mlx_loop((*al).mlx);
	}
	else
		render_next_frame(al);
	free((*al).sprite_data);
	free((*al).dist_wall);
	(*al).sprite_data = NULL;
	(*al).dist_wall = NULL;
}
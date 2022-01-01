/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_0_keys.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdulcie <mdulcie@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 00:00:53 by mdulcie           #+#    #+#             */
/*   Updated: 2021/12/28 00:00:58 by mdulcie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "soLong.h"

/*************************
*     6. graphics        *
**************************
*/
/*
 * Description:
 *      This function runs games graphics (drow all game in games window).
 * Contains functions:
 * 		6.1. find_x_y_player;
 * 		6.2. key_press;
 * 		6.3. key_release;
 * 		6.4. ft_exit_0;
 * 		6.5. render_next_frame;
*/

void	graphics(t_mlx *all)
{
	find_x_y_player(all, 0, 0);
	all->map[(int)all->x_pl][(int)all->y_pl] = '0';
	mlx_hook(all->win, X11_EVENTS_KEYPRESS, 1L << 0, key_press, all);
	mlx_hook(all->win, X11_EVENTS_KEYREL, 1L << 1, key_release, all);
	mlx_hook(all->win, X11_EVENTS_EXIT, 1L << 0, ft_exit_0, all);
	mlx_loop_hook(all->mlx, render_next_frame, all);
	mlx_loop((*all).mlx);
}

/*****************************
*     6.1. find_x_y_player   *
******************************
*/
/*
 * Description:
 *		This function fills in the player's starting position 
 * 		from the map array.
*/

void	find_x_y_player(t_mlx *all, float x, float y)
{
	while (x < all->map_height)
	{
		y = 0;
		while (x < all->map_height && y <= all->map_lenght)
		{
			if (all->map[(int)x][(int)y] == 'P')
			{
				(*all).x_pl = x + 0.5;
				(*all).y_pl = y + 0.5;
				return ;
			}
			++y;
		}
		++x;
	}
}

/*************************
*     6.2. key_press     *
**************************
*/
/*
 * Description:
 *      The function sets the motion variable run 
 *      ft_exit_0() depending on the pressed key.
 * Return value:
 * 		keycode.
 * Contains functions:
 * 		6.4. ft_exit_0;
*/

int	key_press(int keycode, t_mlx *all)
{
	if (keycode == KEY_LEFT_A || keycode == KEY_LEFT_ARROW)
	{
		(*all).move.a = 1;
		all->nb_texture_pl = 0;
	}
	if (keycode == KEY_UP_W || keycode == KEY_UP_ARROW)
		(*all).move.w = 1;
	if (keycode == KEY_RIGHT_D || keycode == KEY_RIGHT_ARROW)
	{
		(*all).move.d = 1;
		all->nb_texture_pl = 1;
	}
	if (keycode == KEY_DOWN_S || keycode == KEY_DOWN_ARROW)
		(*all).move.s = 1;
	if (keycode == KEY_ESC)
		ft_exit_0(all);
	return (keycode);
}

/*************************
*     6.3. key_release   *
**************************
*/
/*
 * Description:
 *      The function resets the motion or output 
 *      variable depending on the released key.
 * Return value:
 * 		keycode.
*/

int	key_release(int keycode, t_mlx *all)
{
	if (keycode == KEY_LEFT_A || keycode == KEY_LEFT_ARROW)
		(*all).move.a = 0;
	if (keycode == KEY_UP_W || keycode == KEY_UP_ARROW)
		(*all).move.w = 0;
	if (keycode == KEY_RIGHT_D || keycode == KEY_RIGHT_ARROW)
		(*all).move.d = 0;
	if (keycode == KEY_DOWN_S || keycode == KEY_DOWN_ARROW)
		(*all).move.s = 0;
	return (keycode);
}

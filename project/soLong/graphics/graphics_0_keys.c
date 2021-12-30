/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_1_keys                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdulcie <mdulcie@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 00:00:53 by mdulcie           #+#    #+#             */
/*   Updated: 2021/12/28 00:00:58 by mdulcie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "soLong.h"

void	graphics(t_mlx *all)
{
	// (*al).sprite_data = (t_spr *)malloc(((*al).nb_sprite + 1) * sizeof(t_spr));
	// if (!(*al).sprite_data)
	// {
	// 	write(1, "Error\nmalloc error.\n", 21);
	// 	exit_clean(al, -1, 0);
	// }
	// sprite_wall_zero(al);
	find_x_y_player(all, 0, 0);
	all->map[(int)all->x_pl][(int)all->y_pl] = '0';

	mlx_hook(all->win, X11_EVENTS_KEYPRESS, 1L << 0, key_press, all);
	mlx_hook(all->win, X11_EVENTS_KEYREL, 1L << 1, key_release, all);
	mlx_hook(all->win, X11_EVENTS_EXIT, 1L << 0, ft_exit_0, all);
	mlx_loop_hook(all->mlx, render_next_frame, all);
	mlx_loop((*all).mlx);

	// free((*al).sprite_data);
	// (*al).sprite_data = NULL;
}

int	key_press(int keycode, t_mlx *all)
{
	if (keycode == KEY_LEFT_A || keycode == KEY_LEFT_ARROW)
		(*all).move.a = 1;
	if (keycode == KEY_UP_W || keycode == KEY_UP_ARROW)
		(*all).move.w = 1;
	if (keycode == KEY_RIGHT_D || keycode == KEY_RIGHT_ARROW)
		(*all).move.d = 1;
	if (keycode == KEY_DOWN_S || keycode == KEY_DOWN_ARROW)
		(*all).move.s = 1;
	if (keycode == KEY_ESC)
		ft_exit_0(all);
	return (keycode);
}

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

void move_correct(t_mlx *all)
{
	if (all->move.a == 1)
		move_adws(all, 0, -1);
	if (all->move.d == 1)
		move_adws(all, 0, 1);
	if (all->move.w == 1)
		move_adws(all, -1, 0);
	if (all->move.s == 1)
		move_adws(all, 1, 0);
}

void	move_adws(t_mlx *all, int add_x, int add_y)
{
	if (all->map[(int)all->x_pl + add_x][(int)all->y_pl + add_y] != '1')
	{
		all->x_pl += add_x;
		all->y_pl += add_y;
		printf("Current number of movements is: %d\n", ++(all->steps));
		move_adws_collect(all);
		move_adws_exit(all);
	}
}

void	move_adws_collect(t_mlx *all)
{
	if (all->map[(int)all->x_pl][(int)all->y_pl] == 'C')
	{
		all->map[(int)all->x_pl][(int)all->y_pl] = '0';
		all->collect++;
		all->collect_total--;
	}
}

void	move_adws_exit(t_mlx *all)
{
	if (!all->collect_total && all->map[(int)all->x_pl][(int)all->y_pl] == 'E')
	{
		printf("You have collected all the collectibles and now you can go to the exit.\n");
		ft_exit_0(all);
	}
}

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
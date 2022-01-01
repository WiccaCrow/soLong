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
		move_adws_death(all);
		move_adws_collect(all);
		move_adws_exit(all);
	}
}

void	move_adws_death(t_mlx *all)
{
	int	n;

	n = -1;
	while (++n < all->nb_sprites)
	{
		if ((int)all->x_pl == all->sprites[n].x && (int)all->y_pl == all->sprites[n].y)
			game_over(all);
	}
	if (all->map[(int)all->x_pl][(int)all->y_pl] == 's')
		game_over(all);
}

void	game_over(t_mlx *all)
{
	write(STDOUT_FILENO, "GAME OVER\n", 10);
	ft_exit_0(all);
}

void	move_adws_collect(t_mlx *all)
{
	if (all->map[(int)all->x_pl][(int)all->y_pl] == 'C')
	{
		all->map[(int)all->x_pl][(int)all->y_pl] = '0';
		all->collect++;
	}
}

void	move_adws_exit(t_mlx *all)
{
	if (all->collect_total == all->collect && all->map[(int)all->x_pl][(int)all->y_pl] == 'E')
	{
		printf("You have collected all the collectibles and now you can go to the exit.\n");
		ft_exit_0(all);
	}
}

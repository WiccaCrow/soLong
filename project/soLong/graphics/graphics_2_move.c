/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_2_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdulcie <mdulcie@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 00:00:53 by mdulcie           #+#    #+#             */
/*   Updated: 2021/12/28 00:00:58 by mdulcie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "soLong.h"

/*************************
*  6.5.1. move_correct   *
**************************
*/
/*
 * Description:
 *      The function parses the variable movements 
 *      and starts the player's movement function.
 *      
 * Contains functions:
 * 		6.5.1.1. move_adws;
*/

void	move_correct(t_mlx *all)
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

/*************************
*   6.5.1.1. move_adws   *
**************************
*/
/*
 * Description:
 *      The function corrects the position of 
 *      the player, the number of collected 
 *      items and their location, triggers the 
 *      exit from the game when the player enters 
 *      the exit position with collected collectibles.
 *      
 * Contains functions:
 * 		6.5.1.1.1. move_adws_collect;
 * 		6.5.1.1.2. move_adws_exit;
*/

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

/**********************************
*   6.5.1.1.1. move_adws_collect  *
***********************************
*/
/*
 * Description:
 *      The function corrects the number of collected 
 *      items and their location when the player enters 
 *      the collectibles position.
*/

void	move_adws_collect(t_mlx *all)
{
	if (all->map[(int)all->x_pl][(int)all->y_pl] == 'C')
	{
		all->map[(int)all->x_pl][(int)all->y_pl] = '0';
		all->collect++;
		all->collect_total--;
	}
}

/********************************
*   6.5.1.1.2. move_adws_exit   *
*********************************
*/
/*
 * Description:
 *      The function corrects triggers the exit from 
 *      the game when the player hits the exit 
 *      position with collected collectibles.
 *      
 * Contains functions:
 * 		6.4. ft_exit_0;
*/

void	move_adws_exit(t_mlx *all)
{
	if (!all->collect_total && all->map[(int)all->x_pl][(int)all->y_pl] == 'E')
	{
		write(STDOUT_FILENO, "You have collected all the collectibles and", 43);
		write(STDOUT_FILENO, " now you can go to the exit.\n", 29);
		ft_exit_0(all);
	}
}

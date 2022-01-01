/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_go_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdulcie <mdulcie@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 00:00:53 by mdulcie           #+#    #+#             */
/*   Updated: 2021/12/28 00:00:58 by mdulcie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../soLong.h"

/*************************************
*   6.5.3. move_correct_sprites_go   *
**************************************
*/
/*
 * Description:
 *      This function creates next frame.
 * Return value:
 * 		0.
 * Contains functions:
 * 		6.5.3.1. game_over
*/

void	move_correct_sprites_go(t_mlx *all)
{
	int				n;
	struct timeval	tv;

	n = -1;
	gettimeofday(&tv, NULL);
	if ((long int)tv.tv_usec % 2)
	// if ((long int)tv.tv_sec > (long int)all->tv.tv_sec)
	// if ((long int)tv.tv_sec - (long int)all->tv.tv_sec + (long int)tv.tv_usec - (long int)all->tv.tv_usec > 20000)
	{
		// all->tv.tv_sec = tv.tv_sec;
		// all->tv.tv_usec = tv.tv_usec;
		while (++n < all->nb_sprites)
		{
			if (all->map[all->sprites[n].x][all->sprites[n].y
				+ all->sprites[n].kx] != '1')
			{
				all->sprites[n].y += all->sprites[n].kx;
				all->sprites[n].nb_step++;
			}
			else
				all->sprites[n].kx *= -1;
			if ((int)all->x_pl == all->sprites[n].x
				&& (int)all->y_pl == all->sprites[n].y)
				game_over(all);
		}
	}
}

/********************************
*   6.5.1.1.3.1. game_over      *
*********************************
*/
/*
 * Description:
 *      The function prints a message about 
 *      the end of the game to standard output 
 *      and exits the program with code 0.
 *      
 * Contains functions:
 * 		6.4. ft_exit_0;
 * 		gnl. ft_strlen;
*/

void	game_over(t_mlx *all)
{
	write(STDOUT_FILENO, GAME_OVER, ft_strlen(GAME_OVER));
	ft_exit_0(all);
}

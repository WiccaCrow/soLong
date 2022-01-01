/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_2_move_game_over.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdulcie <mdulcie@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 00:00:53 by mdulcie           #+#    #+#             */
/*   Updated: 2021/12/28 00:00:58 by mdulcie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "soLong.h"

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

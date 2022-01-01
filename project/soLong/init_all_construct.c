/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all_construct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdulcie <mdulcie@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 00:00:53 by mdulcie           #+#    #+#             */
/*   Updated: 2021/12/28 00:00:58 by mdulcie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "soLong.h"

/*****************************************
*     2.    construct_t_mlx              *
******************************************
*/
/*
 * Description:
 *		Init all variables and pointers.
 *
 * Contains functions:
 *		2.1. construct_t_mlx_win;
 *		2.2. ft_memset;
 *		5.   error_occurse;
 *		gnl. ft_strlen;
*/

void	construct_t_mlx(t_mlx *all, char **av)
{
	all->argv1 = av[1];
	all->fd = open(all->argv1, O_RDONLY);
	if (all->fd == -1)
		error_occurse(all, ERROR_OPEN);
	construct_t_mlx_win(all);
	all->collect = 0;
	all->collect_total = 0;
	all->player_total = 0;
	all->steps = 0;
	all->line = NULL;
	all->map_begin = NULL;
	all->map = NULL;
	all->map_height = 0;
	all->map_lenght = 0;
	all->scale = BLOCK_SIZE;
	ft_memset(&all->move, 0, sizeof(all->move));
	ft_memset(&all->frame, 0, sizeof(all->frame));
	ft_memset(&all->texture_arrays, 0, sizeof(all->texture_arrays));
}

/*****************************************
*       2.1. construct_t_mlx_win         *
******************************************
*/
/*
 * Description:
 *		Init mlx variable for window of this game.
 *
 * Contains functions:
 *		5.   error_occurse;
*/

void	construct_t_mlx_win(t_mlx *all)
{
	(*all).mlx = NULL;
	(*all).win = NULL;
	(*all).mlx = mlx_init();
	if (!(*all).mlx)
		error_occurse(all, ERROR_MLX_INIT);
}

/*******************************
*		5.1. ft_exit_1         *
********************************
*/
/*
 * Description:
 *		Exit the program without leaks.
 * Exit code:
 * 		1.
 * Contains functions:
 *		7.   destruct_t_mlx;
*/

void	ft_exit_1(t_mlx *all)
{
	destruct_t_mlx(all);
	exit(1);
}

/*******************************
*		5.1. ft_exit_0         *
********************************
*/
/*
 * Description:
 *		Exit the program without leaks.
 * Exit code:
 * 		0.
 * Contains functions:
 *		7.   destruct_t_mlx;
*/

int	ft_exit_0(t_mlx *all)
{
	destruct_t_mlx(all);
	exit(1);
}

/*******************************
*		7. destruct_t_mlx      *
********************************
*/
/*
 * Description:
*	The function clears the allocated memory.
*/

int	destruct_t_mlx(t_mlx *all)
{
	ft_map_list_clear(all, &(all->map_begin));
	if ((*all).line)
		free((*all).line);
	(*all).line = NULL;
	if (all->map)
	{
		free(all->map);
		all->map = NULL;
	}
	if ((*all).frame.img)
		mlx_destroy_image((*all).mlx, (*all).frame.img);
	if (all->win)
		mlx_destroy_window(all->mlx, all->win);
	return (0);
}

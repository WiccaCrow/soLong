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
	construct_t_mlx_win(all);
	all->collect = 0;
	all->collect_total = 0;
	all->player_total = 0;
	all->steps = 0;
	all->nb_texture_pl = 1;
	all->line = NULL;
	all->map = NULL;
	all->map_begin = NULL;
	all->map_height = 0;
	all->map_lenght = 0;
	all->scale = BLOCK_SIZE;
	all->sprites = NULL;
	ft_memset(&all->move, 0, sizeof(all->move));
	ft_memset(&all->frame, 0, sizeof(all->frame));
	ft_memset(&all->texture_arrays, 0, sizeof(all->texture_arrays));
	all->argv1 = av[1];
	all->fd = open(all->argv1, O_RDONLY);
	if (all->fd == -1)
		error_occurse(all, ERROR_OPEN);
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
	all->mlx = NULL;
	all->win = NULL;
	all->mlx = mlx_init();
	if (!all->mlx)
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
*		6.4. ft_exit_0         *
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
	exit(0);
}

/*******************************
*		7. destruct_t_mlx      *
********************************
*/
/*
 * Description:
 *	The function clears the allocated memory.
 * Contains functions:
 * 		7.1. ft_map_list_clear;
*/

int	destruct_t_mlx(t_mlx *all)
{
	int	i;

	if (all->map_begin)
		ft_map_list_clear(&(all->map_begin));
	if (all->line)
		free(all->line);
	all->line = NULL;
	if (all->map)
	{
		i = -1;
		while (++i < all->map_height)
			free(all->map[i]);
		free(all->map);
		all->map = NULL;
	}
	if (all->frame.img)
		mlx_destroy_image(all->mlx, all->frame.img);
	if (all->win)
		mlx_destroy_window(all->mlx, all->win);
	if (SYS_FLAG == 'A')
		system("killall afplay");
	if (SYS_FLAG == 'L')
		system("killall aplay");
	return (0);
}

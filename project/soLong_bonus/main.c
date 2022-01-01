/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdulcie <mdulcie@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 00:00:53 by mdulcie           #+#    #+#             */
/*   Updated: 2021/12/28 00:00:58 by mdulcie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "soLong.h"

/*****************************************
*      0. main                           *
******************************************
 * Description:
 * 	Start the program. 
 * Return value:
 * 	0 if all good.
 *  1 if error occourse.
 * Contains functions:
 * 		1. check_extention_argv;
 * 		2. construct_t_mlx;
 * 		3. parser_valid_argv1;
 * 		4. paste_texture;
 * 		5. error_occurse;
 * 		6. graphics;
 * 		7. destruct_t_mlx;
 * 		8. paste_sprites_go;
 * 		9. bonus_volume;
*/

int	main(int argc, char **argv)
{
	t_mlx	all;

	if (argc == 2)
	{
		check_extention_argv(argv[1], ".ber");
		construct_t_mlx(&all, argv);
		parser_valid_argv1(&all);
		paste_texture(&all);
		paste_sprites_go(&all);
		all.win = mlx_new_window(all.mlx, all.map_lenght * BLOCK_SIZE,
				all.map_height * BLOCK_SIZE, "W");
		if (all.win == NULL)
			error_occurse(&all, ERROR_MLX_NEW_WINDOW);
		bonus_volume();
		graphics(&all);
		destruct_t_mlx(&all);
	}
	else
		write(STDOUT_FILENO, "Error:\nwrong numbers of arguments (argc)\n", 41);
	return (0);
}

/*****************************************
*       5. error_occurse                 *
******************************************
*/
/*
 * Description:
 * 		The function is intended to be called in case of an error.
 * 		The function prints an error message to standard output, 
 * 		clears the memory previously allocated dynamically in the 
 * 		program, and exits the program with code 1.
 * Exit code:
 * 	    1.
 * Contains functions:
 * 		5.1. ft_exit_1;
 * 		gnl. ft_strlen;
*/

void	error_occurse(t_mlx *all, char *msg)
{
	write(STDOUT_FILENO, msg, ft_strlen(msg));
	ft_exit_1(all);
}

/******************************
*      9. bonus_volume        *
*******************************
 * Description:
 * 		Function starts music
*/

void	bonus_volume(void)
{
	if (SYS_FLAG == 'A')
		system("afplay --volume 1 2.wav &");
	if (SYS_FLAG == 'L')
		system("aplay 2.wav &");
}

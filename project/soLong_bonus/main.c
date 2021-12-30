#include "soLong.h"

/*****************************************
*       main                             *
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
 * 		4. destruct_t_mlx;
*/

int main(int argc, char **argv)
{
    t_mlx	all;


    if (argc == 2)
	{
		check_extention_argv(argv[1], ".ber");
    	construct_t_mlx(&all, argv);
		parser_valid_argv1(&all);
		paste_texture(&all);
		paste_sprites_go(&all);

		// 	bonus_volume();
		all.win = mlx_new_window(all.mlx, all.map_lenght * BLOCK_SIZE, all.map_height * BLOCK_SIZE, "W");
		if (all.win == NULL)
			error_occurse(&all, ERROR_MLX_NEW_WINDOW);
		graphics(&all);
    	destruct_t_mlx(&all);
	}
	else
		write(1, "Error:\nwrong numbers of arguments (argc)\n", 41);
    return (0);
}

/*****************************************
*       error_occurse                    *
******************************************
 * Description:
 * 		The function is intended to be called in case of an error.
 * 		The function prints an error message to standard output, 
 * 		clears the memory previously allocated dynamically in the 
 * 		program, and exits the program with code 1.
 * Exit code:
 * 	    1.
 * Contains functions:
 * 		1. ft_strlen;
 * 		2. destruct_t_mlx;
*/

void	error_occurse(t_mlx *all, char *msg)
{
	write(STDOUT_FILENO, msg, ft_strlen(msg));
	ft_exit_1(all);
	exit(1);
}
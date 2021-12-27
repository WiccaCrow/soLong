#include "soLong.h"

int main(int argc, char **argv)
{
    t_mlx	al;


    if (argc == 2)
	{
		check_extention_argv(argv[1], ".ber");
    	construct_t_mlx(&al, argv);
		parser_valid_argv1(&al);

		// parser_valid_argv1(&al, 0, 1, 0);
		// if (argc == 2)
		// {
		// 	bonus_volume();
		// 	al.win = mlx_new_window(al.mlx, al.r_xy[0], al.r_xy[1], "W");
		// }
		// if (argc == 2 && al.win == NULL)
		// 	write(1, "Error\nmlx_new_window error\n", 28);
		// if (!(argc == 2 && al.win == NULL))
			// ft_mlx_functions(&al);
    	destruct_t_mlx(&al);
	}
	else
		write(1, "Error:\nwrong numbers of arguments (argc)\n", 41);
	// exit_clean(&al, -1, 0);

    return (0);
}

void	error_occurse(t_mlx *all, char *msg)
{
	write(STDOUT_FILENO, msg, ft_strlen(msg));
	destruct_t_mlx(all);
	exit(1);
}
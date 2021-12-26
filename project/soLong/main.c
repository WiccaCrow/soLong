#include "soLong.h"

int main(int argc, char argv)
{
    t_mlx	al;

    init_t_mlx(&al);

    if (argc == 2 || argc == 3)
	{
		check_extention_argv(argv[1], ".cub", 0);
		if (argc == 3)
			check_extention_argv(argv[2], "--save", 2);
		al.argv1 = argv[1];
		al.fd = open(al.argv1, O_RDONLY);
		parser_valid_argv1(&al, 0, 1, 0);
		if (argc == 2)
		{
			bonus_volume();
			al.win = mlx_new_window(al.mlx, al.r_xy[0], al.r_xy[1], "W");
		}
		if (argc == 2 && al.win == NULL)
			write(1, "Error\nmlx_new_window error\n", 28);
		if (!(argc == 2 && al.win == NULL))
			ft_mlx_functions(&al);
	}
	else
		write(1, "Error:\nwrong numbers of arguments (argc)\n", 41);
	exit_clean(&al, -1, 0);

    return (0);
}
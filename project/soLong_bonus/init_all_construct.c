#include "soLong.h"

/*****************************************
*	1.1.    construct_t_mlx  			 *
******************************************
*	Init all variables and pointers.
*
*	functions:
*	1.1.1. construct_t_mlx_texture
// *	1.1.2. construct_t_mlx_move_sprite_wall
*/

void	construct_t_mlx(t_mlx *all, char **av)
{
    all->argv1 = av[1];
    all->fd = open(all->argv1, O_RDONLY);
    if (all->fd == -1)
    {
        write(STDOUT_FILENO, ERROR_OPEN, ft_strlen(ERROR_OPEN));
        exit(1);
    }
	construct_t_mlx_texture(all);
	all->collect = 0;
	all->collect_total = 0;
	all->steps = 0;
	all->nb_texture_pl = 1;
	all->player_total = 0;

	all->line = NULL;
	all->map_begin = NULL;
	all->map = NULL;
	all->map_height = 0;
	all->map_lenght = 0;
	all->scale = BLOCK_SIZE;

	all->sprites = NULL;

	ft_memset(&all->move, 0, sizeof(all->move));
	ft_memset(&all->frame, 0, sizeof(all->frame));
	ft_memset(&all->texture_arrays, 0, sizeof(all->texture_arrays));
}


/*****************************************
*		1.1.1. construct_t_mlx_texture	 *
******************************************
*/

void	construct_t_mlx_texture(t_mlx *all)
{
	(*all).mlx = NULL;
	(*all).win = NULL;
	(*all).mlx = mlx_init();
	if (!(*all).mlx)
	{
		write(1, ERROR_MLX_INIT, ft_strlen(ERROR_MLX_INIT));
		exit (1);
	}
}

/*****************************************
*		1.3.4.1.1. exit_clean   	     *
******************************************
*	Exit program. Clean exit.
*/

int    destruct_t_mlx(t_mlx *all)
{
	int	i;

	ft_map_list_clear(all, &(all->map_begin));
	if ((*all).line)
		free((*all).line);
	(*all).line = NULL;
	if (all->map)
	{
		i = -1;
		while (++i < all->map_height)
		{
			free(all->map[i]);
			all->map[i] = NULL;
		}
		free(all->map);
		all->map = NULL;
	}
	if ((*all).frame.img)
		mlx_destroy_image((*all).mlx, (*all).frame.img);
	if (all->win)
		mlx_destroy_window(all->mlx, all->win);
	return (0);
}

void	ft_exit_1(t_mlx *all)
{
	destruct_t_mlx(all);
	exit(1);
}

int	ft_exit_0(t_mlx *all)
{
	destruct_t_mlx(all);
	// system("killall afplay");
	system("killall aplay");
	exit(1);
}
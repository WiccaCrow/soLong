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
	// int	i;

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

	all->line = NULL;
	all->map_begin = NULL;
	all->map = NULL;
	all->map_height = 0;
	all->map_lenght = 0;
	all->scale = BLOCK_SIZE;

	ft_memset(&all->move, 0, sizeof(all->move));
	ft_memset(&all->frame, 0, sizeof(all->frame));
	ft_memset(&all->texture_floor, 0, sizeof(all->texture_floor));
	// all->texture_floor = NULL;

	// (*all).r_xy[0] = 0;
	// (*all).r_xy[1] = 0;
	// i = 3;
	// while (i--)
	// {
	// 	(*all).f_rgb[i] = 0;
	// 	(*all).c_rgb[i] = 0;
	// }
	// (*all).does_paste_r = 0;
	// (*all).does_paste_f = 0;
	// (*all).does_paste_c = 0;
	// (*all).nb_lines = 0;
	// while (i < 6)
	// 	(*all).nswe_s[i++] = 0;
	// (*all).map = NULL;
	// (*all).len_str_max = 0;
	// (*all).player = 0;
	// (*all).free_line = NULL;
	// construct_t_mlx_move_sprite_wall(all);
}

/********************************************
*	1.1.2. construct_t_mlx_move_sprite_wall	*
*********************************************
*/	

// void	start_move_sprite_wall(t_mlx *all)
// {
	// (*all).dist_wall = NULL;
	// (*all).sprite_data = NULL;
	// (*all).move.a = 0;
	// (*all).move.w = 0;
	// (*all).move.d = 0;
	// (*all).move.s = 0;
	// (*all).move.arrow_l = 0;
	// (*all).move.arrow_r = 0;
// }

/*****************************************
*		1.1.1. construct_t_mlx_texture	 *
******************************************
*/

void	construct_t_mlx_texture(t_mlx *all)
{
	// int	i;

	(*all).mlx = NULL;
	(*all).win = NULL;
	(*all).mlx = mlx_init();
	if (!(*all).mlx)
	{
		write(1, ERROR_MLX_INIT, ft_strlen(ERROR_MLX_INIT));
		exit (1);
	}
	// i = -1;
	// while (++i < 5)
	// {
	// 	(*all).texture_nswe_s[i].img = NULL;
	// 	(*all).texture_nswe_s[i].addr = NULL;
	// }
	// (*all).frame.img = NULL;
}

/*****************************************
*		1.3.4.1.1. exit_clean   	     *
******************************************
*	Exit program. Clean exit.
*/

// int	exit_clean(t_mlx *all, int i, int ii)
int    destruct_t_mlx(t_mlx *all)
{
	if (all->map)
	{
		free(all->map);
		all->map = NULL;
	}
	ft_map_list_clear(&(all->map_begin), ft_map_list_delone);
	if ((*all).line)
		free((*all).line);
	(*all).line = NULL;

	if ((*all).texture_floor.img)
			mlx_destroy_image((*all).mlx, (all->texture_floor.img));
	if ((*all).frame.img)
		mlx_destroy_image((*all).mlx, (*all).frame.img);

	if (all->win)
		mlx_destroy_window(all->mlx, all->win);
	exit (1);
	return (0);
}
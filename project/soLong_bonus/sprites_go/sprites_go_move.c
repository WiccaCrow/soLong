#include "../soLong.h"

void	move_correct_sprites_go(t_mlx *all)
{
    int             n;
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
            if (all->map[all->sprites[n].x][all->sprites[n].y + all->sprites[n].kx] != '1')
            {
                all->sprites[n].y += all->sprites[n].kx;
                all->sprites[n].nb_step++;
            }
            else
                all->sprites[n].kx *= -1;
            if ((int)all->x_pl == all->sprites[n].x && (int)all->y_pl == all->sprites[n].y)
			    game_over(all);
        }
    }
}

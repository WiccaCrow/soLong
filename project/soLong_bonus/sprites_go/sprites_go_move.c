#include "../soLong.h"

void	move_correct_sprites_go(t_mlx *all)
{
    int             n;
    struct timeval	tv;
    n = -1;
    gettimeofday(&tv, NULL);
    if (tv.tv_usec - all->tv.tv_usec > 20000)
    // if (tv.tv_sec - all->tv.tv_sec > 0)
    {
        while (++n < all->nb_sprites)
        {
            if (all->map[all->sprites[n].x][all->sprites[n].y + all->sprites[n].kx] != '1')
            {
                all->sprites[n].y += all->sprites[n].kx;
                all->sprites[n].nb_step++;
            }
            else
                all->sprites[n].kx *= -1;
        }
    }
}

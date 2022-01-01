#include "../soLong.h"

void	sprites_go_drow(t_mlx *all)
{
    int n;
    int z;

    n = -1;
    z = 0;
    while (++n < all->nb_sprites)
    {
        z = all->sprites[n].nb_step % 2;
        if (all->sprites[n].kx == -1)
            z += 2;
        drow_one_block(all, all->sprites[n].x, all->sprites[n].y, all->texture_arrays.sprite_go[z], 0x00FFFFFF);
    }
}

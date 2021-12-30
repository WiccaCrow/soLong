#include "../soLong.h"

void	paste_sprites_go(t_mlx *all)
{
    all->nb_sprites = sprite_counting(all);
    all->sprites = (t_spr *)malloc(sizeof(t_spr) * all->nb_sprites);
    if (!all->sprites)
        ft_exit_1(all);
    fill_sprites_go(all);
}

int sprite_counting(t_mlx *all)
{
    int nb_sprite;
    int i;
    int j;

    nb_sprite = 0;
    i = -1;
    while (++i < all->map_height)
    {
        j = -1;
        while (++j < all->map_lenght)
        {
            if (all->map[i][j] == 'S')
                ++nb_sprite;
        }
    }
    return(nb_sprite);
}

void fill_sprites_go(t_mlx *all)
{
    int i;
    int j;
    int n;

    n = 0;
    i = -1;
    while (++i < all->map_height)
    {
        j = -1;
        while (++j < all->map_lenght)
        {
            if (all->map[i][j] == 'S')
            {
                all->sprites[n].x = i;
                all->sprites[n].y = j;
                all->sprites[n].kx = 1;
                all->sprites[n].nb_step = 0;
                all->map[i][j] = '0';
                ++n;
            }
        }
    }
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_go.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdulcie <mdulcie@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 00:00:53 by mdulcie           #+#    #+#             */
/*   Updated: 2021/12/28 00:00:58 by mdulcie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../soLong.h"

/*****************************************
*       8. paste_sprites_go              *
******************************************
 * Description:
 * 		The function creates an array of moving 
 *      sprites and fills in their starting positions (t_spr).
 * Contains functions:
 *      8.1. sprite_counting;
 *      8.2. fill_sprites_go;
 *      5. error_occurse;
*/

void	paste_sprites_go(t_mlx *all)
{
    all->nb_sprites = sprite_counting(all);
    all->sprites = (t_spr *)malloc(sizeof(t_spr) * all->nb_sprites);
    if (!all->sprites)
        error_occurse(all, ERROR_MALLOC);
    fill_sprites_go(all);
}

/*****************************************
*       8.1. paste_sprites_go            *
******************************************
 * Description:
 * 		The function counts the number of moving sprites.
 * Return value:
 *      number of moving sprites.
*/

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


/*****************************************
*       8.2. fill_sprites_go             *
******************************************
 * Description:
 *      The function fills starting positions 
 *      (in t_spr array) of moving sprites.
*/

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

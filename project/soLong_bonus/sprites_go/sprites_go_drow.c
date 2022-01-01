/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_go_drow.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdulcie <mdulcie@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 00:00:53 by mdulcie           #+#    #+#             */
/*   Updated: 2021/12/28 00:00:58 by mdulcie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../soLong.h"

/*****************************
*   6.5.2.3. drow_map_01ces  *
******************************
*/
/*
 * Description:
 *      The function draws all movable sprites 
 *      on the image.
 * Contains functions:
 * 		6.5.2.1. ft_mlx_one_bloke;
*/

void	sprites_go_drow(t_mlx *all)
{
	int	n;
	int	z;

	n = -1;
	z = 0;
	while (++n < all->nb_sprites)
	{
		z = all->sprites[n].nb_step % 2;
		if (all->sprites[n].kx == -1)
			z += 2;
		drow_one_block(all, all->sprites[n].x, all->sprites[n].y,
			all->texture_arrays.sprite_go[z]);
	}
}

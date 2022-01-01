/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_init_won.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdulcie <mdulcie@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 00:00:53 by mdulcie           #+#    #+#             */
/*   Updated: 2021/12/28 00:00:58 by mdulcie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../soLong.h"

/*****************************************
*           4.2. texture_won             *
******************************************
*/
/*
 * Description:
 *	   The function checks extension of str
 *	   and fills img_to_fill (subfunction texture2).
 *
 * Contains functioins:
 *		4.2.1. fill_img_array_won;
 *		4.1.1. texture_check_extention;
 *		4.1.2. texture_img_init;
 *		5.     error_occurse;
*/

void	texture_won(t_mlx *all, char *str,
		int array_to_fill[BLOCK_SIZE_X4][BLOCK_SIZE])
{
	t_img	img_to_fill;

	if (texture_check_extention(str, TEXTURE_EXTENSION_XPM))
		error_occurse(all, ERROR_TEXTURE_FORMAT);
	else
	{
		texture_img_init(all, &img_to_fill, str);
		fill_img_array_won(array_to_fill, &img_to_fill);
		mlx_destroy_image(all->mlx, img_to_fill.img);
	}
}

/***************************************
*       4.2.1. fill_img_array_won      *
****************************************
*/
/*
 * Description:
 *      This function fills an array of colors 
 *      from the texture if the player wins.
 *
 * Contains functioins:
 *      4.1.3.1.1. my_mlx_pix_take;
*/

void	fill_img_array_won(int array_to_fill[BLOCK_SIZE_X4][BLOCK_SIZE],
		t_img *img_to_fill)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < BLOCK_SIZE_X4)
	{
		j = -1;
		while (++j < BLOCK_SIZE)
			array_to_fill[i][j]
				= my_mlx_pix_take(img_to_fill,
					i * (float)img_to_fill->height / (float)BLOCK_SIZE,
					j * (float)img_to_fill->width / (float)BLOCK_SIZE / 4);
		i++;
	}
}

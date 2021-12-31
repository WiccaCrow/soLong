/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_1_render  .c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdulcie <mdulcie@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 00:00:53 by mdulcie           #+#    #+#             */
/*   Updated: 2021/12/28 00:00:58 by mdulcie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../soLong.h"

void	texture_won(t_mlx *all, char *str, int array_to_fill[BLOCK_SIZE * 4][BLOCK_SIZE])
{
	t_img	img_to_fill;

	if (texture_check_extention(str, TEXTURE_EXTENSION_XPM))
			error_occurse(all, ERROR_TEXTURE_FORMAT);
	else
	{
		texture_img_init(all, &img_to_fill, str);
		fill_img_array_won(array_to_fill, &img_to_fill);
		mlx_destroy_image((*all).mlx, img_to_fill.img);
	}
}

void	fill_img_array_won(int array_to_fill[BLOCK_SIZE * 4][BLOCK_SIZE], t_img *img_to_fill)
{
	int	i;
	int	j;
	int block_size_4;

	i = 0;
	j = 0;
	block_size_4 = BLOCK_SIZE * 4;
	while (i < block_size_4)
	{
		j = -1;
		while (++j < BLOCK_SIZE)
			array_to_fill[i][j] = my_mlx_pix_take(img_to_fill, i * (float)img_to_fill->height / (float)BLOCK_SIZE, j * (float)img_to_fill->width / (float)BLOCK_SIZE / 4);
		i++;
	}
}

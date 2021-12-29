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

void	paste_texture(t_mlx *all)
{
	texture1(all, TEXTURE_FLOOR, all->texture_arrays.collect);
	texture1(all, TEXTURE_FLOOR, all->texture_arrays.e_exit);
	texture1(all, TEXTURE_FLOOR, all->texture_arrays.floor);
	texture1(all, TEXTURE_FLOOR, all->texture_arrays.player);
	texture1(all, TEXTURE_FLOOR, all->texture_arrays.wall);
}

/*****************************************
*                texture1                *
******************************************
*	The function checks extension of str, does re-fill img_to_fill,
*	and fills img_to_fill (subfunction texture2).
*
* Contains functioins:
*		ft_strlen;
*		error_occurse;
*		texture2;
*/

void	texture1(t_mlx *all, char *str, int array_to_fill[BLOCK_SIZE][BLOCK_SIZE])
{
	int	str_i;
	int	i;
	char *extension;

	extension = TEXTURE_EXTENTION;
	str_i = ft_strlen(str);
	i = 5;
	while (--i)
		if (str[str_i - i] != extension[4 - i])
			error_occurse(all, ERROR_TEXTURE_FORMAT);
	texture2(all, str, array_to_fill);
}

/*****************************************
*                texture2                *
******************************************
*	Paste textures trom str to img_to_fill.
*
* Contains functioins:
*		error_occurse;
*/

void	texture2(t_mlx *all, char *str, int array_to_fill[BLOCK_SIZE][BLOCK_SIZE])
{
	int 	fd;
	t_img 	img_to_fill;


	fd = open(str, O_RDONLY);
	if (fd < 0)
		error_occurse(all, ERROR_TEXTURE_OPEN);
	close(fd);
	img_to_fill.img = mlx_xpm_file_to_image(all->mlx, str,
			&img_to_fill.width, &img_to_fill.height);
	if (img_to_fill.img)
		img_to_fill.addr = mlx_get_data_addr(img_to_fill.img,
				&img_to_fill.b_p_p,
				&img_to_fill.line_l,
				&img_to_fill.endian);
	if (!img_to_fill.addr)
		error_occurse(all, ERROR_TEXTURE_ADDR);
	fill_img_array(array_to_fill, &img_to_fill);
	mlx_destroy_image((*all).mlx, img_to_fill.img);
}

void	fill_img_array(int array_to_fill[BLOCK_SIZE][BLOCK_SIZE], t_img *img_to_fill)
{
	int	i;
	int	j;
    int color;

	i = 0;
	j = 0;
	while (i < BLOCK_SIZE)
	{
		j = -1;
		while (++j < BLOCK_SIZE)
        {
            color = color_take(img_to_fill, i, j);
            // color = COLOR_SKIP;
			array_to_fill[i][j] = color;
        }
		i++;
	}
}

int	color_take(t_img *map, float i,float j)
{
	float	scale;

	scale = (float)map->height / (float)BLOCK_SIZE;
	return (my_mlx_pix_take(map, i * scale, j * scale));
}
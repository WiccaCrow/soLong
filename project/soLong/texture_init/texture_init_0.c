/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_init_0.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdulcie <mdulcie@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 00:00:53 by mdulcie           #+#    #+#             */
/*   Updated: 2021/12/28 00:00:58 by mdulcie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../soLong.h"

/*************************
*     4. paste_texture   *
**************************
*/
/*
 * Description:
 *      This function fills in all color texture arrays 
 *      (using a subfunction texture1).
 * Contains functions:
 * 		4.1. texture1;
*/

void	paste_texture(t_mlx *all)
{
	texture1(all, TEXTURE_COLLECT, all->texture_arrays.collect);
	texture1(all, TEXTURE_EXIT, all->texture_arrays.e_exit);
	texture1(all, TEXTURE_FLOOR, all->texture_arrays.floor);
	texture1(all, TEXTURE_PL_R_1, all->texture_arrays.player);
	texture1(all, TEXTURE_WALL, all->texture_arrays.wall);
}

/*****************************************
*           4.1. texture1                *
******************************************
*/
/*
 * Description:
 *	   The function checks extension of str
 *	   and fills img_to_fill (subfunction texture2).
 *
 * Contains functioins:
 *		4.1.1. texture2;
 *		5.     error_occurse;
 *		gnl.   ft_strlen;
*/

void	texture1(t_mlx *all, char *str,
			int array_to_fill[BLOCK_SIZE][BLOCK_SIZE])
{
	int		str_i;
	int		i;
	char	*extension;

	extension = TEXTURE_EXTENTION;
	str_i = ft_strlen(str);
	i = 5;
	while (--i)
		if (str[str_i - i] != extension[4 - i])
			error_occurse(all, ERROR_TEXTURE_FORMAT);
	texture2(all, str, array_to_fill);
}

/*****************************************
*       4.1.1.   texture2                *
******************************************
*/
/*
 * Description:
 *	Paste textures trom str to img_to_fill.
 *
 * Contains functioins:
 *      4.1.1.1. fill_img_array;
 *		5. error_occurse;
*/

void	texture2(t_mlx *all, char *str,
			int array_to_fill[BLOCK_SIZE][BLOCK_SIZE])
{
	int		fd;
	t_img	img_to_fill;

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

/*****************************************
*       4.1.1.1.   fill_img_array        *
******************************************
*/
/*
 * Description:
 *	      This function fills an array of colors from a texture.
 *
 * Contains functioins:
 *      4.1.1.1.1. color_take;
*/

void	fill_img_array(int array_to_fill[BLOCK_SIZE][BLOCK_SIZE],
			t_img *img_to_fill)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < BLOCK_SIZE)
	{
		j = -1;
		while (++j < BLOCK_SIZE)
			array_to_fill[i][j] = color_take(img_to_fill, i, j);
		i++;
	}
}

/*****************************************
*       4.1.1.1.1.   color_take          *
******************************************
*/
/*
 * Description:
 *        This function takes one color from a texture 
 *        (in i and j coordinates).
 *
 * Contains functioins:
 *      4.1.1.1.1.1. my_mlx_pix_take;
*/

int	color_take(t_img *map, float i, float j)
{
	int	x;
	int	y;

	x = j * (float)map->height / (float)BLOCK_SIZE;
	y = i * (float)map->width / (float)BLOCK_SIZE;
	return (my_mlx_pix_take(map, y, x));
}

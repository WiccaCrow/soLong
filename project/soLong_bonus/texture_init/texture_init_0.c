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
 * 		4.1. texture;
 * 		4.2. texture_won;
*/

void	paste_texture(t_mlx *all)
{
	texture(all, TEXTURE_COLLECT, all->texture_arrays.collect);
	texture(all, TEXTURE_EXIT, all->texture_arrays.e_exit);
	texture(all, TEXTURE_FLOOR, all->texture_arrays.floor);
	texture(all, TEXTURE_PL_L_1, all->texture_arrays.player[0]);
	texture(all, TEXTURE_PL_R_1, all->texture_arrays.player[1]);
	texture(all, TEXTURE_SPRITE_Sl_L, all->texture_arrays.sprite_s[0]);
	texture(all, TEXTURE_SPRITE_Sl_R, all->texture_arrays.sprite_s[1]);
	texture(all, TEXTURE_SPRITE_S_R_1, all->texture_arrays.sprite_go[0]);
	texture(all, TEXTURE_SPRITE_S_R_2, all->texture_arrays.sprite_go[1]);
	texture(all, TEXTURE_SPRITE_S_L_1, all->texture_arrays.sprite_go[2]);
	texture(all, TEXTURE_SPRITE_S_L_2, all->texture_arrays.sprite_go[3]);
	texture(all, TEXTURE_WALL, all->texture_arrays.wall);
	texture_won(all, TEXTURE_WON, all->texture_arrays.won);
}

/*****************************************
*           4.1. texture                 *
******************************************
*/
/*
 * Description:
 *	   The function checks extension of str
 *	   and fills img_to_fill (subfunction texture2).
 *
 * Contains functioins:
 *		4.1.1. texture_check_extention;
 *		4.1.2. texture_img_init;
  *		4.1.3. fill_img_array;
 *		5.     error_occurse;
*/

void	texture(t_mlx *all, char *str,
		int array_to_fill[BLOCK_SIZE][BLOCK_SIZE])
{
	t_img	img_to_fill;

	if (texture_check_extention(str, TEXTURE_EXTENSION_XPM))
		error_occurse(all, ERROR_TEXTURE_FORMAT);
	else
	{
		texture_img_init(all, &img_to_fill, str);
		fill_img_array(array_to_fill, &img_to_fill);
		mlx_destroy_image(all->mlx, img_to_fill.img);
	}
}

/*****************************************
*     4.1.1. texture_check_extention     *
******************************************
*/
/*
 * Description:
 *		The function checks extension of str.
 * Return value:
 *		1 if bad extention.
 *		0 if good extention.
 * Contains functioins:
 *		gnl. ft_strlen;
*/

int	texture_check_extention(char *str, char *extension)
{
	int	str_i;
	int	i;

	str_i = ft_strlen(str);
	i = 5;
	while (--i)
		if (str[str_i - i] != extension[4 - i])
			return (1);
	return (0);
}

/*****************************************
*       4.1.2. texture_img_init          *
******************************************
*/
/*
 * Description:
 *	   The function checks extension of str
 *	   and fills img_to_fill (subfunction texture2).
 * Contains functioins:
 *		5.     error_occurse;
*/

void	texture_img_init(t_mlx *all, t_img *img_to_fill, char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		printf("Error\n %s\n", str);
		error_occurse(all, ERROR_TEXTURE_OPEN);
	}
	close(fd);
	img_to_fill->img = mlx_xpm_file_to_image(all->mlx, str,
			&img_to_fill->width, &img_to_fill->height);
	if (img_to_fill->img)
		img_to_fill->addr = mlx_get_data_addr(img_to_fill->img,
				&img_to_fill->b_p_p,
				&img_to_fill->line_l,
				&img_to_fill->endian);
	if (!img_to_fill->addr)
		error_occurse(all, ERROR_TEXTURE_ADDR);
}

/***************************************
*       4.1.3.   fill_img_array        *
****************************************
*/
/*
 * Description:
 *	      This function fills an array of colors from a texture.
 *
 * Contains functioins:
 *      4.1.3.1. color_take;
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

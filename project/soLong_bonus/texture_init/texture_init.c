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
	texture1(all, TEXTURE_COLLECT, all->texture_arrays.collect);
	texture1(all, TEXTURE_EXIT, all->texture_arrays.e_exit);
	texture1(all, TEXTURE_FLOOR, all->texture_arrays.floor);
	texture1(all, TEXTURE_PL_L_1, all->texture_arrays.player[0]);
	texture1(all, TEXTURE_PL_R_1, all->texture_arrays.player[1]);
	texture1(all, TEXTURE_SPRITE_Sl_L, all->texture_arrays.sprite_s[0]);
	texture1(all, TEXTURE_SPRITE_Sl_R, all->texture_arrays.sprite_s[1]);
	texture1(all, TEXTURE_SPRITE_S_R_1, all->texture_arrays.sprite_go[0]);
	texture1(all, TEXTURE_SPRITE_S_R_2, all->texture_arrays.sprite_go[1]);	
	texture1(all, TEXTURE_SPRITE_S_L_1, all->texture_arrays.sprite_go[2]);
	texture1(all, TEXTURE_SPRITE_S_L_2, all->texture_arrays.sprite_go[3]);
	texture1(all, TEXTURE_WALL, all->texture_arrays.wall);
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
	if (texture1_check_extention(str, TEXTURE_EXTENSION_XPM))
	{
		// if (texture1_check_extention(str, TEXTURE_EXTENSION_PNG))
			error_occurse(all, ERROR_TEXTURE_FORMAT);
		// else
		// 	texture2(all, str, array_to_fill, 2);
	}
	else
		texture2(all, str, array_to_fill, 1);
}

int	texture1_check_extention(char *str, char *extension)
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
*                texture2                *
******************************************
*	Paste textures trom str to img_to_fill.
*
* Contains functioins:
*		error_occurse;
*/

void	texture2(t_mlx *all, char *str, int array_to_fill[BLOCK_SIZE][BLOCK_SIZE], int flag)
{
	int 	fd;
	t_img 	img_to_fill;


	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		printf("Error\n %s\n", str);
		error_occurse(all, ERROR_TEXTURE_OPEN);
	}
	close(fd);
	if (flag == 1)
		img_to_fill.img = mlx_xpm_file_to_image(all->mlx, str,
				&img_to_fill.width, &img_to_fill.height);
	// else
	// 	img_to_fill.img = mlx_png_file_to_image(all->mlx, str,
	// 			&img_to_fill.width, &img_to_fill.height);
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

int	color_take(t_img *map, float i,float j)
{
	int		x;
	int		y;

	x = j * (float)map->height / (float)BLOCK_SIZE;
	y = i * (float)map->width / (float)BLOCK_SIZE;
	return (my_mlx_pix_take(map, y, x));
}
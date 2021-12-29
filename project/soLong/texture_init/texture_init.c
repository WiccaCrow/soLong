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
	texture1(all, TEXTURE_FLOOR, TEXTURE_EXTENTION, &all->texture_floor);
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

void	texture1(t_mlx *all, char *str, char *extension, t_img *img_to_fill)
{
	int	str_i;
	int	i;

	str_i = ft_strlen(str);
	i = 5;
	while (--i)
		if (str[str_i - i] != extension[4 - i])
			error_occurse(all, ERROR_TEXTURE_FORMAT);
	if (img_to_fill->img)
		error_occurse(all, ERROR_TEXTURE_REFILL);
	texture2(all, str, img_to_fill);
}

/*****************************************
*                texture2                *
******************************************
*	Paste textures trom str to img_to_fill.
*
* Contains functioins:
*		error_occurse;
*/

void	texture2(t_mlx *all, char *str, t_img *img_to_fill)
{
	int fd;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		error_occurse(all, ERROR_TEXTURE_OPEN);
	close(fd);
	img_to_fill->img = mlx_xpm_file_to_image(all->mlx, str,
			&img_to_fill->width, &img_to_fill->height);
	if (img_to_fill->img)
		img_to_fill->addr = mlx_get_data_addr(img_to_fill,
				&img_to_fill->b_p_p,
				&img_to_fill->line_l,
				&img_to_fill->endian);
	if (!img_to_fill->addr)
		error_occurse(all, ERROR_TEXTURE_ADDR);

	if (img_to_fill)
	;

	// t_img img;
		// img.img = mlx_xpm_file_to_image(all->mlx, str,
		// 	&img.width, &img.height);
	// if (img.img)
	// 	img.addr = mlx_get_data_addr(&img,
	// 			&img.b_p_p,
	// 			&img.line_l,
	// 			&img.endian);
	// if (!img.addr)
	// 	error_occurse(all, ERROR_TEXTURE_ADDR);
}
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
	texture1(all, TEXTURE_FLOOR, TEXTURE_EXTENTION);
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

void	texture1(t_mlx *all, char *str, char *extension)
{
	int	str_i;
	int	i;

	str_i = ft_strlen(str);
	i = 5;
	while (--i)
		if (str[str_i - i] != extension[4 - i])
			error_occurse(all, ERROR_TEXTURE_FORMAT);
	if (all->texture_floor.addr)
		error_occurse(all, ERROR_TEXTURE_REFILL);
	texture2(all, str);
}

/*****************************************
*                texture2                *
******************************************
*	Paste textures trom str to img_to_fill.
*
* Contains functioins:
*		error_occurse;
*/

void	texture2(t_mlx *all, char *str)
{
	int fd;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		error_occurse(all, ERROR_TEXTURE_OPEN);
	close(fd);
	all->texture_floor.img = mlx_xpm_file_to_image(all->mlx, str,
			&(*all).texture_floor.width, &(*all).texture_floor.height);
	if (all->texture_floor.img)
		all->texture_floor.addr = mlx_get_data_addr(&all->texture_floor,
				&(*all).texture_floor.b_p_p,
				&(*all).texture_floor.line_l,
				&(*all).texture_floor.endian);
	if (!all->texture_floor.addr)
		error_occurse(all, ERROR_TEXTURE_ADDR);
}
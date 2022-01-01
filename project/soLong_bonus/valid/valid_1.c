/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdulcie <mdulcie@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 00:00:53 by mdulcie           #+#    #+#             */
/*   Updated: 2021/12/28 00:00:58 by mdulcie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../soLong.h"

/*****************************************
*           valid_one_char               *
******************************************
*/
/*
 * Description:
 *		The function checks the validity of a specific symbol 
 *		(whether the character char_to_check matches the set of characters 
 *		in the string simbols).
 * Contains functions:
 *		1. error_occurse;
*/

void	valid_one_char(t_mlx *all, char *simbols, char char_to_check)
{
	int	i_s;
	int	valid_flag;

	i_s = -1;
	valid_flag = 0;
	while (simbols[++i_s])
	{
		if (simbols[i_s] == char_to_check)
			valid_flag = 1;
	}
	if (!valid_flag)
	{
		if ((*simbols == '1' && ft_strlen(simbols) == 1))
			error_occurse(all, ERROR_MAP_CLOSED);
		error_occurse(all, ERROR_MAP_SIMBOLS);
	}
}

/*****************************************
*           map_add_list                 *
******************************************
*/
/*
 * Description:
 *		The function adds next line in list of map lines.
 * Contains functions:
 *		1. ft_map_list_add_back;
 *		2. ft_map_list_new;
*/

void	map_add_list(t_mlx *all)
{
	all->map_height++;
	ft_map_list_add_back(&(all->map_begin), ft_map_list_new(all));
}

/*****************************************
*           map_array_fill               *
******************************************
*/
/*
 * Description:
 *		The function fills map array from map list.
 * Contains functions:
 *		1. error_occurse;
*/

void	map_array_fill(t_mlx *all)
{
	t_map_list	*ptr_map;
	int			i;

	i = 0;
	ptr_map = all->map_begin;
	all->map = (char **)malloc(sizeof(char *) * (all->map_height));
	if (!all->map)
		error_occurse(all, ERROR_MALLOC);
	while (i < all->map_height)
	{
		all->map[i] = ft_strdup(ptr_map->line);
		free(ptr_map->line);
		ptr_map->line = NULL;
		ptr_map = ptr_map->next;
		++i;
	}
}

/*****************************************
*           checks_character_sets        *
******************************************
*/
/*
 * Description:
 *		The function checks if the complete set of required (by subject) 
 *		symbols is present on the map.
 * Contains functions:
 *		1. error_occurse;
*/

void	checks_character_sets(t_mlx *all)
{
	int		i;
	int		j;
	int		set_01cep_int[6];
	char	*set_01cep_char;

	set_01cep_char = "01CEP";
	checks_character_sets_find_matches(all, set_01cep_int, set_01cep_char);
	i = 5;
	j = 0;
	while (i--)
		j += set_01cep_int[i];
	if (j)
		error_occurse(all, ERROR_MAP_SIMBOLS_INCOMPLETE);
}

/******************************************************
*           checks_character_sets_find_matches        *
*******************************************************
*/
/*
 * Description:
 *		The function is subfunction of checks_character_sets.
 *		The function finds matches of symbols on the map with the minimum 
 *		required set of symbols for the validity of the map.
 *		The found characters are set to 0 in array set_01cep_int.
 * Contains functions:
 *		1. ft_strchr_int;
*/

void	checks_character_sets_find_matches(t_mlx *all, int *set_01cep_int,
		char *set_01cep_char)
{
	int		char_pos;
	int		i;
	int		j;

	i = 5;
	while (i--)
		set_01cep_int[i] = 1;
	set_01cep_int[5] = 0;
	while (++i < all->map_height)
	{
		j = -1;
		while (all->map[i][++j])
		{
			char_pos = ft_strchr_int(set_01cep_char, all->map[i][j]);
			set_01cep_int[char_pos] = 0;
		}
	}
}

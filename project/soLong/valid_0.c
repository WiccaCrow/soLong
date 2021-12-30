/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdulcie <mdulcie@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 00:00:53 by mdulcie           #+#    #+#             */
/*   Updated: 2021/12/28 00:00:58 by mdulcie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "soLong.h"

/*****************************************
*       check_extention_argv             *
******************************************
*/
/*
 * Description:
 * 	The function checks the validity of the map file extension 
 * 	(.ber in subject). 
*/

void	check_extention_argv(char *av, char *extension)
{
	int	len_ext;
	int	len_av;

	len_ext = ft_strlen(extension);
	len_av = ft_strlen(av);
	if (len_ext <= len_av)
	{
		while (len_ext && (extension[len_ext - 1] == av[--len_av]))
			--len_ext;
	}
	if (len_ext)
	{
		write(STDOUT_FILENO, ERROR_MAP_EXTENTION,
			ft_strlen(ERROR_MAP_EXTENTION));
		exit (1);
	}
}

/*****************************************
*           parser_valid_argv1           *
******************************************
*/
/*
 * Description:
 *		The function checks the validity of the card entered as an argument 
 *		to the program.
 *		In case of an error, a subfunction "error_occurse" is called with the 
 *		appropriate message.
 * Contains functions:
 *		1. map_check_and_fill;
 *		2. ft_strlen;
 *		3. error_occurse;
 *		4. map_array_fill;
 *		5. checks_character_sets;
*/

void	parser_valid_argv1(t_mlx *all)
{
	int	gnl;

	gnl = map_check_and_fill(all);
	if (all->fd >= 0 && gnl < 0)
		close (all->fd);
	if (gnl < 0)
		error_occurse(all, ERROR_OPEN);
	if (all->map_lenght != ft_strlen(all->line))
		error_occurse(all, ERROR_MAP_RECTANGULAR);
	all->line = NULL;
	close (all->fd);
	map_array_fill(all);
	checks_character_sets(all);
}

/*****************************************
*           map_check_and_fill           *
******************************************
*/
/*
 * Description:
 *		The function checks and fills the map array.
 *		In case of an error, a subfunction "error_occurse" is called with the 
 *		appropriate message.
 * Contains functions:
 *		1. get_next_line (take next line from file);
 *		2. ft_strlen;
 *		3. valid_empty_map;
 *		4. valid_fill_map;
 *		5. map_add_list;
*/

int	map_check_and_fill(t_mlx *all)
{
	int	gnl;

	gnl = get_next_line(all->fd, &all->line);
	all->map_lenght = ft_strlen(all->line);
	valid_empty_map(all, gnl, all->map_lenght);
	valid_fill_map(all, "1");
	while (gnl > 0 && all->map_lenght == ft_strlen(all->line))
	{
		map_add_list(all, all->line);
		valid_fill_map(all, "01CEP");
		all->line = NULL;
		gnl = get_next_line(all->fd, &all->line);
	}
	map_add_list(all, all->line);
	valid_fill_map(all, "1");
	return (gnl);
}

/*****************************************
*           valid_empty_map              *
******************************************
*/
/*
 * Description:
 *		The function checks map. Does it empty?
 * Contains functions:
 *		1. error_occurse;
*/

void	valid_empty_map(t_mlx *all, int gnl, int len_line)
{
	if (gnl == 0 && len_line == 0)
	{
		close ((*all).fd);
		error_occurse(all, ERROR_MAP_EMPTY);
	}
}

/*****************************************
*           valid_fill_map               *
******************************************
*/
/*
 * Description:
 *		The function checks the map. 
 *		Is it closed and are the map symbols valid?
 * Contains functions:
 *		1. valid_one_char;
 *		2. error_occurse;
*/

void	valid_fill_map(t_mlx *all, char *simbols)
{
	int	i;

	i = -1;
	while (all->line[++i])
	{
		valid_one_char(all, simbols, all->line[i]);
		if (all->line[i] == 'C')
			++all->collect_total;
		if (all->line[i] == 'P')
			++all->player_total;
	}
	if (all->player_total > 1)
		error_occurse(all, ERROR_MAP_PLAYER);
	if (all->line[0] != '1' || all->line[ft_strlen(all->line) - 1] != '1')
		error_occurse(all, ERROR_MAP_CLOSED);
}

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

#include "../soLong.h"

/*****************************************
*       1. check_extention_argv          *
******************************************
*/
/*
 * Description:
 * 	The function checks the validity of the map file extension 
 * 	(.ber in subject). 
 * Contains functions:
 * 		gnl. ft_strlen;
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
*       3.  parser_valid_argv1           *
******************************************
*/
/*
 * Description:
 *		The function checks the validity of the card entered as an argument 
 *		to the program.
 *		In case of an error, a subfunction "error_occurse" is called with the 
 *		appropriate message.
 * Contains functions:
 *		3.1. map_check_and_fill;
 *		3.2. map_array_fill;
 *		3.3. checks_character_sets;
 *		5. error_occurse;
 *		gnl. ft_strlen;
*/

void	parser_valid_argv1(t_mlx *all)
{
	int	gnl;

	gnl = map_check_and_fill(all);
	if (all->fd >= 0 && gnl < 0)
		close (all->fd);
	if (gnl < 0)
		error_occurse(all, ERROR_OPEN);
	close (all->fd);
	map_array_fill(all);
	checks_character_sets(all);
}

/*****************************************
*           3.1. map_check_and_fill      *
******************************************
*/
/*
 * Description:
 *		The function checks and fills the map array.
 *		In case of an error, a subfunction "error_occurse" is called with the 
 *		appropriate message.
 * Contains functions:
 *		3.1.1. valid_empty_map;
 *		3.1.2. valid_fill_map;
 *		3.1.3. map_add_list;
 *		gnl. get_next_line;
 *		gnl. ft_strlen;
*/

int	map_check_and_fill(t_mlx *all)
{
	int	gnl;

	gnl = get_next_line(all->fd, &all->line);
	all->map_lenght = ft_strlen(all->line);
	valid_empty_map(all, gnl, all->map_lenght);
	valid_fill_map(all, "1");
	while (gnl > 0)
	{
		valid_fill_map(all, MAP_SIMBOLS);
		map_add_list(all);
		gnl = get_next_line(all->fd, &all->line);
	}
	valid_fill_map(all, "1");
	map_add_list(all);
	return (gnl);
}

/*****************************************
*      3.1.1. valid_empty_map            *
******************************************
*/
/*
 * Description:
 *		The function checks map. Does it empty?
 * Contains functions:
 *		5. error_occurse;
*/

void	valid_empty_map(t_mlx *all, int gnl, int len_line)
{
	if (gnl == 0 && len_line == 0)
	{
		close (all->fd);
		error_occurse(all, ERROR_MAP_EMPTY);
	}
}

/*****************************************
*     3.1.2. valid_fill_map              *
******************************************
*/
/*
 * Description:
 *		The function checks the map. 
 *		Is it closed and are the map symbols valid?
 * Contains functions:
 *		3.1.2.1. valid_one_char;
 *		5. error_occurse;
 *		gnl. ft_strlen;
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
	if (all->map_lenght != ft_strlen(all->line))
		error_occurse(all, ERROR_MAP_RECTANGULAR);
	if (all->player_total > 1)
		error_occurse(all, ERROR_MAP_PLAYER);
	if (all->line[0] != '1' || all->line[ft_strlen(all->line) - 1] != '1')
		error_occurse(all, ERROR_MAP_CLOSED);
}

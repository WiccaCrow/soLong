#include "soLong.h"

/*****************************************
*	1.2. check_extention_argv 		     *
******************************************
*/

void	check_extention_argv(char *av, char *extension)
{
	int len_ext;
	int len_av;
	
	len_ext = ft_strlen(extension);
	len_av = ft_strlen(av);
	if (len_ext <= len_av)
	{
		while (len_ext && (extension[len_ext - 1] == av[--len_av]))
			--len_ext;
	}
	if (len_ext)
	{
		write(STDOUT_FILENO, ERROR_map_extention, 
			ft_strlen(ERROR_map_extention));
		exit (1);
	}
}

/*****************************************
*	1.3.    parser_valid_argv1           *
******************************************
*	the function works with the first argument:
*	1. Reads the file with the map line by line.
*	2. Calls the function of checking empty lines between the map parameters
*		"NO SO WE EA S"
*	3. Checks which particular map parameter needs to be filled and calls 
*		the functions for filling the map and parameters from the argument.
*	4. Runs the function for checking the screen size and program window
*
*	functions:
*	1.3.1. get_next_line (take next line from file)
*		./map/gnl
*	1.3.2. check_empty_line_beetwen_options
*	1.3.3. ft_strchr 
*		./map/libft_add_functions.c
*	1.3.4. parser_r_f_c
*	1.3.5. paste_no_so_we_ea_s 
*		./map/fill_all_except_the_map.c
*	1.3.6. map
*	1.3.7. exit_clean
*	1.3.8. check_screen_size
*/

void	parser_valid_argv1(t_mlx *all)
{
	int	gnl;
	int	len_line;

	gnl = get_next_line(all->fd, &all->line);
	len_line = ft_strlen(all->line);
	valid_empty_map(all, gnl, len_line);
	valid_fill_map(all, "1");
	while (gnl > 0 && len_line == ft_strlen(all->line))
	{
		map_add_list(all, all->line);
		valid_fill_map(all, "01CEP");
		all->line = NULL;
		gnl = get_next_line(all->fd, &all->line);
	}
	map_add_list(all, all->line);
	valid_fill_map(all, "1");
	if (all->fd >= 0 && gnl < 0)
		close (all->fd);
	if (gnl < 0)
		error_occurse(all, "Error\nfile with map was not open or read (gnl)\n");
	if (len_line != ft_strlen(all->line))
		error_occurse(all, "Error\nThe map must be rectangular\n");
	all->line = NULL;
	close (all->fd);
	map_array_fill(all);

}

//check map. Does it empty?
void	valid_empty_map(t_mlx *all, int gnl, int len_line)
{
	if (gnl == 0 && len_line == 0)
	{
		close ((*all).fd);
		error_occurse(all, "Error\n empty map\n");
	}
}

//check map. Does it close and valid simbols?
void	valid_fill_map(t_mlx *all, char *simbols)
{
	int i;

	i = -1;
	while (all->line[++i])
	{
		valid_one_char(all, simbols, all->line[i]);
		if (all->line[i] == 'C')
			++all->collect_total;
	}
	if (all->line[0] != '1' || all->line[ft_strlen(all->line) - 1] != '1')
		error_occurse(all, "Error\n The map must be closed/surrounded by wall\n");
}

//check char_to_check. Does it in valid simbols?
void	valid_one_char(t_mlx *all, char *simbols, char char_to_check)
{
	int i_s;
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
			error_occurse(all, "Error\n The map must be closed/surrounded by wall\n");
		error_occurse(all, "Error\n invalid symbols in the map\n");
	}
}

// add next line in list of map lines
void	map_add_list(t_mlx *all, char *line)
{
	all->nb_map_lines++;
	ft_map_list_add_back(&(all->map_begin), ft_map_list_new(line));
}

// fill map array from map list
void	map_array_fill(t_mlx *all)
{
	t_map_list *ptr_map;
	int 		i;

	i = 0;
	ptr_map = all->map_begin;
	all->map = (char**)malloc(sizeof(char*) * (all->nb_map_lines));
	if (!all->map)
		error_occurse(all, "Error\n malloc error\n");
	while (i < all->nb_map_lines)
	{
		all->map[i] = ptr_map->line;
		ptr_map->line = NULL;
		ptr_map = ptr_map->next;
		++i;
	}
}

#ifndef SOLONG_H
# define SOLONG_H

# include "../mlx/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
#include "../gnl/get_next_line.h"

#include "stdio.h"

// ERRORS
# define ERROR_map_extention "Error\n wrong extension of 1st argument\n"
# define ERROR_open "Error\n error opening file with map\n"

typedef struct s_map_list {
	char				*line;
	struct s_map_list	*next;
}	t_map_list;

typedef struct s_mlx {
	//for graphics
	void			*mlx;
	void			*win;

	// map file
	char			*argv1;
	int				fd;
	char			*line;
	char			**map;
	int				nb_map_lines;
	t_map_list		*map_begin;

	// collectible
	int				collect;
	int				collect_total;

}	t_mlx;


// lib_functions
//		file: lib_functions/lib_functions.c
t_map_list		*ft_map_list_new(char *line);
t_map_list		*ft_map_list_last(t_map_list *lst);
void			ft_map_list_add_back(t_map_list **lst, t_map_list *new);
void			ft_map_list_clear(t_map_list **lst, void (*del)(t_map_list*));
void			ft_map_list_delone(t_map_list *lst);
// char		*ft_strdup(const char *s1);


// constructors/init and destructors/clean
// 		file: init_all_construct.c
void    construct_t_mlx(t_mlx *all, char **av);
void	construct_t_mlx_texture(t_mlx *all);
void    destruct_t_mlx(t_mlx *all);


// validate and fill map array
//		file: valid.c
void	check_extention_argv(char *av, char *extension);
void	parser_valid_argv1(t_mlx *all);
void	valid_empty_map(t_mlx *all, int gnl, int len_line);
void	valid_fill_map(t_mlx *all, char *simbols);
void	valid_one_char(t_mlx *all, char *simbols, char char_to_check);
void	map_add_list(t_mlx *all, char *line);
void	map_array_fill(t_mlx *all);


// errors
//		file: main.c
void	error_occurse(t_mlx *all, char *msg);

#endif
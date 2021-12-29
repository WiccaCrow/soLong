#ifndef SOLONG_H
# define SOLONG_H

# include "../mlx/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
#include "../gnl/get_next_line.h"

#include "stdio.h"

// ERRORS
//					parser errors
# define ERROR_OPEN "Error\n error opening file with map\n"
# define ERROR_MALLOC "Error\n malloc error\n"
# define ERROR_MAP_EXTENTION "Error\n wrong extension of 1st argument\n"
# define ERROR_MAP_RECTANGULAR "Error\nThe map must be rectangular\n"
# define ERROR_MAP_EMPTY "Error\n empty map\n"
# define ERROR_MAP_CLOSED "Error\n The map must be closed/surrounded by wall\n"
# define ERROR_MAP_SIMBOLS "Error\n invalid symbols in the map\n"
# define ERROR_MAP_SIMBOLS_INCOMPLETE "Error\n the map character set is incomplete. Required characters: 01CEP\n"
//					graphics errors
# define ERROR_MLX_INIT "Error\n mlx_init error.\n"
# define ERROR_MLX_NEW_IMAGE "Error\n mlx_new_image error.\n"
# define ERROR_MLX_NEW_WINDOW "Error\nmlx_new_window error\n"
# define ERROR_TEXTURE_FORMAT "Error\nTexture's format is bad.\n"
# define ERROR_TEXTURE_REFILL "Error\nre-fill the textures.\n"
# define ERROR_TEXTURE_OPEN "Error\nTexture. The file does not exist or is bad.\n"
# define ERROR_TEXTURE_ADDR "Error\nmlx error (addr or img).\n"


// move
typedef struct s_move {
	double	a;
	double	w;
	double	d;
	double	s;
	// double	arrow_l;
	// double	arrow_r;
}	t_move;

// frame
typedef struct s_img {
	int		width;
	int		height;
	void	*img;
	char	*addr;
	int		b_p_p;
	int		line_l;
	int		endian;
}	t_img;

// Datas
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
	int				map_height;
	int				map_lenght;
	t_map_list		*map_begin;

	// collectible
	int				collect;
	int				collect_total;

	// steps;
	int				steps;

	// player position and move
	float			x_pl;
	float			y_pl;
	t_move			move;

	// frame
	t_img			frame;
	int				scale;
	t_img			texture_floor;

}	t_mlx;

/******************************************************************************/
/*                       Init, exit, errors, parser                           */
/******************************************************************************/

// lib_functions
//		file: lib_functions/lib_functions_0.c
t_map_list		*ft_map_list_new(t_mlx *all, char *line);
t_map_list		*ft_map_list_last(t_map_list *lst);
void			ft_map_list_add_back(t_map_list **lst, t_map_list *new);
void			ft_map_list_clear(t_map_list **lst, void (*del)(t_map_list*));
void			ft_map_list_delone(t_map_list *lst);
//		file: lib_functions/lib_functions_1.c
int				ft_strchr_int(const char *s, int c);
void			*ft_memset(void *b, int c, size_t len);



// constructors/init and destructors/clean ( init game )
// 		file: init_all_construct.c
void    construct_t_mlx(t_mlx *all, char **av);
void	construct_t_mlx_texture(t_mlx *all);
int	    destruct_t_mlx(t_mlx *all);


// validate and fill map array
//		file: valid.c
void	check_extention_argv(char *av, char *extension);
void	parser_valid_argv1(t_mlx *all);
int		map_check_and_fill(t_mlx *all);
void	valid_empty_map(t_mlx *all, int gnl, int len_line);
void	valid_fill_map(t_mlx *all, char *simbols);
void	valid_one_char(t_mlx *all, char *simbols, char char_to_check);
void	map_add_list(t_mlx *all, char *line);
void	map_array_fill(t_mlx *all);
void	checks_character_sets(t_mlx *all);
void	checks_character_sets_find_matches(t_mlx *all, int *set_01cep_int, char *set_01cep_char);


// errors
//		file: main.c
void	error_occurse(t_mlx *all, char *msg);

/******************************************************************************/
/*                       graphics                                             */
/******************************************************************************/

// start
void	paste_texture(t_mlx *all);
void	texture1(t_mlx *all, char *str, char *extension, t_img *img_to_fill);
void	texture2(t_mlx *all, char *str, t_img *img_to_fill);
// void	texture1(t_mlx *all, char *str, char *extension);
// void	texture2(t_mlx *all, char *str);

void	graphics(t_mlx *all);

// find start player position
void	find_x_y_player(t_mlx *all, float x, float y);

// catch key
int		key_press(int keycode, t_mlx *all);
int		key_release(int keycode, t_mlx *all);

// drow image and move
//		render. start
int		render_next_frame(t_mlx *all);
//		move
void 	move_correct(t_mlx *all);
void	move_adws(t_mlx *all, int add_x, int add_y);
void	move_adws_collect(t_mlx *all);
void	move_adws_exit(t_mlx *all);
//		drow
void	drow_map(t_mlx *all);
void	ft_mlx_one_bloke(t_mlx *all, int x, int y, char c);
unsigned int	my_mlx_pix_take(t_img *map, int x, int y);
void	my_mlx_pix_put(t_img *map, int x, int y, int color);

// keys
# define	KEY_LEFT_A 0
# define	KEY_UP_W 13
# define	KEY_RIGHT_D 2
# define	KEY_DOWN_S 1
# define	KEY_ESC 53

# define	X11_EVENTS_KEYPRESS 2
# define	X11_EVENTS_KEYREL 3
# define	X11_EVENTS_EXIT 17

// game settings
# define	COLOR_SKIP 0x00FFFFFF
// Scale
# define 	BLOCK_SIZE 64
// texture
# define	TEXTURE_EXTENTION ".xpm"
// # define	TEXTURE_EXTENTION ".png"
// # define	TEXTURE_FLOOR "round.xpm"
// # define	TEXTURE_FLOOR "2.xpm"

// # define	TEXTURE_FLOOR "c.xpm"
# define	TEXTURE_FLOOR "floor.xpm"
// # define	TEXTURE_FLOOR "1.png"


#endif
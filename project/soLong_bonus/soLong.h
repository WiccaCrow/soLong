/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soLong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdulcie <mdulcie@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 00:00:53 by mdulcie           #+#    #+#             */
/*   Updated: 2021/12/28 00:00:58 by mdulcie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include "../mlx/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "../gnl/get_next_line.h"

# include "stdio.h"
# include "sys/time.h"
// ERRORS
//					parser errors
# define ERROR_OPEN "Error\n error opening file with map\n"
# define ERROR_MALLOC "Error\n malloc error\n"
# define ERROR_MAP_EXTENTION "Error\n wrong extension of 1st argument\n"
# define ERROR_MAP_RECTANGULAR "Error\nThe map must be rectangular\n"
# define ERROR_MAP_EMPTY "Error\n empty map\n"
# define ERROR_MAP_CLOSED "Error\n The map must be closed/surrounded by wall\n"
# define ERROR_MAP_SIMBOLS "Error\n invalid symbols in the map\n"
# define ERROR_MAP_PLAYER "Error\n too many players\n"
# define ERROR_MAP_SIMBOLS_INCOMPLETE "Error\n the map character set is \
incomplete. Required characters: 01CEP\n"
//					graphics errors
# define ERROR_MLX_INIT "Error\n mlx_init error.\n"
# define ERROR_MLX_NEW_IMAGE "Error\n mlx_new_image error.\n"
# define ERROR_MLX_NEW_WINDOW "Error\nmlx_new_window error\n"
# define ERROR_TEXTURE_FORMAT "Error\nTexture's format is bad.\n"
# define ERROR_TEXTURE_REFILL "Error\nre-fill the textures.\n"
# define ERROR_TEXTURE_OPEN "Error\nTexture. The file does not exist or is bad.\n"
# define ERROR_TEXTURE_ADDR "Error\nmlx error (addr or img).\n"

// keys
# if defined(__APPLE__)
#  define KEY_LEFT_A 0
#  define KEY_UP_W 13
#  define KEY_RIGHT_D 2
#  define KEY_DOWN_S 1
#  define KEY_LEFT_ARROW 123
#  define KEY_UP_ARROW 126
#  define KEY_RIGHT_ARROW 124
#  define KEY_DOWN_ARROW 125
#  define KEY_ESC 53
#  define SYS_FLAG 'A'
# else
#  define KEY_LEFT_A 97
#  define KEY_UP_W 119
#  define KEY_RIGHT_D 100
#  define KEY_DOWN_S 115
#  define KEY_LEFT_ARROW 65361
#  define KEY_UP_ARROW 65362
#  define KEY_RIGHT_ARROW 65363
#  define KEY_DOWN_ARROW 65364
#  define KEY_ESC 65307
#  define SYS_FLAG 'L'
# endif

# define X11_EVENTS_KEYPRESS 2
# define X11_EVENTS_KEYREL 3
# define X11_EVENTS_EXIT 17

# define MAP_SIMBOLS "01CEPsS"

# define COUNTERS_STEP "Current number of movements is: "
# define COUNTERS_COLLECT "Your money: "
# define WON_EXIT "\033[38;2;255;255;10mYou have collected \
all the collectibles and now you can go to the exit.\n\033[0m"
# define GAME_OVER "\033[21;38;2;0;128;0mGAME OVER\n\033[0m"

// game settings
# define COLOR_SKIP 0x00FFFFFF
// Scale
// # define BLOCK_SIZE 96
// # define BLOCK_SIZE_X4 384
# define BLOCK_SIZE 48
# define BLOCK_SIZE_X4 192
// texture
# define TEXTURE_EXTENSION_XPM ".xpm"
// speed of sprites
# define SPEED 7

# define TEXTURE_FLOOR "./textures/grass-1.xpm"
//# define	TEXTURE_FLOOR "./textures/floor_grass.xpm"
// # define	TEXTURE_WALL "./textures/wall_1.xpm"
# define TEXTURE_WALL "./textures/wall_trees.xpm"
# define TEXTURE_COLLECT "./textures/texture_ring.xpm"
# define TEXTURE_EXIT "./textures/1.xpm"
# define TEXTURE_PL_R_1 "./textures/texture_pirate_1-r.xpm"
# define TEXTURE_PL_L_1 "./textures/texture_pirate_1-l.xpm"
# define TEXTURE_SPRITE_SL_L "./textures/texture_sprite_sit-l2.xpm"
# define TEXTURE_SPRITE_SL_R "./textures/texture_sprite_sit-r2.xpm"
# define TEXTURE_SPRITE_S_L_1 "./textures/texture_sprite_go_l_1.xpm"
# define TEXTURE_SPRITE_S_L_2 "./textures/texture_sprite_go_l_2.xpm"
# define TEXTURE_SPRITE_S_R_1 "./textures/texture_sprite_go_r_1.xpm"
# define TEXTURE_SPRITE_S_R_2 "./textures/texture_sprite_go_r_2.xpm"
# define TEXTURE_WON "./textures/Won-door.xpm"

//
// textures
typedef struct s_texture {
	int	floor[BLOCK_SIZE][BLOCK_SIZE];
	int	wall[BLOCK_SIZE][BLOCK_SIZE];
	int	collect[BLOCK_SIZE][BLOCK_SIZE];
	int	player[2][BLOCK_SIZE][BLOCK_SIZE];
	int	sprite_s[3][BLOCK_SIZE][BLOCK_SIZE];
	int	sprite_go[4][BLOCK_SIZE][BLOCK_SIZE];
	int	e_exit[BLOCK_SIZE][BLOCK_SIZE];
	int	won[BLOCK_SIZE_X4][BLOCK_SIZE];
}	t_img_array;

//
// move
typedef struct s_move {
	double	a;
	double	w;
	double	d;
	double	s;
}	t_move;

// sprites S
typedef struct s_sprite {
	int	x;
	int	y;
	int	kx;
	int	nb_step;
}	t_spr;

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
	void			*mlx;
	void			*win;
	char			*argv1;
	int				fd;
	char			*line;
	char			**map;
	int				map_height;
	int				map_lenght;
	t_map_list		*map_begin;
	int				collect;
	int				collect_total;
	int				steps;
	int				player_total;
	float			x_pl;
	float			y_pl;
	t_move			move;
	int				nb_texture_pl;
	t_spr			*sprites;
	int				nb_sprites;
	t_img			frame;
	int				scale;
	t_img			texture_floor;
	t_img_array		texture_arrays;
	struct timeval	tv;
	struct timeval	tv_sprites_go;
	int				color_skip;
}	t_mlx;

// typedef struct s_mlx {
// 	//for graphics
// 	void			*mlx;
// 	void			*win;

// 	// map file
// 	char			*argv1;
// 	int				fd;
// 	char			*line;
// 	char			**map;
// 	int				map_height;
// 	int				map_lenght;
// 	t_map_list		*map_begin;

// 	// collectible
// 	int				collect;
// 	int				collect_total;

// 	// steps;
// 	int				steps;

// 	// player position and move
// 	int				player_total;
// 	float			x_pl;
// 	float			y_pl;
// 	t_move			move;
// 	int				nb_texture_pl;

// 	// sprites (go)
// 	t_spr			*sprites;
// 	int				nb_sprites;

// 	// frame
// 	t_img			frame;
// 	int				scale;
// 	t_img			texture_floor;
// 	t_img_array		texture_arrays;//memset0

// 	// system time
// 	struct timeval	tv;

// 	int			color_skip;
// }	t_mlx;

/******************************************************************************/
/*                       Init, exit, errors, parser                           */
/******************************************************************************/

// lib_functions
//		file: lib_functions/lib_functions_0.c
t_map_list		*ft_map_list_new(t_mlx *all);
t_map_list		*ft_map_list_last(t_map_list *lst);
void			ft_map_list_add_back(t_map_list **lst, t_map_list *new_list);
void			ft_map_list_clear(t_map_list **lst);
void			ft_map_list_delone(t_map_list *lst);
//		file: lib_functions/lib_functions_1.c
int				ft_strchr_int(const char *s, int c);
void			*ft_memset(void *b, int c, size_t len);
char			*ft_itoa(int n);

// constructors/init and destructors/clean ( init game )
// 		file: init_all_construct.c
void			construct_t_mlx(t_mlx *all, char **av);
void			construct_t_mlx_win(t_mlx *all);
int				destruct_t_mlx(t_mlx *all);
int				ft_exit_0(t_mlx *all);
void			ft_exit_1(t_mlx *all);

// validate and fill map array
//		file: valid_0.c
void			check_extention_argv(char *av, char *extension);
void			parser_valid_argv1(t_mlx *all);
int				map_check_and_fill(t_mlx *all);
void			valid_empty_map(t_mlx *all, int gnl, int len_line);
void			valid_fill_map(t_mlx *all, char *simbols);
//		file: valid_1.c
void			valid_one_char(t_mlx *all, char *simbols, char char_to_check);
void			map_add_list(t_mlx *all);
void			map_array_fill(t_mlx *all);
void			checks_character_sets(t_mlx *all);
void			checks_character_sets_find_matches(t_mlx *all,
					int *set_01cep_int, char *set_01cep_char);

// init sprites_go
//		file: sprites_go.c
void			fill_sprites_go(t_mlx *all);
int				sprite_counting(t_mlx *all);
void			paste_sprites_go(t_mlx *all);

// errors
//		file: main.c
void			error_occurse(t_mlx *all, char *msg);

// volume
//		file: main.c
void			bonus_volume(void);

/******************************************************************************/
/*                       graphics                                             */
/******************************************************************************/

// start init
//		file: texture_init/texture_init_0.c
void			paste_texture(t_mlx *all);
void			texture(t_mlx *all, char *str,
					int array_to_fill[BLOCK_SIZE][BLOCK_SIZE]);
int				texture_check_extention(char *str, char *extension);
void			texture_img_init(t_mlx *all, t_img *img_to_fill, char *str);
void			fill_img_array(int array_to_fill[BLOCK_SIZE][BLOCK_SIZE],
					t_img *img_to_fill);
//		file: texture_init/texture_init_1.c
int				color_take(t_img *map, float i, float j);
unsigned int	my_mlx_pix_take(t_img *map, int x, int y);
//		file: texture_init/texture_init_won.c
void			texture_won(t_mlx *all, char *str,
					int array_to_fill[BLOCK_SIZE_X4][BLOCK_SIZE]);
void			fill_img_array_won(int array_to_fill[BLOCK_SIZE_X4][BLOCK_SIZE],
					t_img *img_to_fill);

// start run
//		file: graphics/graphics_0_keys.c
void			graphics(t_mlx *all);

// find start player position
//		file: graphics/graphics_0_keys.c
void			find_x_y_player(t_mlx *all, float x, float y);

// catch key
//		file: graphics/graphics_0_keys.c
int				key_press(int keycode, t_mlx *all);
int				key_release(int keycode, t_mlx *all);

// drow image and move
//	render. start
//		file: graphics/graphics_1_render.c
int				render_next_frame(t_mlx *all);
//	move
//		file: graphics/graphics_2_move.c
void			move_correct(t_mlx *all);
void			move_adws(t_mlx *all, int add_x, int add_y);
void			move_adws_death(t_mlx *all);
void			move_adws_collect(t_mlx *all);
void			move_adws_exit(t_mlx *all);
//	drow
//		file: graphics/graphics_1_render.c
void			drow_map(t_mlx *all);
void			drow_map_01ces(t_mlx *all);
void			drow_one_block(t_mlx *all, int x, int y,
					int array_to_fill[BLOCK_SIZE][BLOCK_SIZE]);
void			ft_mlx_one_bloke(t_mlx *all, int x, int y, char c);
//		file: graphics/graphics_3_counters_and_win_msg.c 
void			my_mlx_pix_put(t_img *map, int x, int y, int color);
void			counters_print_img(t_mlx *all);
void			win_img(t_mlx *all);

// sprites_go move
//		file: ./sprites_go/sprites_go_move.c
void			move_correct_sprites_go(t_mlx *all);
//		file: ./sprites_go/sprites_go_drow.c
void			sprites_go_drow(t_mlx *all);

// GAME_OVER
//		file: ./sprites_go/sprites_go_move.c
void			check_game_over(t_mlx *all, int n);
void			game_over(t_mlx *all);

#endif

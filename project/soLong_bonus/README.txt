SoLong.

This project is a small 2D game. It is built to make me work with
textures, sprites. And some very basic gameplay elements.

To start this version run "make bonus" in terminal from "project" directory.
After that, start the game with the map as the second argument:
./so_long  ./soLong_bonus/maps/2.ber 

Finished cards are in the folder: ./soLong_bonus/maps.

The header SoLong.h shows the structure of this project.

For each function in the project, a description is made in the 
appropriate files (see SoLong.h).

file: main.c                        0. main
file: valid/valid_0.c                   1. check_extention_argv
file: ../gnl/get_next_line_utils.c          gnl.  ft_strlen 
file: init_all_construct.c              2. construct_t_mlx
file: init_all_construct.c                  2.1.  construct_t_mlx_win
file: main.c                                    5.  error_occurse
file: lib_functions/lib_functions_1.c       2.2.  ft_memset
file: main.c                                    5.  error_occurse
file: ../gnl/get_next_line_utils.c          gnl.  ft_strlen 
file: valid/valid_0.c                   3. parser_valid_argv1
file: valid/valid_0.c                       3.1. map_check_and_fill
file: valid/valid_0.c                           3.1.1. valid_empty_map
file: main.c                                        5.    error_occurse
file: valid/valid_0.c                           3.1.2. valid_fill_map
file: valid/valid_1.c                               3.1.2.1. valid_one_char
file: main.c                                            5.    error_occurse
file: ../gnl/get_next_line_utils.c                      gnl.  ft_strlen
file: main.c                                        5.    error_occurse
file: ../gnl/get_next_line_utils.c                  gnl.  ft_strlen
file: valid/valid_1.c                           3.1.3. map_add_list
file: lib_functions/lib_functions_0.c               3.1.3.1. ft_map_list_new
file: lib_functions/lib_functions_1.c                   3.1.3.1.1. ft_strdup
file: main.c                                            5.    error_occurse
file: lib_functions/lib_functions_0.c               3.1.3.2. ft_map_list_add_back
file: lib_functions/lib_functions_0.c                   3.1.3.2.1. ft_map_list_last
file: ../gnl/get_next_line.c                    gnl. get_next_line
file: ../gnl/get_next_line_utils.c              gnl. ft_strlen
file: valid/valid_1.c                       3.2. map_array_fill
file: lib_functions/lib_functions_1.c           3.1.3.1.1. ft_strdup
file: main.c                                    5. error_occurse
file: valid/valid_1.c                       3.3. checks_character_sets
file: valid/valid_1.c                           3.3.1. checks_character_sets_find_matches
file: lib_functions/lib_functions_1.c               3.3.1.1. ft_strchr_int
file: main.c                                    5.     error_occurse
file: main.c                                5.   error_occurse
file: texture_init/texture_init_0.c     4. paste_texture
file: texture_init/texture_init_0.c         4.1. texture
file: texture_init/texture_init_0.c             4.1.1. texture_check_extention
file: ../gnl/get_next_line_utils.c                  gnl. ft_strlen
file: texture_init/texture_init_0.c             4.1.2. texture_img_init
file: main.c                                        5.   error_occurse
file: texture_init/texture_init_0.c             4.1.3. fill_img_array
file: texture_init/texture_init_0.c                 4.1.3.1. color_take
file: texture_init/texture_init_1.c                     4.1.3.1.1. my_mlx_pix_take
file: main.c                                    5.     error_occurse
file: texture_init/texture_init_won.c       4.2. texture_won
file: texture_init/texture_init_0.c             4.2.1. fill_img_array_won
file: texture_init/texture_init_1.c                 4.1.3.1.1. my_mlx_pix_take
file: texture_init/texture_init_0.c             4.1.1. texture_check_extention
file: ../gnl/get_next_line_utils.c                  gnl. ft_strlen
file: texture_init/texture_init_0.c             4.1.2. texture_img_init
file: main.c                                        5.   error_occurse
file: main.c                                    5.     error_occurse
file: main.c                            5. error_occurse
file: init_all_construct.c                  5.1. ft_exit_1
file: ../gnl/get_next_line_utils.c          gnl. ft_strlen
file: graphics/graphics_0_keys.c        6. graphics
file: graphics/graphics_0_keys.c            6.1. find_x_y_player
file: graphics/graphics_0_keys.c            6.2. key_press
file: graphics/graphics_0_keys.c                6.4. ft_exit_0
file: graphics/graphics_0_keys.c            6.3. key_release
file: graphics/graphics_0_keys.c            6.4. ft_exit_0
file: graphics/graphics_1_render.c          6.5. render_next_frame
file: graphics/graphics_2_move.c                 6.5.1. move_correct
file: graphics/graphics_2_move.c                     6.5.1.1. move_adws
file: graphics/graphics_2_move.c                         6.5.1.1.1. move_adws_collect
file: graphics/graphics_2_move.c                        6.5.1.1.2. move_adws_exit
file: graphics/graphics_0_keys.c                            6.4. ft_exit_0
file: graphics/graphics_2_move.c                        6.5.1.1.3. move_adws_death
file: sprites_go/sprites_go_move.c                              6.5.1.1.3.1. game_over
file: graphics/graphics_2_move.c                                6.4. ft_exit_0
file: graphics/graphics_2_move.c                                gnl. ft_strlen
file: graphics/graphics_1_render.c              6.5.2. drow_map
file: graphics/graphics_1_render.c                  6.5.2.1. ft_mlx_one_bloke
file: graphics/graphics_1_render.c                      6.5.2.1.1. drow_one_block
file: graphics/graphics_3_counters_and_win_msg.c            6.5.2.1.1.1. my_mlx_pix_put
file: graphics/graphics_1_render.c                  6.5.2.2. drow_map_01ces
file: graphics/graphics_1_render.c                      6.5.2.1. ft_mlx_one_bloke
file: lib_functions/lib_functions_1.c                   3.3.1.1. ft_strchr_int
file: ../gnl/get_next_line_utils.c                      gnl. ft_strlen
file: sprites_go/sprites_go_drow.c                  6.5.2.3. sprites_go_drow
file: graphics/graphics_1_render.c                      6.5.2.1. ft_mlx_one_bloke
file: graphics/graphics_3_counters_and_win_msg.c    6.5.2.4. counters_print_img;
file: lib_functions/lib_functions_1.c                   6.5.2.4.1. ft_itoa;
file: ../gnl/get_next_line_utils.c                      gnl. ft_strlen;
file: graphics/graphics_3_counters_and_win_msg.c    6.5.2.5. win_img;
file: graphics/graphics_3_counters_and_win_msg.c        6.5.2.1.1.1. my_mlx_pix_put
file: sprites_go/sprites_go_move.c              6.5.3. move_correct_sprites_go
file: sprites_go/sprites_go_move.c                  6.5.1.1.3.1. game_over
file: main.c                                    5. error_occurse
file: init_all_construct.c              7. destruct_t_mlx
file: lib_functions/lib_functions_0.c       7.1. ft_map_list_clear
file: lib_functions/lib_functions_0.c           7.1.1. ft_map_list_delone
file: sprites_go/paste_sprites_go.c     8. paste_sprites_go
file: sprites_go/paste_sprites_go.c             8.1. sprite_counting
file: sprites_go/paste_sprites_go.c             8.2. fill_sprites_go
file: main.c                                    5. error_occurse
file: main.c                            9. bonus_volume

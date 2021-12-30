NAME 		= so_long

CC			=	gcc
FLAGS 		= 	-Wall -Wextra -Werror

SRC 		= 						  	\
				main.c 				  	\
				init_all_construct.c 	\
				valid_0.c valid_1.c	 	\
				graphics/graphics_0_keys.c graphics/graphics_1_render.c \
				texture_init/texture_init.c 

SRC_LIB 	=	./lib_functions/lib_functions_0.c ./lib_functions/lib_functions_1.c
SRC_GNL 	=	./gnl/get_next_line.c ./gnl/get_next_line_utils.c

ifdef MAKE_BONUS
FOLDER = ./soLong_bonus/
SRC1 = $(addprefix $(FOLDER), $(SRC))
SRC1 += $(addprefix $(FOLDER), sprites_go/sprites_go.c sprites_go/sprites_go_move.c sprites_go/sprites_go_drow.c)
HEAD = ./soLong_bonus/soLong.h
else
FOLDER 		= ./soLong/
SRC1 		= $(addprefix $(FOLDER), $(SRC))
HEAD 		= ./soLong/soLong.h
endif

SRC1 		+= $(SRC_LIB)
SRC1 		+= $(SRC_GNL)

OBJ = $(SRC1:.c=.o)

OS 			= 	$(shell uname -s)
ifeq ($(OS),Darwin)
$(info Darwin)
CinO		=	$(CC) $(FLAGS) -Imlx -c $< -o $@ -I$(FOLDER)
SOLONG		=	$(CC) $(MLX) $(OBJ) -o $(NAME) $(MLX)
MLX 		= 	-Lmlx -lmlx -framework OpenGL -framework AppKit
MINILIBX 	= 	make -C mlx
endif

ifeq ($(OS),Linux)
$(info Linux)
CinO		=	$(CC) $(FLAGS) -g -I$(FOLDER) -I./mlx_linux2 -c $(@:.o=.c) -o $@ -L./mlx_linux2 $(MLX)
SOLONG		=	$(CC) -g -I$(FOLDER) -I./mlx_linux2 -o $(NAME) $(OBJ) -L./mlx_linux2 $(MLX)
MLX 		= 	-lm -lmlx -lXext -lX11
MINILIBX 	= 	make -C mlx_linux2
endif

%.o: %.c $(HEAD)
		$(CinO)

all: $(NAME)

bonus: ; $(MAKE) MAKE_BONUS=0 all


$(NAME): $(OBJ)
		$(MINILIBX)
		$(SOLONG)

clean: ; rm -rf $(OBJ) ; make clean -C mlx
cleanbonus: ; $(MAKE) MAKE_BONUS=0 clean

fclean:	clean ; rm -rf $(NAME)
fcleanbonus: ; $(MAKE) MAKE_BONUS=0 clean ; rm -rf $(NAME)

re: fclean all
rebonus: ; $(MAKE) MAKE_BONUS=0 fclean all

.PHONY: all clean fclean re bonus cleanbonus fcleanbonus rebonus

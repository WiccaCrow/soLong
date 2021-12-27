NAME 		= so_long

CC			=	gcc
FLAGS 		= 	-Wall -Wextra -Werror

SRC 		= 						  	\
				main.c 				  	\
				init_all_construct.c 	\
				valid.c				 	\

SRC_LIB 	=	./lib_functions/lib_functions.c
SRC_GNL 	=	./gnl/get_next_line.c ./gnl/get_next_line_utils.c

# ifdef MAKE_BONUS
# FOLDER = ./soLong_bonus/
# SRC1 = $(addprefix $(FOLDER), $(SRC))
# SRC1 += $(addprefix $(FOLDER), graphic/bonus_correct_move.c graphic/bonus_itoa.c graphic/bonus_drow_map.c main_3_start_all.c)
# HEAD = ./soLong_bonus/soLong.h
# else
FOLDER 		= ./soLong/
SRC1 		= $(addprefix $(FOLDER), $(SRC))
HEAD 		= ./soLong/
# endif

SRC1 		+= $(SRC_LIB)
SRC1 		+= $(SRC_GNL)

OBJ = $(SRC1:.c=.o)

ifdef (__APPLE__)
CinO		=	$(CC) $(FLAGS) -Imlx -c $< -o $@ -I$(FOLDER) $@ -c $<
SOLONG		=	$(CC) $(MLX) -o $(NAME) $(OBJ)
MLX 		= 	-Lmlx -lmlx -framework OpenGL -framework AppKit
MINILIBX 	= 	make -C mlx
else
CinO		=	$(CC) $(FLAGS) -g -I$(FOLDER) -I./mlx_linux -c $(@:.o=.c) -o $@ -L./mlx_linux $(MLX)
SOLONG		=	$(CC) -g -I$(FOLDER) -I./mlx_linux -o $(NAME) $(OBJ) -L./mlx_linux $(MLX)
MLX 		= 	-lm -lmlx -lXext -lX11
MINILIBX 	= 	make -C mlx_linux
endif

%.o: %.c $(HEAD)
		$(CinO)

all: $(NAME)

# bonus: ; $(MAKE) MAKE_BONUS=0 all

# $(OBJ): %.o: %.c $(HEAD)
# 	$(CC) $(FLAGS) -I$(FOLDER) -c $< -o $@


$(NAME): $(OBJ) 
		$(MINILIBX)
		$(SOLONG)

clean: ; rm -rf $(OBJ) ; make clean -C mlx
# cleanbonus: ; $(MAKE) MAKE_BONUS=0 clean

fclean:	clean ; rm -rf $(NAME)
# fcleanbonus: ; $(MAKE) MAKE_BONUS=0 clean ; rm -rf $(NAME)

re: fclean all
# rebonus: ; $(MAKE) MAKE_BONUS=0 fclean all

# .PHONY: all clean fclean re bonus cleanbonus fcleanbonus rebonus

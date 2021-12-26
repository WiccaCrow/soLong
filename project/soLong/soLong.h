#ifndef SOLONG_H
# define SOLONG_H

# include "../mlx/mlx.h"

typedef struct s_mlx {
	void			*mlx;
	void			*win;
	char			*argv1;

}	t_mlx;

void    init_t_mlx(t_mlx *all);


#endif
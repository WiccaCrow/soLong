#include "../soLong.h"

void	counters_print_img(t_mlx *all)
{
	char	*s_nb;

	s_nb = NULL;
    mlx_string_put(all->mlx, all->win, 10, 16, 0x00FF2566, COUNTERS_STEP);
    s_nb = ft_itoa(all->steps);
    mlx_string_put(all->mlx, all->win, ft_strlen(COUNTERS_STEP) * 6 + 16, 16, 0x00FF0066, s_nb);
    free(s_nb);

    mlx_string_put(all->mlx, all->win, 10, 32, 0x00FF2566, COUNTERS_COLLECT);
    s_nb = ft_itoa(all->collect);
    mlx_string_put(all->mlx, all->win, ft_strlen(COUNTERS_COLLECT) * 6 + 16, 32, 0x00FF0066, s_nb);
    free(s_nb);
}
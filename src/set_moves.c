
#include "../Include/cub3D.h"

static void	close_window(t_cub *game)
{
	mlx_close_window(game->mlx);
}

/* Set the moves and the actions */

void	set_moves(mlx_key_data_t key, void *param)
{
	if (key.key == MLX_KEY_ESCAPE && key.action == MLX_PRESS)
		close_window((t_cub *)param);
}

#include "../Include/cub3D.h"

static void	close_window(t_cub *game)
{
	mlx_close_window(game->mlx);
	free_game(game);
}

static void	make_move(t_cub *g, mlx_key_data_t key)
{
	if (key.key == MLX_KEY_A)
		key_a(g);
	if (key.key == MLX_KEY_D)
		key_d(g);
	if (key.key == MLX_KEY_W)
		key_w(g);
	if (key.key == MLX_KEY_S)
		key_s(g);
	if (key.key == MLX_KEY_LEFT || key.key == MLX_KEY_RIGHT)
		key_left_right(g, key);
	put_textures(g);
	ray_casting(g, g->ray);
}

void	set_moves(mlx_key_data_t key, void *param)
{
	if (key.key == MLX_KEY_ESCAPE && key.action == MLX_PRESS)
		close_window((t_cub *)param);
	if ((key.key == MLX_KEY_A || key.key == MLX_KEY_D
			|| key.key == MLX_KEY_W || key.key == MLX_KEY_S
			|| key.key == MLX_KEY_LEFT || key.key == MLX_KEY_RIGHT)
		&& (key.action == MLX_REPEAT || key.action == MLX_PRESS))
		make_move((t_cub *)param, key);
}

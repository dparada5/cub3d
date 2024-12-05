
#include "../Include/cub3D.h"
/* 
	Init the game, set the moves and put the 
	textures in the window.
 */

void	init_mlx_game(t_cub *game)
{
	t_ray	ray[W_WIDTH];

	game->ray = ray;
	game->window_img = mlx_new_image(game->mlx, W_WIDTH, W_HEIGHT);
	put_textures(game);
	mlx_key_hook(game->mlx, &set_moves, game);
	ray_casting(game, ray);
	mlx_loop(game->mlx);
}
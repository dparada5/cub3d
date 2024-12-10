
#include "../Include/cub3D.h"
/* 
	Init the game, set the moves and put the 
	textures in the window.
 */

void	init_mlx_game(t_cub *game)
{
	t_ray	ray[W_WIDTH];

	put_textures(game);
	mlx_key_hook(game->mlx, &set_moves, game);
	ray_casting(game, ray);
	mlx_loop(game->mlx);
}
#include "../Include/cub3D.h"

static void	mouse_cam(void *param)
{
	int		x;
	int		y;
	t_cub	*g;

	g = (t_cub *)param;
	mlx_get_mouse_pos(g->mlx, &x, &y);
	if (y < W_HEIGHT && y > 0)
	{
		if (x < W_WIDTH_2 && x < W_WIDTH_2 - W_WIDTH_4 && x > 0)
		{
			g->player->r_view -= ANG_MOVE;
			put_textures(g);
			ray_casting(g, g->ray);
		}
		if (x > W_WIDTH_2 && x > W_WIDTH_2 + W_WIDTH_4 && x < W_WIDTH)
		{
			g->player->r_view += ANG_MOVE;
			put_textures(g);
			ray_casting(g, g->ray);
		}
	}
}

void	init_mlx_game(t_cub *game)
{
	t_ray	ray[W_WIDTH];

	game->ray = ray;
	game->window_img = mlx_new_image(game->mlx, W_WIDTH, W_HEIGHT);
	put_textures(game);
	mlx_image_to_window(game->mlx, game->window_img, 0, 0);
	mlx_key_hook(game->mlx, &set_moves, game);
	mlx_loop_hook(game->mlx, &mouse_cam, game);
	ray_casting(game, ray);
	mlx_loop(game->mlx);
}

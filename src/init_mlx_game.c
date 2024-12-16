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
		if (x < (W_WIDTH / 2) && x < (W_WIDTH / 2) - (W_WIDTH / 4) && x > 0)
		{
			g->player->r_view -= ANG_MOVE;
			put_textures(g);
			ray_casting(g, g->ray);
		}
		if (x > (W_WIDTH / 2) && x > (W_WIDTH / 2) + (W_WIDTH / 4) && x < W_WIDTH)
		{
			g->player->r_view += ANG_MOVE;
			put_textures(g);
			ray_casting(g, g->ray);
		}
	}
}

static void	init_minimap(t_cub *g)
{
	g->mini_map->start_x = W_WIDTH / 65;
	g->mini_map->start_y = W_HEIGHT - (W_HEIGHT / 4);
	g->mini_map->width = W_WIDTH / 4;
	g->mini_map->height = W_HEIGHT / 4;
	g->mini_map->end_x = g->mini_map->start_x + g->mini_map->width;
	g->mini_map->end_y = g->mini_map->start_y + g->mini_map->height - W_WIDTH / 65;
	g->mini_map->pixel_size = g->mini_map->width / 20;
}

void	init_mlx_game(t_cub *game)
{
	t_ray	ray[W_WIDTH];

	init_minimap(game);
	init_animations(game);
	game->ray = ray;
	game->window_img = mlx_new_image(game->mlx, W_WIDTH, W_HEIGHT);
	put_textures(game);
	mlx_image_to_window(game->mlx, game->window_img, 0, 0);
	mlx_key_hook(game->mlx, &set_moves, game);
	mlx_loop_hook(game->mlx, &mouse_cam, game);
	ray_casting(game, ray);
	mlx_loop_hook(game->mlx, &update_animation, game);
	//mlx_loop_hook(game->mlx, &mini_map, game);
	mlx_loop(game->mlx);
}

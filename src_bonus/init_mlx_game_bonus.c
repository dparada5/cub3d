/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_game_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:40:08 by dparada           #+#    #+#             */
/*   Updated: 2024/12/26 18:50:07 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cub3D_bonus.h"

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
		if (x > (W_WIDTH / 2) && x > (W_WIDTH / 2)
			+ (W_WIDTH / 4) && x < W_WIDTH)
		{
			g->player->r_view += ANG_MOVE;
			put_textures(g);
			ray_casting(g, g->ray);
		}
	}
}

void	ft_init_game(t_cub *game)
{
	game->mlx = NULL;
	game->coor = malloc_coor(game);
	game->player = malloc(sizeof(t_player));
	if (!game->player)
		ft_msj_error(game, 1, "Malloc failed.");
	game->map = NULL;
	game->map_len = 0;
	game->start_map = 0;
	game->n_player = 0;
	game->fd = -1;
	game->open = 0;
	game->anim = NULL;
}

void	init_mlx_game(t_cub *game)
{
	t_ray	ray[W_WIDTH];

	game->mlx = mlx_init(W_WIDTH, W_HEIGHT, "cub3D", false);
	if (!game->mlx)
		ft_msj_error(game, 1, NULL);
	init_animations(game);
	game->ray = ray;
	game->window_img = mlx_new_image(game->mlx, W_WIDTH, W_HEIGHT);
	put_textures(game);
	mlx_image_to_window(game->mlx, game->window_img, 0, 0);
	mlx_key_hook(game->mlx, &set_moves, game);
	mlx_set_cursor_mode(game->mlx, MLX_MOUSE_HIDDEN);
	mlx_set_mouse_pos(game->mlx, W_WIDTH / 2, W_HEIGHT / 2);
	mlx_loop_hook(game->mlx, &mouse_cam, game);
	ray_casting(game, ray);
	mlx_loop_hook(game->mlx, &update_animation, game);
	mlx_loop(game->mlx);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_game_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:40:08 by dparada           #+#    #+#             */
/*   Updated: 2024/12/26 19:16:45 by tanselmo         ###   ########.fr       */
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

static void	paint(mlx_image_t *img, int color, int x, int y)
{
	int	len_y;
	int	len_x;

	len_y = y + W_HEIGHT / 50;
	len_x = x + W_WIDTH / 50;
	while (y <= len_y)
	{
		x = len_x - W_WIDTH / 50;
		while (x <= len_x)
			mlx_put_pixel(img, x++, y, color);
		y++;
	}
}

static void	paint_minimap(void *param)
{
	t_cub	*g;
	int		y;
	int		x;

	g = (t_cub *)param;
	y = -1;
	while (g->map[++y])
	{
		x = -1;
		while (g->map[y][++x])
		{
			if (g->map[y][x] == '1')
				paint(g->window_img, get_rgba(0, 0, 0, 255), x * W_HEIGHT / 50, y * W_HEIGHT / 50);
			else if (g->map[y][x] == '0')
				paint(g->window_img, get_rgba(255, 255, 255, 255), x * W_HEIGHT / 50, y * W_HEIGHT / 50);
			else if (g->map[y][x] == 'D')
				paint(g->window_img, get_rgba(255, 255, 0, 255), x * W_HEIGHT / 50, y * W_HEIGHT / 50);
			else if (g->map[y][x] == 'N' || g->map[y][x] == 'S' || g->map[y][x] == 'W' || g->map[y][x] == 'E')
				paint(g->window_img, get_rgba(255, 0, 0, 255), x * W_HEIGHT / 50, y * W_HEIGHT / 50);
		}
	}
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
	//paint_minimap(game);
	mlx_loop_hook(game->mlx, &paint_minimap, game);
	mlx_loop(game->mlx);
}

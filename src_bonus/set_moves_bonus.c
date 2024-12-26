/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_moves_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:41:18 by dparada           #+#    #+#             */
/*   Updated: 2024/12/26 18:35:33 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cub3D_bonus.h"

static void	close_window(t_cub *game)
{
	mlx_close_window(game->mlx);
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
	if (key.key == MLX_KEY_O && key.action == MLX_PRESS)
		open_door((t_cub *)param);
}

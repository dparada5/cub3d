/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:40:15 by dparada           #+#    #+#             */
/*   Updated: 2024/12/20 15:40:17 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cub3D.h"

void	key_w(t_cub *g)
{
	double	new_y;
	double	new_x;

	new_y = g->player->y + P_MOVE * sin(g->player->r_view);
	new_x = g->player->x + P_MOVE * cos(g->player->r_view);
	if (g->map[(int)new_y][(int)new_x] != '1'
		&& g->map[(int)new_y][(int)new_x] != 'D')
	{
		if ((g->map[(int)new_y][(int)g->player->x] != '1'
			&& g->map[(int)new_y][(int)g->player->x] != 'D')
				&& (g->map[(int)g->player->y][(int)new_x] != '1'
					&& g->map[(int)g->player->y][(int)new_x] != 'D'))
		{
			g->player->y = new_y;
			g->player->x = new_x;
		}
	}
}

void	key_s(t_cub *g)
{
	double	new_y;
	double	new_x;

	new_y = g->player->y - P_MOVE * sin(g->player->r_view);
	new_x = g->player->x - P_MOVE * cos(g->player->r_view);
	if (g->map[(int)new_y][(int)new_x] != '1'
		&& g->map[(int)new_y][(int)new_x] != 'D')
	{
		if ((g->map[(int)new_y][(int)g->player->x] != '1'
			&& g->map[(int)new_y][(int)g->player->x] != 'D')
				&& (g->map[(int)g->player->y][(int)new_x] != '1'
					&& g->map[(int)g->player->y][(int)new_x] != 'D'))
		{
			g->player->y = new_y;
			g->player->x = new_x;
		}
	}
}

void	key_a(t_cub *g)
{
	double	new_y;
	double	new_x;

	new_y = g->player->y - P_MOVE * cos(g->player->r_view);
	new_x = g->player->x + P_MOVE * sin(g->player->r_view);
	if (g->map[(int)new_y][(int)new_x] != '1'
		&& g->map[(int)new_y][(int)new_x] != 'D')
	{
		if ((g->map[(int)new_y][(int)g->player->x] != '1'
			&& g->map[(int)new_y][(int)g->player->x] != 'D')
				&& (g->map[(int)g->player->y][(int)new_x] != '1'
					&& g->map[(int)g->player->y][(int)new_x] != 'D'))
		{
			g->player->y = new_y;
			g->player->x = new_x;
		}
	}
}

void	key_d(t_cub *g)
{
	double	new_y;
	double	new_x;

	new_y = g->player->y + P_MOVE * cos(g->player->r_view);
	new_x = g->player->x - P_MOVE * sin(g->player->r_view);
	if (g->map[(int)new_y][(int)new_x] != '1'
		&& g->map[(int)new_y][(int)new_x] != 'D')
	{
		if ((g->map[(int)new_y][(int)g->player->x] != '1'
			&& g->map[(int)new_y][(int)g->player->x] != 'D')
				&& (g->map[(int)g->player->y][(int)new_x] != '1'
					&& g->map[(int)g->player->y][(int)new_x] != 'D'))
		{
			g->player->y = new_y;
			g->player->x = new_x;
		}
	}
}

void	key_left_right(t_cub *g, mlx_key_data_t key)
{
	if (key.key == MLX_KEY_LEFT)
		g->player->r_view -= ANG_MOVE * 2;
	if (key.key == MLX_KEY_RIGHT)
		g->player->r_view += ANG_MOVE * 2;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:37:26 by dparada           #+#    #+#             */
/*   Updated: 2024/12/20 15:37:28 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cub3D.h"

void	key_w(t_cub *g)
{
	double	new_y;
	double	new_x;

	new_y = g->player->y + (P_MOVE * 2) * sin(g->player->r_view);
	new_x = g->player->x + (P_MOVE * 2) * cos(g->player->r_view);
	if (g->map[(int)new_y][(int)new_x] != '1')
	{
		if (g->map[(int)new_y][(int)g->player->x] != '1'
			&& g->map[(int)g->player->y][(int)new_x] != '1')
		{
			g->player->y = g->player->y + P_MOVE * sin(g->player->r_view);
			g->player->x = g->player->x + P_MOVE * cos(g->player->r_view);
		}
	}
}

void	key_s(t_cub *g)
{
	double	new_y;
	double	new_x;

	new_y = g->player->y - (P_MOVE * 2) * sin(g->player->r_view);
	new_x = g->player->x - (P_MOVE * 2) * cos(g->player->r_view);
	if (g->map[(int)new_y][(int)new_x] != '1')
	{
		if (g->map[(int)new_y][(int)g->player->x] != '1'
			&& g->map[(int)g->player->y][(int)new_x] != '1')
		{
			g->player->y = g->player->y - P_MOVE * sin(g->player->r_view);
			g->player->x = g->player->x - P_MOVE * cos(g->player->r_view);
		}
	}
}

void	key_a(t_cub *g)
{
	double	new_y;
	double	new_x;

	new_y = g->player->y - (P_MOVE * 2) * cos(g->player->r_view);
	new_x = g->player->x + (P_MOVE * 2) * sin(g->player->r_view);
	if (g->map[(int)new_y][(int)new_x] != '1')
	{
		if (g->map[(int)new_y][(int)g->player->x] != '1'
			&& g->map[(int)g->player->y][(int)new_x] != '1')
		{
			g->player->y = g->player->y - P_MOVE * cos(g->player->r_view);
			g->player->x = g->player->x + P_MOVE * sin(g->player->r_view);
		}
	}
}

void	key_d(t_cub *g)
{
	double	new_y;
	double	new_x;

	new_y = g->player->y + (P_MOVE * 2) * cos(g->player->r_view);
	new_x = g->player->x - (P_MOVE * 2) * sin(g->player->r_view);
	if (g->map[(int)new_y][(int)new_x] != '1')
	{
		if (g->map[(int)new_y][(int)g->player->x] != '1'
			&& g->map[(int)g->player->y][(int)new_x] != '1')
		{
			g->player->y = g->player->y + P_MOVE * cos(g->player->r_view);
			g->player->x = g->player->x - P_MOVE * sin(g->player->r_view);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:40:15 by dparada           #+#    #+#             */
/*   Updated: 2024/12/26 18:38:40 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cub3D_bonus.h"

void	key_w(t_cub *g)
{
	double	new_y;
	double	new_x;

	new_y = g->player->y + (P_MOVE * 2) * sin(g->player->r_view);
	new_x = g->player->x + (P_MOVE * 2) * cos(g->player->r_view);
	if (g->map[(int)new_y][(int)new_x] != '1'
		&& g->map[(int)new_y][(int)new_x] != 'D')
	{
		if ((g->map[(int)new_y][(int)g->player->x] != '1'
			&& g->map[(int)new_y][(int)g->player->x] != 'D')
				&& (g->map[(int)g->player->y][(int)new_x] != '1'
					&& g->map[(int)g->player->y][(int)new_x] != 'D'))
		{
			g->player->y = g->player->y + P_MOVE * sin(g->player->r_view);
			g->player->x = g->player->x + P_MOVE * cos(g->player->r_view);
			put_textures(g);
			ray_casting(g, g->ray);
		}
	}
}

void	key_s(t_cub *g)
{
	double	new_y;
	double	new_x;

	new_y = g->player->y - (P_MOVE * 2) * sin(g->player->r_view);
	new_x = g->player->x - (P_MOVE * 2) * cos(g->player->r_view);
	if (g->map[(int)new_y][(int)new_x] != '1'
		&& g->map[(int)new_y][(int)new_x] != 'D')
	{
		if ((g->map[(int)new_y][(int)g->player->x] != '1'
			&& g->map[(int)new_y][(int)g->player->x] != 'D')
				&& (g->map[(int)g->player->y][(int)new_x] != '1'
					&& g->map[(int)g->player->y][(int)new_x] != 'D'))
		{
			g->player->y = g->player->y - P_MOVE * sin(g->player->r_view);
			g->player->x = g->player->x - P_MOVE * cos(g->player->r_view);
			put_textures(g);
			ray_casting(g, g->ray);
		}
	}
}

void	key_a(t_cub *g)
{
	double	new_y;
	double	new_x;

	new_y = g->player->y - (P_MOVE * 2) * cos(g->player->r_view);
	new_x = g->player->x + (P_MOVE * 2) * sin(g->player->r_view);
	if (g->map[(int)new_y][(int)new_x] != '1'
		&& g->map[(int)new_y][(int)new_x] != 'D')
	{
		if ((g->map[(int)new_y][(int)g->player->x] != '1'
			&& g->map[(int)new_y][(int)g->player->x] != 'D')
				&& (g->map[(int)g->player->y][(int)new_x] != '1'
					&& g->map[(int)g->player->y][(int)new_x] != 'D'))
		{
			g->player->y = g->player->y - P_MOVE * cos(g->player->r_view);
			g->player->x = g->player->x + P_MOVE * sin(g->player->r_view);
			put_textures(g);
			ray_casting(g, g->ray);
		}
	}
}

void	key_d(t_cub *g)
{
	double	new_y;
	double	new_x;

	new_y = g->player->y + (P_MOVE * 2) * cos(g->player->r_view);
	new_x = g->player->x - (P_MOVE * 2) * sin(g->player->r_view);
	if (g->map[(int)new_y][(int)new_x] != '1'
		&& g->map[(int)new_y][(int)new_x] != 'D')
	{
		if ((g->map[(int)new_y][(int)g->player->x] != '1'
			&& g->map[(int)new_y][(int)g->player->x] != 'D')
				&& (g->map[(int)g->player->y][(int)new_x] != '1'
					&& g->map[(int)g->player->y][(int)new_x] != 'D'))
		{
			g->player->y = g->player->y + P_MOVE * cos(g->player->r_view);
			g->player->x = g->player->x - P_MOVE * sin(g->player->r_view);
			put_textures(g);
			ray_casting(g, g->ray);
		}
	}
}

void	key_left_right(t_cub *g, mlx_key_data_t key)
{
	if (key.key == MLX_KEY_LEFT)
		g->player->r_view -= ANG_MOVE * 2;
	if (key.key == MLX_KEY_RIGHT)
		g->player->r_view += ANG_MOVE * 2;
	put_textures(g);
	ray_casting(g, g->ray);
}

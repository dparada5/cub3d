/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:39:08 by dparada           #+#    #+#             */
/*   Updated: 2024/12/27 12:12:52 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cub3D_bonus.h"

int	get_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

static void	open_frames(t_cub *g)
{
	g->anim->frames[0] = mlx_load_png("Animation/Torch_0.png");
	if (!g->anim->frames[0])
		ft_msj_error(g, 1, "Failed to load image.");
	g->anim->frames[1] = mlx_load_png("Animation/Torch_1.png");
	if (!g->anim->frames[1])
		ft_msj_error(g, 1, "Failed to load image.");
	g->anim->frames[2] = mlx_load_png("Animation/Torch_2.png");
	if (!g->anim->frames[2])
		ft_msj_error(g, 1, "Failed to load image.");
	g->anim->frames[3] = mlx_load_png("Animation/Torch_3.png");
	if (!g->anim->frames[3])
		ft_msj_error(g, 1, "Failed to load image.");
	g->anim->frames[4] = mlx_load_png("Animation/Torch_4.png");
	if (!g->anim->frames[4])
		ft_msj_error(g, 1, "Failed to load image.");
	g->anim->frames[5] = mlx_load_png("Animation/Torch_5.png");
	if (!g->anim->frames[5])
		ft_msj_error(g, 1, "Failed to load image.");
	g->anim->frames[6] = mlx_load_png("Animation/Torch_6.png");
	if (!g->anim->frames[6])
		ft_msj_error(g, 1, "Failed to load image.");
}

void	init_animations(t_cub *g)
{
	g->anim = malloc(sizeof(t_animation));
	if (!g->anim)
		ft_msj_error(g, 1, "Malloc failed.");
	open_frames(g);
	g->anim->img = mlx_texture_to_image(g->mlx, g->anim->frames[0]);
	if (!g->anim->img)
		ft_msj_error(g, 1, "Malloc failed.");
	mlx_image_to_window(g->mlx, g->anim->img,
		W_WIDTH * 0.5, W_HEIGHT - (ANIM_SIZE * 0.7));
	g->anim->current_frame = 0;
	g->anim->last_time = get_time();
}

void	update_animation(t_cub *g)
{
	int		current_time;

	current_time = get_time();
	if (current_time - g->anim->last_time >= DELAY)
	{
		g->anim->last_time = current_time;
		g->anim->current_frame = (g->anim->current_frame + 1) % ANIMATIONS;
		mlx_delete_image(g->mlx, g->anim->img);
		g->anim->img = mlx_texture_to_image(g->mlx,
				g->anim->frames[g->anim->current_frame]);
		if (!g->anim->img)
			ft_msj_error(g, 1, "Error: Animations failed.");
		mlx_image_to_window(g->mlx, g->anim->img,
			W_WIDTH * 0.5, W_HEIGHT - (ANIM_SIZE * 0.7));
	}
}

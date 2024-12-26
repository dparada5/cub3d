/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:39:21 by dparada           #+#    #+#             */
/*   Updated: 2024/12/26 16:21:36 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cub3D_bonus.h"

static void	ft_delete_textures(t_coor *coor)
{
	if (coor->north_i)
		mlx_delete_texture(coor->north_i);
	if (coor->south_i)
		mlx_delete_texture(coor->south_i);
	if (coor->west_i)
		mlx_delete_texture(coor->west_i);
	if (coor->east_i)
		mlx_delete_texture(coor->east_i);
	if (coor->door_i)
		mlx_delete_texture(coor->door_i);
}

static void	free_coor(t_coor *coor)
{
	if (coor->ceiling)
		free(coor->ceiling);
	if (coor->floor)
		free(coor->floor);
	if (coor->north)
		free(coor->north);
	if (coor->south)
		free(coor->south);
	if (coor->west)
		free(coor->west);
	if (coor->east)
		free(coor->east);
	if (coor->t_ceiling)
		free(coor->t_ceiling);
	if (coor->t_floor)
		free(coor->t_floor);
	if (coor->door)
		free(coor->door);
	ft_delete_textures(coor);
	if (coor)
		free(coor);
}

static void	free_anim(t_animation *anim)
{
	int	i;

	i = 0;
	while (i < ANIMATIONS)
	{
		if (anim->frames[i])
			mlx_delete_texture(anim->frames[i]);
		i++;
	}
	free(anim);
}

void	free_game(t_cub *game)
{
	if (game)
	{
		if (game->map)
			ft_free(game->map);
		if (game->coor)
			free_coor(game->coor);
		if (game->player)
			free(game->player);
		if (game->fd != -1)
			close(game->fd);
		if (game->anim)
			free_anim(game->anim);
		if (game->mlx)
			mlx_terminate(game->mlx);
		free(game);
	}
}

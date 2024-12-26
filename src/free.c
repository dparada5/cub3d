/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:36:14 by dparada           #+#    #+#             */
/*   Updated: 2024/12/26 16:12:39 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cub3D.h"

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
	ft_delete_textures(coor);
	if (coor)
		free(coor);
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
		if (game->mlx)
			mlx_terminate(game->mlx);
		free(game);
	}
}

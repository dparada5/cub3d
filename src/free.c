/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:49:09 by dparada           #+#    #+#             */
/*   Updated: 2024/12/06 17:16:12 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cub3D.h"

void	ft_delete_images(mlx_t *mlx, t_coor *coor)
{
	if (coor->north_i)
		mlx_delete_image(mlx, coor->north_i);
	if (coor->south_i)
		mlx_delete_image(mlx, coor->south_i);
	if (coor->west_i)
		mlx_delete_image(mlx, coor->west_i);
	if (coor->east_i)
		mlx_delete_image(mlx, coor->east_i);
}

// mlx_delete_image()
//should destroy mlx images?
void	free_coor(mlx_t *mlx, t_coor *coor)
{
	if (coor->cealing)
		free(coor->cealing);
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
			free_coor(game->mlx, game->coor);
		if (game->player)
			free(game->player);
		if (game->fd != -1)
			close(game->fd);
		mlx_terminate(game->mlx);
		free(game);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:49:09 by dparada           #+#    #+#             */
/*   Updated: 2024/11/20 11:41:17 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cub3D.h"

void	free_coor(t_coor *coor)
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
		if (game->fd != -1)
			close(game->fd);
		free(game);	
	}
}
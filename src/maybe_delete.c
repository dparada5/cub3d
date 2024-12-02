/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maybe_delete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:46:14 by dparada           #+#    #+#             */
/*   Updated: 2024/11/27 15:09:46 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cub3D.h"

void	change_spaces(t_cub *game)
{
	int	y;
	int	x;

	y = -1;
	if (game->error_flag)
		return ;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
			if (game->map[y][x] == ' ')
				game->map[y][x] = '1';
	}
}

void	printf_player(t_cub *game)
{
	printf("x = %d y = %d view = %c\n", game->player->x, game->player->y, game->player->view);
}
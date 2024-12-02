/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maybe_delete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:46:14 by dparada           #+#    #+#             */
/*   Updated: 2024/12/02 18:53:54 by tanselmo         ###   ########.fr       */
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
	printf("x = %f y = %f view = %c\n", game->player->x, game->player->y, game->player->view);
}
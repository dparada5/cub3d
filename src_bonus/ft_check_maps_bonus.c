/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_maps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:39:27 by dparada           #+#    #+#             */
/*   Updated: 2024/12/20 15:53:40 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cub3D.h"

static void	check_valid_walls(t_cub *game, int y, int x)
{
	if (ft_strchr("0NSWE", game->map[y][x]) && !game->map[y - 1])
		ft_msj_error(game, 1, "Map not closed properly.");
	else if (ft_strchr("0NSWE", game->map[y][x]) && !game->map[y + 1])
		ft_msj_error(game, 1, "Map not closed properly.");
	else if (ft_strchr("0NSWE", game->map[y][x]) && !game->map[y][x - 1])
		ft_msj_error(game, 1, "Map not closed properly.");
	else if (ft_strchr("0NSWE", game->map[y][x]) && !game->map[y][x + 1])
		ft_msj_error(game, 1, "Map not closed properly.");
	check_valid_door(game, game->map, x, y);
}

static void	check_char(t_cub *game, char current, char next)
{
	if (!ft_strchr("10NSWED ", current))
		ft_msj_error(game, 1, "Invalid character on map.");
	else if (current == '1' || current == ' ')
		return ;
	else if (current == 'D' && !game->coor->is_door)
		ft_msj_error(game, 1, "Invalid character on map.");
	else if ((current == '0' || current == 'D') && (!ft_strchr("10NSWED", next)
			|| !next))
		ft_msj_error(game, 1, "Map not closed properly.");
	else if (ft_strchr("NSWE", current) && (!ft_strchr("10D", next) || !next))
		ft_msj_error(game, 1, "Map not closed properly.");
}

static void	add_spaces(t_cub *game)
{
	size_t	max;
	int		y;

	y = -1;
	max = ft_strlen(game->map[0]);
	while (game->map[++y])
		if (ft_strlen(game->map[y]) > max)
			max = ft_strlen(game->map[y]);
	y = -1;
	while (game->map[++y])
		while (ft_strlen(game->map[y]) < max)
			game->map[y] = ft_strjoin(game->map[y], " ");
}

static void	count_players(t_cub *game)
{
	int	y;
	int	x;

	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (ft_strchr("NSWE", game->map[y][x]))
			{
				game->player->x = x + 0.5;
				game->player->y = y + 0.5;
				game->player->view = game->map[y][x];
				game->player->r_view = get_radian(game->map[y][x]);
				game->n_player++;
			}
		}
	}
	if (game->n_player != 1)
		ft_msj_error(game, 1, "Invalid number of players.");
}

void	ft_check_map(t_cub *game)
{
	int	x;
	int	y;

	y = -1;
	if (!game->map)
		return (ft_msj_error(game, 1, "There's no map."));
	add_spaces(game);
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			check_valid_walls(game, y, x);
			if (y > 0 && x > 0)
			{
				check_char(game, game->map[y][x], game->map[y][x - 1]);
				check_char(game, game->map[y][x], game->map[y][x + 1]);
				check_char(game, game->map[y][x], game->map[y - 1][x]);
				if (game->map[y] && game->map[y + 1])
					check_char(game, game->map[y][x], game->map[y + 1][x]);
			}
		}
	}
	change_spaces(game);
	count_players(game);
}

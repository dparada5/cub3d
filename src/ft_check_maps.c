/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_maps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:36:19 by dparada           #+#    #+#             */
/*   Updated: 2024/12/27 12:53:32 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cub3D.h"

static int	check_valid_walls(t_cub *game, int y, int x)
{
	if (game->map[y][x] && !ft_strchr("10NSWE ", game->map[y][x]))
		return (ft_msj_error(game, 1, "Invalid character on map."), 0);
	if (ft_strchr("0NSWE", game->map[y][x]) && (y == 0 || !game->map[y - 1]))
		return (ft_msj_error(game, 1, "Map not closed properly."), 0);
	else if (ft_strchr("0NSWE", game->map[y][x]) && !game->map[y + 1])
		return (ft_msj_error(game, 1, "Map not closed properly."), 0);
	else if (ft_strchr("0NSWE", game->map[y][x])
		&& (x == 0 || !game->map[y][x - 1]))
		return (ft_msj_error(game, 1, "Map not closed properly."), 0);
	else if (ft_strchr("0NSWE", game->map[y][x]) && !game->map[y][x + 1])
		return (ft_msj_error(game, 1, "Map not closed properly."), 0);
	return (1);
}

static int	check_char(t_cub *game, char current, char next)
{
	if (!ft_strchr("10NSWE ", current))
		return (ft_msj_error(game, 1, "Invalid character on map."), 0);
	else if (current == '1' || current == ' ')
		return (1);
	else if (current == '0' && (!ft_strchr("10NSWE", next) || !next))
		return (ft_msj_error(game, 1, "Map not closed properly."), 0);
	else if (ft_strchr("NSWE", current) && (!ft_strchr("10", next) || !next))
		return (ft_msj_error(game, 1, "Map not closed properly."), 0);
	return (1);
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

void	ft_check_map(t_cub *game, int y, int x)
{
	if (game->coor->n_coor != 6)
		ft_msj_error(game, 1, "There's no texture.");
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_maps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 11:08:46 by dparada           #+#    #+#             */
/*   Updated: 2024/11/20 11:41:13 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cub3D.h"
//sacar el punto extra que es para diferenciar el msj
static int	check_valid_walls(t_cub *game, int y, int x)
{
	if (ft_strchr("0NSWE", game->map[y][x]) && !game->map[y - 1])
		return (ft_msj_error(game, 1, "Map not closed properly.."), 0);
	else if (ft_strchr("0NSWE", game->map[y][x]) && !game->map[y + 1])
		return (ft_msj_error(game, 1, "Map not closed properly.."), 0);
	else if (ft_strchr("0NSWE", game->map[y][x]) && !game->map[y][x - 1])
		return (ft_msj_error(game, 1, "Map not closed properly.."), 0);
	else if (ft_strchr("0NSWE", game->map[y][x]) && !game->map[y][x + 1])
		return (ft_msj_error(game, 1, "Map not closed properly.."), 0);
	return (1);
}

static int	check_char(t_cub *game, char current, char c)
{
	if (game->error_flag)
		return (0);
	if (!c)
		return (1);
	else if (!ft_strchr("10NSWE ", current))
		return (ft_msj_error(game, 1, "Invalid char on map."), 0);
	else if (current == '1' || current == ' ')
		return (1);
	else if (current == '0' && !ft_strchr("10NSWE", c))
		return (ft_msj_error(game, 1, "Map not closed properly."), 0);
	else if (ft_strchr("NSWE", current) && !ft_strchr("10", c))
		return (ft_msj_error(game, 1, "Map not closed properly."), 0);
	return (1);
}

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
	// ft_replace_char(game->map[y], '1', ' ');
}

void	add_spaces(t_cub *game)
{
	size_t	max;
	int		y;
	// char	*aux;
	
	y = -1;
	max = ft_strlen(game->map[0]);
	while (game->map[++y])
		if (ft_strlen(game->map[y]) > max)
			max = ft_strlen(game->map[y]);
	y = -1;
	while (game->map[++y])
	{
		while (ft_strlen(game->map[y]) < max)
			game->map[y] = ft_strjoin(game->map[y], " ");
	}
}

static void	count_players(t_cub *game)
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
			if (ft_strchr("NSWE", game->map[y][x]))
				game->player++;
	}
	if (game->player != 1)
		ft_msj_error(game, 1, "Invalid number of players.");
}

void	ft_check_map(t_cub *game)
{
	int	x;
	int	y;

	y = -1;
	if (!game->map)
		return (ft_msj_error(game, 1, "There's no map."));
	while (game->map[++y] && !game->error_flag)
	{
		x = -1;
		while (game->map[y][++x] && !game->error_flag)
		{
			check_valid_walls(game, y, x);
			if (y > 0 && x > 0)
			{	
				check_char(game, game->map[y][x], game->map[y][x - 1]);
				check_char(game, game->map[y][x], game->map[y][x + 1]);
				check_char(game, game->map[y][x], game->map[y - 1][x]);
				if (game->map[y + 1])
					check_char(game, game->map[y][x], game->map[y + 1][x]);
			}
		}
	}
	add_spaces(game);
	// change_spaces(game);
	count_players(game);
	print_matrix(game->map);
}

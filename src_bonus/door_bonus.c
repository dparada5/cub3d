/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 10:05:49 by dparada           #+#    #+#             */
/*   Updated: 2024/12/27 13:10:28 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cub3D_bonus.h"

void	check_valid_door(t_cub *g, char **map, int x, int y)
{
	if (map[y][x] == 'D')
	{
		if (((map[y - 1] && map[y + 1])) && (ft_strchr("0NSWE", map[y - 1][x])
			&& ft_strchr("0NSWE", map[y + 1][x])))
			if (map[y][x - 1] && map[y][x + 1] && map[y][x - 1] == '1'
				&& map[y][x + 1])
				return ;
		if (map[y][x - 1] && map[y][x + 1] && ft_strchr("0NSWE", map[y][x - 1])
			&& ft_strchr("0NSWE", map[y][x + 1]))
			if (map[y - 1][x] && map[y + 1][x] && map[y - 1][x] == '1'
				&& map[y + 1][x] == '1')
				return ;
		ft_msj_error(g, 1, "Door has no access.");
	}
}

static char	check_next_char(t_cub *g, char next, int *change)
{
	if (next == 'D' && g->open)
	{
		(*change) = 1;
		next = 'O';
	}
	else if (next == 'O' && !g->open)
	{
		(*change) = 1;
		next = 'D';
	}
	return (next);
}

static void	check_door_in_x(t_cub *g, int y, int x, int *change)
{
	if (g->map[y] && g->map[y][x + 1])
		g->map[y][x + 1] = check_next_char(g, g->map[y][x + 1], change);
	if (x > 0 && g->map[y] && g->map[y][x - 1])
		g->map[y][x - 1] = check_next_char(g, g->map[y][x - 1], change);
	if (g->map[y] && g->map[y][x + 1] && g->map[y][x + 2])
		g->map[y][x + 2] = check_next_char(g, g->map[y][x + 2], change);
	if (x > 1 && g->map[y] && g->map[y][x - 1] && g->map[y][x - 2])
		g->map[y][x - 2] = check_next_char(g, g->map[y][x - 2], change);
}

static void	check_door_in_y(t_cub *g, int y, int x, int *change)
{
	if (g->map[y + 1])
		g->map[y + 1][x] = check_next_char(g, g->map[y + 1][x], change);
	if (y > 0 && g->map[y - 1])
		g->map[y - 1][x] = check_next_char(g, g->map[y - 1][x], change);
	if (g->map[y + 1] && g->map[y + 2])
		g->map[y + 2][x] = check_next_char(g, g->map[y + 2][x], change);
	if (y > 1 && g->map[y - 1] && g->map[y - 2])
		g->map[y - 2][x] = check_next_char(g, g->map[y - 2][x], change);
}

void	open_door(t_cub *g)
{
	int	change;
	int	x;
	int	y;

	change = 0;
	x = g->player->x;
	y = g->player->y;
	if (!g->open)
		g->open = 1;
	else if (g->open)
		g->open = 0;
	check_door_in_y(g, y, x, &change);
	check_door_in_x(g, y, x, &change);
	if (change == 0 && g->open)
		g->open = 0;
	else if (change == 0 && !g->open)
		g->open = 1;
	put_textures(g);
	ray_casting(g, g->ray);
}

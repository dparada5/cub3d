/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:40:02 by dparada           #+#    #+#             */
/*   Updated: 2024/12/27 10:00:54 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cub3D_bonus.h"

int	ft_is_all_space(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
		if (line[i] != ' ' && (line[i] <= 9 || line[i] >= 13))
			return (0);
	return (1);
}

void	open_map(t_cub *game, char *argv)
{
	char	*name;
	char	*backslash;

	name = ft_strrchr(argv, '.');
	backslash = ft_strrchr(argv, '/');
	if (backslash && (!ft_strcmp (&backslash[1], ".cub") \
	|| backslash[1] == '.'))
		ft_msj_error(game, 1, "Can't have hidden files.");
	if (ft_strcmp(name, ".cub"))
		return (ft_msj_error(game, 1, "Incorrect extension"));
	if (ft_strlen(name) == ft_strlen(argv))
		ft_msj_error(game, 1, "Can't have hidden files.");
	game->fd = open(argv, O_RDONLY);
	if (game->fd < 0)
		return (ft_msj_error(game, 1, "Can't open file."));
}

void	ft_msj_error(t_cub *game, int use, char *str)
{
	ft_putstr_fd("Error: ", 2);
	ft_putendl_fd(str, 2);
	if (!use)
	{
		ft_putendl_fd("Correct use: ", 2);
		ft_putendl_fd("./cub3d Maps/map.cub", 2);
		return ;
	}
	free_game(game);
	exit(EXIT_FAILURE);
}

void	change_spaces(t_cub *game)
{
	int	y;
	int	x;

	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
			if (game->map[y][x] == ' ')
				game->map[y][x] = '1';
	}
}

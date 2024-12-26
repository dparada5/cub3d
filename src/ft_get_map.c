/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:39:54 by dparada           #+#    #+#             */
/*   Updated: 2024/12/26 17:20:13 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cub3D_bonus.h"

static int	check_content(t_cub *game, char *line, int len, int u)
{
	int	i;

	if (!line)
		return (0);
	if (u && ft_strlen(line) <= (size_t)len)
		ft_msj_error(game, 1, "No content in texture line.");
	else if (!u && ft_strlen(line) <= (size_t)len)
		ft_msj_error(game, 1, "No content in color line.");
	else
	{
		i = len - 2;
		while (line[++i])
			if (line[i] != ' ' && line[i] != '\n')
				break ;
	}
	if (u && line[i] && line[i] == ' ' && line[i] == '\n')
		ft_msj_error(game, 1, "No content in texture line.");
	else if (!u && line[i] && line[i] == ' ' && line[i] == '\n')
		ft_msj_error(game, 1, "No content in color line.");
	return (1);
}

static	char	*coor(t_cub *game, char *dst, char *coor, char *line)
{
	ft_printf_fd("---------------------------deaca\n");
	if (!dst && !ft_strncmp(line, coor, ft_first_char(line, ' '))
		&& check_content(game, line, ft_first_char(line, ' '), 1))
	{
		game->coor->n_coor++;
		return (ft_substr(line, 0, ft_strlen(line) - 1));
	}
	if (dst)
		return (dst);
	return (NULL);
}

static void	ft_save_coor(t_cub *g, char *line)
{
	g->coor->north = coor(g, g->coor->north, "NO", line);
	g->coor->south = coor(g, g->coor->south, "SO", line);
	g->coor->west = coor(g, g->coor->west, "WE", line);
	g->coor->east = coor(g, g->coor->east, "EA", line);
	g->coor->floor = coor(g, g->coor->floor, "F", line);
	g->coor->ceiling = coor(g, g->coor->ceiling, "C", line);
	if (g->coor->n_coor >= 6 && ft_strcmp(line, "\n") \
	&& !ft_is_all_space(line))
		g->start_map = 1;
}

static int	check_newline(char *line)
{
	int	i;

	i = -1;
	if (!line)
		return (1);
	while (line[++i])
		if (line[i + 1] && line[i] == '\n' && line[i + 1] == '\n')
			return (0);
	return (1);
}

void	ft_maps(t_cub *game, char *aux, char *result)
{
	char	*line;
	int		flag;

	flag = 0;
	line = get_next_line(game->fd);
	while (line)
	{
		if (!game->start_map)
			ft_save_coor(game, line);
		else if (game->start_map)
		{
			aux = result;
			result = ft_strjoin(aux, line);
			if (!check_newline(result))
				flag = 1;
		}
		free(line);
		line = get_next_line(game->fd);
	}
	if (result && !flag)
		game->map = ft_split(result, '\n');
	if (result)
		free(result);
	if (flag)
		ft_msj_error(game, 1, "Newline in the middle of map.");
}

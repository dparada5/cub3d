/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:39:54 by dparada           #+#    #+#             */
/*   Updated: 2024/12/20 18:11:36 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cub3D.h"

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

void	check_if_door(t_cub *g, char *line)
{
	if (!g->coor->door && !ft_strncmp(line, "D", ft_first_char(line, ' ')) \
	&& check_content(g, line, ft_first_char(line, ' '), 0))
		g->coor->door = ft_substr(line, 0, ft_strlen(line) - 1);
}

static void	ft_save_coor(t_cub *g, char *line)
{
	check_if_door(g, line);
	if (!g->coor->north && !ft_strncmp(line, "NO", ft_first_char(line, ' ')) \
	&& check_content(g, line, ft_first_char(line, ' '), 1))
		g->coor->north = ft_substr(line, 0, ft_strlen(line) - 1);
	if (!g->coor->south && !ft_strncmp(line, "SO", ft_first_char(line, ' ')) \
	&& check_content(g, line, ft_first_char(line, ' '), 1))
		g->coor->south = ft_substr(line, 0, ft_strlen(line) - 1);
	if (!g->coor->west && !ft_strncmp(line, "WE", ft_first_char(line, ' ')) \
	&& check_content(g, line, ft_first_char(line, ' '), 1))
		g->coor->west = ft_substr(line, 0, ft_strlen(line) - 1);
	if (!g->coor->east && !ft_strncmp(line, "EA", ft_first_char(line, ' ')) \
	&& check_content(g, line, ft_first_char(line, ' '), 1))
		g->coor->east = ft_substr(line, 0, ft_strlen(line) - 1);
	if (!g->coor->floor && !ft_strncmp(line, "F", ft_first_char(line, ' ')) \
	&& check_content(g, line, ft_first_char(line, ' '), 0))
		g->coor->floor = ft_substr(line, 0, ft_strlen(line) - 1);
	if (!g->coor->ceiling && !ft_strncmp(line, "C", ft_first_char(line, ' ')) \
	&& check_content(g, line, ft_first_char(line, ' '), 0))
		g->coor->ceiling = ft_substr(line, 0, ft_strlen(line) - 1);
	if (g->coor->n_coor >= 7 && ft_strcmp(line, "\n") \
	&& !ft_is_all_space(line))
		g->start_map = 1;
	if (ft_strcmp(line, "\n") && ft_strlen(line))
		g->coor->n_coor++;
}

static void	check_newline(t_cub *game, char *line)
{
	int	i;

	i = -1;
	if (!line)
		return ;
	while (line[++i])
		if (line[i + 1] && line[i] == '\n' && line[i + 1] == '\n')
			ft_msj_error(game, 1, "Newline in the middle of map.");
}

void	ft_maps(t_cub *game, char *aux, char *result, char *prev)
{
	char	*line;

	line = get_next_line(game->fd);
	while (line)
	{
		if (!game->start_map)
			ft_save_coor(game, line);
		if (game->start_map)
		{
			aux = result;
			result = ft_strjoin(aux, line);
			check_newline(game, result);
		}
		free(prev);
		prev = ft_strdup(line);
		free(line);
		line = get_next_line(game->fd);
	}
	if (result)
		game->map = ft_split(result, '\n');
	free(prev);
	free(result);
}

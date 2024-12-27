/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:39:54 by dparada           #+#    #+#             */
/*   Updated: 2024/12/27 12:53:16 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cub3D.h"

static	char	*get_coor(t_cub *game, char *dst, char *coor, char *line)
{
	if (!dst && !ft_strncmp(line, coor, ft_first_char(line, ' ')))
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
	if (ft_strcmp(line, "\n") && ft_strlen(line)
		&& (ft_strncmp(line, "NO", ft_first_char(line, ' '))
			&& ft_strncmp(line, "SO", ft_first_char(line, ' '))
			&& ft_strncmp(line, "WE", ft_first_char(line, ' '))
			&& ft_strncmp(line, "EA", ft_first_char(line, ' '))
			&& ft_strncmp(line, "F", ft_first_char(line, ' '))
			&& ft_strncmp(line, "C", ft_first_char(line, ' ')))
		&& g->coor->n_coor < 6)
		ft_msj_error(g, 1, "Unrecognized line.");
	g->coor->north = get_coor(g, g->coor->north, "NO", line);
	g->coor->south = get_coor(g, g->coor->south, "SO", line);
	g->coor->west = get_coor(g, g->coor->west, "WE", line);
	g->coor->east = get_coor(g, g->coor->east, "EA", line);
	g->coor->floor = get_coor(g, g->coor->floor, "F", line);
	g->coor->ceiling = get_coor(g, g->coor->ceiling, "C", line);
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

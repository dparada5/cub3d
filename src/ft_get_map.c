/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 11:20:20 by dparada           #+#    #+#             */
/*   Updated: 2024/11/21 11:27:54 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cub3D.h"

static void	ft_save_coor(t_cub *game, char *line)
{
	//consultas a personas:
	//espacios pueden haber muchos o tienen que tener maximo uno? tabs son permitidos
	if (!game->coor->north && !ft_strncmp(line, "NO", 2))
		game->coor->north = ft_strdup(line);
	else if (!ft_strncmp(line, "SO", 2))
		game->coor->south = ft_strdup(line);
	else if (!ft_strncmp(line, "WE", 2))
		game->coor->west = ft_strdup(line);
	else if (!ft_strncmp(line, "EA", 2))
		game->coor->east = ft_strdup(line);
	else if (!ft_strncmp(line, "F", 1))
		game->coor->floor = ft_strdup(line);
	else if (!ft_strncmp(line, "C", 1))
		game->coor->cealing = ft_strdup(line);
	else if (game->coor->n_coor >= 6 && ft_strcmp(line, "\n") \
	&& !ft_is_all_space(line))
		game->start_map = 1;
	if (ft_strcmp(line, "\n") && ft_strlen(line))
		game->coor->n_coor++;
}

static int	is_map_closed(t_cub *game, char *line)
{
	int	i;

	i = -1;
	if (!line)
		return (0);
	while (line[++i])
		if (line[i] != '1' && line[i] != ' ' && line[i] != '\n')
			return (ft_msj_error(game, 1, "Empty line in the " \
					"middle of map."), 0);
	return (1);
}

void	ft_maps(t_cub *game, char *aux, char *result, char *prev)
{
	char	*line;

	if (game->error_flag)
		return ;
	line = get_next_line(game->fd);
	while (line)
	{
		if (!game->start_map)
			ft_save_coor(game, line);
		if (game->start_map)
		{
			aux = result;
			if (!ft_strcmp(line, "\n") || !ft_strlen(line))
				if (!is_map_closed(game, prev))
					return ;
			result = ft_strjoin(aux, line);
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

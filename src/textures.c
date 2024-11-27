/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:55:07 by dparada           #+#    #+#             */
/*   Updated: 2024/11/27 12:40:29 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cub3D.h"

static int	check_line(t_cub *game, int u, char *line, char *msg_error)
{
	int	i;
	int	spaces;
	int	commas;

	i = -1;
	spaces = 0;
	commas = 0;
	if (!line)
		return (ft_msj_error(game, 1, msg_error), 1);
	while (line[++i])
		if (line[i] == ' ')
			spaces++;
	i = -1;
	while (line[++i])
		if (line[i] == ',')
			commas++;
	if (spaces != 1)
		return (0);
	if (u && commas != 2)
		ft_msj_error(game, 1, "Invalid number of commas.");
	return (1);
}

static mlx_image_t	*ft_texture_to_img(t_cub *game, char *line)
{
	mlx_texture_t	*aux;
	mlx_image_t		*img;

	aux = NULL;
	img = NULL;
	aux = mlx_load_png(line);
	if (!aux)
		return (ft_msj_error(game, 1, "Path to texture incorrect."), NULL);
	img = mlx_texture_to_image(game->mlx, aux);
	if (!img)
		return (ft_msj_error(game, 1, "Converting texture to image."), NULL);
	mlx_delete_texture(aux);
	return (img);
}

int	check_colors(t_cub *game, char *str)
{
	int	i;
	int	aux;

	i = -1;
	aux = -1;
	while (str[++i])
		if (str[i] != '-' && str[i] != '+' && !ft_isdigit(str[i]))
			ft_msj_error(game, 1, "Incorrect character in color asignation.");
	aux = ft_atoi(str);
	if (aux > 255 || aux < 0)
		ft_msj_error(game, 1, "Invalid range of numbers in color asignation.");
	return (aux);
}

static t_colors	*save_colors(t_cub *game, char **matrix)
{
	int			i;
	t_colors	*aux;

	i = -1;
	if (ft_strlen_matrix(matrix) != 3)
		ft_msj_error(game, 1, "Not valid number of colors.");
	aux = malloc(sizeof(t_colors));
	if (!aux)
		ft_msj_error(game, 1, "Malloc failed.");
	aux->red = check_colors(game, matrix[0]);
	aux->blue = check_colors(game, matrix[1]);
	aux->yellow = check_colors(game, matrix[2]);
	return (aux);
}

void	open_textures(t_cub *game)
{
	int		i;
	char	**aux;

	i = 0;
	aux = NULL;
	if (!check_line(game, 0, game->coor->north, "No path to texture.") \
		|| !check_line(game, 0, game->coor->south, "No path to texture.") \
		|| !check_line(game, 0, game->coor->west, "No path to texture.") \
		|| !check_line(game, 0, game->coor->east, "No path to texture."))
		return (ft_msj_error(game, 1, "Too many spaces/tabs in texture line."));
	game->coor->north_i = ft_texture_to_img(game, &game->coor->north[3]);
	game->coor->south_i = ft_texture_to_img(game, &game->coor->south[3]);
	game->coor->east_i = ft_texture_to_img(game, &game->coor->east[3]);
	game->coor->west_i = ft_texture_to_img(game, &game->coor->west[3]);
	if (!check_line(game, 1, game->coor->floor, "No path to color.") \
	|| !check_line(game, 1, game->coor->cealing, "No path to color."))
		return (ft_msj_error(game, 1, "Too many spaces/tabs in color line."));
	aux = ft_split(&game->coor->floor[2], ',');
	game->coor->t_floor = save_colors(game, aux);
	ft_free(aux);
	aux = ft_split(&game->coor->cealing[2], ',');
	game->coor->t_ceiling = save_colors(game, aux);
	ft_free(aux);
}

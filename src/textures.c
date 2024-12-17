#include "../Include/cub3D.h"

static int	check_line(t_cub *game, int u, char *line, char *msg_error)
{
	int	i;
	int	commas;

	commas = 0;
	if (!line)
		return (ft_msj_error(game, 1, msg_error), 1);
	i = -1;
	while (line[++i])
		if (line[i] == ',')
			commas++;
	if (u && commas != 2)
		ft_msj_error(game, 1, "Invalid number of commas.");
	return (1);
}

static mlx_texture_t	*ft_load_texture(t_cub *game, char *line)
{
	mlx_texture_t	*txt;
	int				i;

	i = -1;
	while (line[++i])
		if (line[i] != ' ')
			break;
	txt = NULL;
	txt = mlx_load_png(&line[i]);
	if (!txt)
		return (ft_msj_error(game, 1, "Path to texture incorrect."), NULL);
	return (txt);
}

static int	check_colors(t_cub *game, char *str)
{
	int	i;
	int	aux;

	i = -1;
	aux = -1;
	while (str[++i])
		if (str[i] != ' ' && !ft_isdigit(str[i]))
			ft_msj_error(game, 1, "Incorrect character in color asignation.");
	i = -1;
	while (str[++i])
		if (!ft_isspace(str[i]))
			break ;
	aux = ft_atoi(&str[i]);
	if (aux > 255 || aux < 0)
		ft_msj_error(game, 1, "Invalid range of numbers in color asignation.");
	return (aux);
}

static t_colors	*save_colors(t_cub *game, char **matrix)
{
	t_colors	*aux;

	if (ft_strlen_matrix(matrix) != 3)
		ft_msj_error(game, 1, "Not valid number of colors.");
	aux = malloc(sizeof(t_colors));
	if (!aux)
		ft_msj_error(game, 1, "Malloc failed.");
	aux->red = check_colors(game, matrix[0]);
	aux->green = check_colors(game, matrix[1]);
	aux->blue = check_colors(game, matrix[2]);
	return (aux);
}

void	open_textures(t_cub *game)
{
	char	**aux;

	aux = NULL;
	if (!game->coor->north || !game->coor->south || !game->coor->east || !game->coor->west)
		ft_msj_error(game, 1, "No path to texture..");
	game->coor->north_i = ft_load_texture(game, &game->coor->north[3]);
	game->coor->south_i = ft_load_texture(game, &game->coor->south[3]);
	game->coor->east_i = ft_load_texture(game, &game->coor->east[3]);
	game->coor->west_i = ft_load_texture(game, &game->coor->west[3]);
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

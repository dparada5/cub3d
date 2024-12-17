
#include "../Include/cub3D.h"

static int	check_content(t_cub *game, char *line, int len, char *msg)
{
	int	i;

	if (!line)
		return (0);
	if (ft_strlen(line) <= (size_t)len)
		ft_msj_error(game, 1, msg);
	else
	{
		i = len - 2;
		while (line[++i])
			if (line[i] != ' ' && line[i] != '\n')
				break ;
	}
	if (line[i] && line[i] == ' ' && line[i] == '\n')
		ft_msj_error(game, 1, msg);
	return (1);
}

static void	ft_save_coor(t_cub *game, char *line)
{
	if (!game->coor->north && !ft_strncmp(line, "NO ", 3) && check_content(game, line, 4, "No content in texture line."))
		game->coor->north = ft_substr(line, 0, ft_strlen(line) - 1);
	if (!game->coor->south && !ft_strncmp(line, "SO ", 3) && check_content(game, line, 4, "No content in texture line."))
		game->coor->south = ft_substr(line, 0, ft_strlen(line) - 1);
	if (!game->coor->west && !ft_strncmp(line, "WE ", 3) && check_content(game, line, 4, "No content in texture line."))
		game->coor->west = ft_substr(line, 0, ft_strlen(line) - 1);
	if (!game->coor->east && !ft_strncmp(line, "EA ", 3) && check_content(game, line, 4, "No content in texture line."))
		game->coor->east = ft_substr(line, 0, ft_strlen(line) - 1);
	if (!game->coor->floor && !ft_strncmp(line, "F ", 2) && check_content(game, line, 3, "No content in color line."))
		game->coor->floor = ft_substr(line, 0, ft_strlen(line) - 1);
	if (!game->coor->cealing && !ft_strncmp(line, "C ", 2) && check_content(game, line, 3, "No content in color line."))
		game->coor->cealing = ft_substr(line, 0, ft_strlen(line) - 1);
	if (game->coor->n_coor >= 6 && ft_strcmp(line, "\n") \
	&& !ft_is_all_space(line))
		game->start_map = 1;
	if (ft_strcmp(line, "\n") && ft_strlen(line))
		game->coor->n_coor++;
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


#include "../Include/cub3D.h"

void	ft_delete_images(t_coor *coor)
{
	if (coor->north_i)
		mlx_delete_texture(coor->north_i);
	if (coor->south_i)
		mlx_delete_texture(coor->south_i);
	if (coor->west_i)
		mlx_delete_texture(coor->west_i);
	if (coor->east_i)
		mlx_delete_texture(coor->east_i);
}

// mlx_delete_image()
//should destroy mlx images?
void	free_coor(t_coor *coor)
{
	if (coor->cealing)
		free(coor->cealing);
	if (coor->floor)
		free(coor->floor);
	if (coor->north)
		free(coor->north);
	if (coor->south)
		free(coor->south);
	if (coor->west)
		free(coor->west);
	if (coor->east)
		free(coor->east);
	if (coor->t_ceiling)
		free(coor->t_ceiling);
	if (coor->t_floor)
		free(coor->t_floor);
	ft_delete_images(coor);
	if (coor)
		free(coor);
}

void	free_game(t_cub *game)
{
	if (game)
	{
		if (game->map)
			ft_free(game->map);
		if (game->coor)
			free_coor(game->coor);
		if (game->player)
			free(game->player);
		if (game->fd != -1)
			close(game->fd);
		if (game->mini_map)
			free(game->mini_map);
		mlx_terminate(game->mlx);
		free(game);
	}
}

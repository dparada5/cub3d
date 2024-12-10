#include "../Include/cub3D.h"

t_coor	*malloc_coor(t_cub *game)
{
	t_coor	*coor;

	coor = malloc(sizeof(t_coor));
	if (!coor)
		ft_msj_error(game, 1, "Malloc failed.");
	coor->n_coor = 0;
	coor->north = NULL;
	coor->south = NULL;
	coor->east = NULL;
	coor->west = NULL;
	coor->floor = NULL;
	coor->cealing = NULL;
	coor->north_i = NULL;
	coor->south_i = NULL;
	coor->east_i = NULL;
	coor->west_i = NULL;
	coor->t_ceiling = NULL;
	coor->t_floor = NULL;
	return (coor);
}

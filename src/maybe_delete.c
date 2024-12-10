
#include "../Include/cub3D.h"

void	printf_player(t_cub *game)
{
	printf("x = %f y = %f view = %c\n", game->player->x, game->player->y, game->player->view);
}

void	printf_coor(t_coor *coor)
{
	if (!coor)
		return ;
	if (coor->north)
		ft_printf_fd("%s\n", coor->north);
	if (coor->south)
		ft_printf_fd("%s\n", coor->south);
	if (coor->west)
		ft_printf_fd("%s\n", coor->west);
	if (coor->east)
		ft_printf_fd("%s\n", coor->east);
	if (coor->floor)
		ft_printf_fd("%s\n", coor->floor);
	if (coor->cealing)
		ft_printf_fd("%s\n", coor->cealing);
}

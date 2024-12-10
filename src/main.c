
#include "../Include/cub3D.h"

void	ft_init_game(t_cub *game)
{
	game->mlx = mlx_init(W_WIDTH, W_HEIGHT, "cub3D", false);
	if (!game->mlx)
		ft_msj_error(game, 1, NULL);
	game->coor = malloc_coor(game);
	game->player = malloc(sizeof(t_player));
	if (!game->player)
		ft_msj_error(game, 1, "Malloc failed.");
	game->map = NULL;
	game->map_len = 0;
	game->start_map = 0;
	game->n_player = 0;
	game->fd = -1;
}

int	main(int argc, char **argv)
{
	t_cub	*game;

	if (argc != 2)
		return (ft_msj_error(NULL, 0, "Incorrect argument number."), 1);
	game = malloc(sizeof(t_cub));
	if (!game)
		return (1);
	ft_init_game(game);
	open_map(game, argv[1]);
	ft_maps(game, NULL, NULL, NULL);
	ft_check_map(game);
	open_textures(game);
	init_mlx_game(game);
	free_game(game);
	return (0);
}

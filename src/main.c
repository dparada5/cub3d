/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:03:37 by dparada           #+#    #+#             */
/*   Updated: 2024/12/09 15:50:40 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cub3D.h"

void	ft_init_game(t_cub *game)
{
	game->mlx = mlx_init(W_WIDTH, W_HEIGHT, "cub3D", false);
	if (!game->mlx)
		ft_msj_error(game, 1, NULL);
	game->coor = malloc(sizeof(t_coor));
	if (!game->coor)
		ft_msj_error(game, 1, "Malloc failed.");
	game->coor->n_coor = 0;
	game->coor->north = NULL;
	game->coor->south = NULL;
	game->coor->east = NULL;
	game->coor->west = NULL;
	game->coor->floor = NULL;
	game->coor->cealing = NULL;
	game->coor->north_i = NULL;
	game->coor->south_i = NULL;
	game->coor->east_i = NULL;
	game->coor->west_i = NULL;
	game->coor->t_ceiling = NULL;
	game->coor->t_floor = NULL;
	game->player = malloc(sizeof(t_player));
	if (!game->player)
		ft_msj_error(game, 1, "Malloc failed.");
	game->map = NULL;
	game->error_flag = 0;
	game->map_len = 0;
	game->start_map = 0;
	game->n_player = 0;
	game->fd = -1;
	game->mini_map = malloc(sizeof(t_minimap));
	if (!game->mini_map)
		ft_msj_error(game, 1, "Malloc failed.");
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

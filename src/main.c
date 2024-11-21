/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:03:37 by dparada           #+#    #+#             */
/*   Updated: 2024/11/20 11:41:30 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cub3D.h"

void	ft_init_game(t_cub *game)
{
	game->coor = malloc(sizeof(t_coor));
	game->coor->n_coor = 0;
	game->coor->north = NULL;
	game->coor->south = NULL;
	game->coor->east = NULL;
	game->coor->west = NULL;
	game->coor->floor = NULL;
	game->coor->cealing = NULL;
	game->map = NULL;
	game->error_flag = 0;
	game->map_len = 0;
	game->start_map = 0;
	game->player = 0;
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
	free_game(game);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:40:21 by dparada           #+#    #+#             */
/*   Updated: 2024/12/26 16:54:33 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cub3D_bonus.h"

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
	ft_maps(game, NULL, NULL);
	ft_check_map(game, -1, -1);
	open_textures(game);
	init_mlx_game(game);
	free_game(game);
	return (0);
}

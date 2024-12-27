/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:37:31 by dparada           #+#    #+#             */
/*   Updated: 2024/12/27 10:39:57 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cub3D.h"

static void	menu(void)
{
	ft_printf("Menu: \n");
	ft_printf("WSAD keys to move around the map.\n");
	ft_printf("Left and right arrows keys to change view.\n");
	ft_printf("ESC key to end game.\n");
}

int	main(int argc, char **argv)
{
	t_cub	*game;

	if (argc != 2)
		return (ft_msj_error(NULL, 0, "Incorrect argument number."), 1);
	if (W_HEIGHT <= 0 || W_WIDTH <= 0)
		ft_msj_error(NULL, 1, "No valid measures.");
	game = malloc(sizeof(t_cub));
	if (!game)
		return (1);
	ft_init_game(game);
	open_map(game, argv[1]);
	ft_maps(game, NULL, NULL);
	ft_check_map(game, -1, -1);
	open_textures(game);
	menu();
	init_mlx_game(game);
	free_game(game);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:08:42 by dparada           #+#    #+#             */
/*   Updated: 2024/11/20 11:41:26 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cub3D.h"

int	ft_is_all_space(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
		if (line[i] != ' ' && (line[i] <= 9 || line[i] >= 13))
			return (0);
	return (1);
}

void	open_map(t_cub *game, char *argv)
{
	char	*name;

	name = ft_strchr(argv, '.');
	if (ft_strcmp(name, ".cub"))
		return (ft_msj_error(game, 1, "Incorrect map?"));
	game->fd = open(argv, O_RDONLY);
	if (game->fd < 0)
		return (ft_msj_error(game, 1, "Can't open map."));
}

void	ft_msj_error(t_cub *game, int use, char *str)
{
	if (game && game->error_flag)
		return ;
	ft_putstr_fd("Error: ", 2);
	ft_putendl_fd(str, 2);
	if (!use)
	{
		ft_putendl_fd("Correct use: ", 2);
		ft_putendl_fd("./cub3d Maps/map.cub", 2);
		return ;
	}
	game->error_flag = 1;
}

void	ft_print_coor(t_cub *game)
{
	t_coor	*aux;

	aux = game->coor;
	ft_putstr_fd(aux->north, 1);
	ft_putstr_fd(aux->south, 1);
	ft_putstr_fd(aux->west, 1);
	ft_putstr_fd(aux->east, 1);
	ft_putstr_fd(aux->cealing, 1);
	ft_putstr_fd(aux->floor, 1);
	ft_putnbr_fd(aux->n_coor, 1);
}


void	print_matrix(char **matrix)
{
	int i;

	i = -1;
	if (!matrix)
		return ;
	while (matrix[++i])
	{
		ft_putstr_fd(matrix[i], 2);
		ft_putendl_fd("-", 2);
	}
}

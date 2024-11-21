/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:03:57 by dparada           #+#    #+#             */
/*   Updated: 2024/11/21 13:44:20 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "LIBFT/libft.h"
// # include "MLX/include/MLX42/MLX42.h"
//estructura de texturas
//estructura de coordenadas?build

typedef struct s_coor
{
	//agregar texturas
	char	*north;//convertir en matrix? o ni?
	char	*south;
	char	*west;
	char	*east;
	char	*floor;
	char	*cealing;//se escribe asi?
	int		n_coor;
}				t_coor;

typedef struct s_cub
{
	int		fd;
	char	**map;
	int		map_len;
	int		error_flag;
	int		start_map;
	int		player;
	t_coor	*coor;
}			t_cub;

//---------------------------UTILS------------------------
void	ft_msj_error(t_cub *game, int use, char *str);
int		ft_is_all_space(char *line);
void	open_map(t_cub *game, char *argv);
void	ft_print_coor(t_cub *game);
void	print_matrix(char **matrix);
//--------------------------MAPS--------------------------
void	ft_check_map(t_cub *game);
void	ft_maps(t_cub *game, char *aux, char *result, char *prev);

//--------------------------FREE--------------------------
void	free_game(t_cub *game);

#endif
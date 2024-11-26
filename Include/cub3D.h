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
# include <math.h>
// # include "MLX/include/MLX42/MLX42.h"
//estructura de texturas
//estructura de coordenadas?build

typedef struct s_ray
{
	double	pos_x; //posicion inicial del rayo
	double	pos_y;
	double	dir_x; // direccion que va a ir el rayo
	double	dir_y;
	// info dda
	double	delta_dist_x; // distancia que debe recorrer el rayo para cruzar una celda del mapa en el eje x/y
	double	delta_dist_y;
	double	side_dist_x; // indica la distancia inicial del rayo desde su pos actual hasta el primer borde de la celda en x/y
	double	side_dist_y;
	double	step_x; // la direccion en que el rayo avanza en cada eje x/y
	double	step_y;
	// info de colisiion
	int	map_x; // donde colisiona en x
	int	map_y; // donde colisiona en y
	double	dis; // distancia que recorre el rayo hasta la colision
	int	side; // ver como lo hacemos, pero esta variable indica que lado impacto, si vertical u horizontal
}	t_ray;

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
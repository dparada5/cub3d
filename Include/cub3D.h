/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:03:57 by dparada           #+#    #+#             */
/*   Updated: 2024/12/02 19:30:35 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "LIBFT/libft.h"
# include "MLX42_P2/include/MLX42/MLX42.h"
# include <math.h>
//estructura de texturas
//estructura de coordenadas?build

# define W_WIDTH 1000
# define W_HEIGHT 800
# define FOV 60.0
# define P_MOVE //velocidad a la que se mueve el player
# define N_PI 3.14159265359
# define N_PI_2 1.57079632679

typedef	struct	s_colors
{
	int	red;
	int	green;
	int	blue;
}				t_colors;

typedef struct	s_player
{
	double	x;
	double	y;
	char	view;
	double	r_view;
}			t_player;

// typedef struct s_ray
// {
// 	double	pos_x; //posicion inicial del rayo
// 	double	pos_y;
// 	double	dir_x; // direccion que va a ir el rayo
// 	double	dir_y;
// 	// info dda
// 	double	delta_dist_x; // distancia que debe recorrer el rayo para cruzar una celda del mapa en el eje x/y
// 	double	delta_dist_y;
// 	double	side_dist_x; // indica la distancia inicial del rayo desde su pos actual hasta el primer borde de la celda en x/y
// 	double	side_dist_y;
// 	double	step_x; // la direccion en que el rayo avanza en cada eje x/y
// 	double	step_y;
// 	// info de colisiion
// 	int	map_x; // donde colisiona en x
// 	int	map_y; // donde colisiona en y
// 	double	dis; // distancia que recorre el rayo hasta la colision
// 	int	side; // ver como lo hacemos, pero esta variable indica que lado impacto, si vertical u horizontal
// }	t_ray;

typedef struct s_ray
{
	double	ang;
	double	sin;
	double	cos;
	double	distance;
	double	col_x; // POSICION DE COLISION X / Y
	double	col_y;

	// DDA
	double	side_dist_x; // Distancia entre intersecciones en el eje x
	double	side_dist_y; // Distancia entre intersecciones en el eje y
	double	delta_dist_x; // Distancia inicial al primer lado en x
	double	delta_dist_y; // Distancia inicial al primer lado en y
	int		step_x; // Direccion de avance en x (1 o -1)
	int		step_y; // Direccion de avance en y (1 o -1)
	int		side;
}	t_ray;

typedef struct s_coor
{
	//agregar texturas
	char	*north;//convertir en matrix? o ni?
	char	*south;
	char	*west;
	char	*east;
	char	*floor;
	char	*cealing;//se escribe asi? no, ceiling
	int		n_coor;
	t_colors	*t_floor;//liberar memoria
	t_colors	*t_ceiling;//liberar memoria
	mlx_image_t	*north_i;
	mlx_image_t	*south_i;
	mlx_image_t	*west_i;
	mlx_image_t	*east_i;
}				t_coor;

typedef struct s_cub
{
	mlx_t		*mlx;
	mlx_image_t	*window_img;
	int			fd;
	char		**map;
	int			map_len;
	int			error_flag;
	int			start_map;
	int			n_player;
	t_ray		*ray;
	t_player	*player;
	t_coor		*coor;
}			t_cub;

//---------------------------RAY CASTING------------------
double	get_radian(int c);
void	ray_casting(t_cub *g, t_ray *ray);

//---------------------------INIT MLX GAME----------------
void	init_mlx_game(t_cub *game);

//---------------------------MOVES------------------------
void	set_moves(mlx_key_data_t key, void *param);
//---------------------------PUT TEXTURES-----------------
void	put_textures(t_cub *g);

//---------------------------UTILS------------------------
void	ft_msj_error(t_cub *game, int use, char *str);
int		ft_is_all_space(char *line);
void	open_map(t_cub *game, char *argv);
void	ft_print_coor(t_cub *game);
void	print_matrix(char **matrix);
//--------------------------MAPS--------------------------
void	ft_check_map(t_cub *game);
void	ft_maps(t_cub *game, char *aux, char *result, char *prev);
//--------------------------TEXTURES----------------------
void	open_textures(t_cub *game);
//--------------------------FREE--------------------------
void	free_game(t_cub *game);
//--------------------------DELETE------------------------
void	printf_player(t_cub *game);

#endif

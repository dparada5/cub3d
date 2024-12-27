/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanselmo <tanselmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 12:53:57 by dparada           #+#    #+#             */
/*   Updated: 2024/12/27 12:18:48 by tanselmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "LIBFT/libft.h"
# include "MLX42_P2/include/MLX42/MLX42.h"
# include <math.h>
# include <sys/time.h>

# define W_WIDTH 1920
# define W_HEIGHT 1080
# define FOV 60.0
# define P_MOVE 0.075
# define ANG_MOVE 0.0174533
# define N_PI 3.14159265359
# define N_PI_2 1.57079632679
# define PIXEL 64
# define ANIMATIONS 7
# define ANIM_SIZE 500
# define DELAY 100

typedef struct s_animation
{
	mlx_texture_t	*frames[ANIMATIONS];
	mlx_image_t		*img;
	int				current_frame;
	int				last_time;
}				t_animation;

typedef struct s_colors
{
	int	red;
	int	green;
	int	blue;
	int	alpha;
}				t_colors;

typedef struct s_player
{
	double	x;
	double	y;
	char	view;
	double	r_view;
}			t_player;

typedef struct s_ray
{
	double	ang;
	double	sin;
	double	cos;
	double	distance;
	double	col_x;
	double	col_y;
	double	start_y;
	double	end_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		step_x;
	int		step_y;
	int		side;
	double	wall_x;
	int		tex_x;
	int		tex_y;
	int		index;
	bool	door;
}	t_ray;

typedef struct s_coor
{
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	char			*floor;
	char			*ceiling;
	char			*door;
	int				n_coor;
	t_colors		*t_floor;
	t_colors		*t_ceiling;
	mlx_texture_t	*north_i;
	mlx_texture_t	*south_i;
	mlx_texture_t	*west_i;
	mlx_texture_t	*east_i;
	mlx_texture_t	*door_i;
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
	int			open;
	t_ray		*ray;
	t_player	*player;
	t_coor		*coor;
	t_animation	*anim;
}			t_cub;

//---------------------------BONUS------------------------
int		get_time(void);
void	update_animation(t_cub *g);
void	init_animations(t_cub *g);
void	update_minimap(t_cub *g);
void	paint_minimap(t_cub *g);
//---------------------------RAY CASTING------------------
double	get_radian(int c);
void	ray_casting(t_cub *g, t_ray *ray);
//---------------------------INIT MLX GAME----------------
void	ft_init_game(t_cub *game);
void	init_mlx_game(t_cub *game);
//---------------------------MOVES------------------------
void	set_moves(mlx_key_data_t key, void *param);
//---------------------------DISTANCE---------------------
void	set_distance(t_cub *g, t_ray *ray);
double	calculate_distance(t_cub *g, t_ray *ray, int map_x, int map_y);
//---------------------------KEYS-------------------------
void	key_w(t_cub *g);
void	key_s(t_cub *g);
void	key_a(t_cub *g);
void	key_d(t_cub *g);
void	key_left_right(t_cub *g, mlx_key_data_t key);
//---------------------------TEXTURES---------------------
void	open_textures(t_cub *game);
void	put_textures(t_cub *g);
int		get_rgba(int r, int g, int b, int a);
void	paint_texture(t_cub *g, t_ray *ray, mlx_texture_t *curr, int wall_h);
void	create_walls(t_cub *g, t_ray *ray, int i);
//---------------------------UTILS------------------------
void	ft_msj_error(t_cub *game, int use, char *str);
int		ft_is_all_space(char *line);
void	open_map(t_cub *game, char *argv);
void	change_spaces(t_cub *game);
//--------------------------MAPS--------------------------
void	ft_check_map(t_cub *game, int y, int x);
void	ft_maps(t_cub *game, char *aux, char *result);
//--------------------------FREE--------------------------
void	free_game(t_cub *game);
//--------------------------MALLOC------------------------
t_coor	*malloc_coor(t_cub *game);
//--------------------------DOOR--------------------------
void	open_door(t_cub *g);
void	check_valid_door(t_cub *g, char **map, int x, int y);

#endif

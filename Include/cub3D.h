
#ifndef CUB3D_H
# define CUB3D_H

# include "LIBFT/libft.h"
# include "MLX42_P2/include/MLX42/MLX42.h"
# include <math.h>
//estructura de texturas
//estructura de coordenadas?build

# define W_WIDTH 1920
# define W_HEIGHT 1080
# define FOV 60.0
# define P_MOVE 0.075
# define ANG_MOVE 0.0174533
# define N_PI 3.14159265359
# define N_PI_2 1.57079632679
# define PIXEL 64
# define ANIMATIONS 7
# define DELAY 10

typedef struct s_animation
{
	mlx_texture_t	*frames[ANIMATIONS];
	int				curr_frame;
	int				frame_counter;
	int				x;
	int				y;
}				t_animation;

typedef struct s_minimap
{
	int	start_y;
	int	start_x;
	int	end_y;
	int	end_x;
	int	width;
	int	height;
	int	pixel_size;
	int	offset_y;
	int	offset_x;
}				t_minimap;

typedef	struct	s_colors
{
	int	red;
	int	green;
	int	blue;
	int	alpha;
}				t_colors;

typedef struct	s_player
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
	double	col_x; // POSICION DE COLISION X / Y
	double	col_y;
	double	start_y;
	double	end_y;

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
	mlx_texture_t	*north_i;
	mlx_texture_t	*south_i;
	mlx_texture_t	*west_i;
	mlx_texture_t	*east_i;
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
	t_minimap	*mini_map;
}			t_cub;

//---------------------------RAY CASTING------------------
double	get_radian(int c);
void	ray_casting(t_cub *g, t_ray *ray);

//---------------------------INIT MLX GAME----------------
void	init_mlx_game(t_cub *game);
void	mini_map(void *g);
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
//---------------------------PUT TEXTURES-----------------
void	put_textures(t_cub *g);
int		get_rgba(int r, int g, int b, int a);
void	paint_texture(t_cub *g, t_ray *ray, mlx_texture_t *txt, double wall_h);
//---------------------------UTILS------------------------
void	ft_msj_error(t_cub *game, int use, char *str);
int		ft_is_all_space(char *line);
void	open_map(t_cub *game, char *argv);
void	change_spaces(t_cub *game);
//--------------------------MAPS--------------------------
void	ft_check_map(t_cub *game);
void	ft_maps(t_cub *game, char *aux, char *result, char *prev);
//--------------------------TEXTURES----------------------
void	open_textures(t_cub *game);
//--------------------------FREE--------------------------
void	free_game(t_cub *game);
//--------------------------MALLOC--------------------------
t_coor	*malloc_coor(t_cub *game);
//--------------------------DELETE------------------------
void	printf_player(t_cub *game);
void	printf_coor(t_coor *coor);
#endif

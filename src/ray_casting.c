
#include "../Include/cub3D.h"

double	get_radian(int c)
{
	if (c == 'E')
		return (0);
	else if (c == 'N')
		return (N_PI_2);
	else if (c == 'W')
		return (N_PI);
	else
		return (N_PI + N_PI_2);
}

static double	calculate_distance(t_cub *g, t_ray *ray, int map_x, int map_y)
{
	double	dis;

	if (ray->side == 0)
		dis = (map_x - g->player->x + (1 - ray->step_x) / 2) / ray->cos;
	else
		dis = (map_y - g->player->y + (1 - ray->step_y) / 2) / ray->sin;
	return (dis);
}

static void	set_collision(t_cub *g, t_ray *ray, int map_x, int map_y)
{
	if (ray->side == 0) // Paredes verticales
	{
		ray->col_x = map_y + (1 - ray->step_y) / 2.0;
		ray->col_y = ray->step_x * (map_x - g->player->x) / ray->cos + g->player->y;
	}
	else // Pared horizontal
	{
		ray->col_x = ray->step_x * (map_y - g->player->y) / ray->sin + g->player->x;
		ray->col_y = map_x + (1 - ray->step_x) / 2.0;
	}
}

static void	collision_bucle(t_cub *g, t_ray *ray)
{
	int	map_x;
	int	map_y;

	map_x = (int)g->player->x;
	map_y = (int)g->player->y;
	while (1)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			map_x += ray->step_x;
			ray->side_dist_x += ray->delta_dist_x;
			ray->side = 0;
		}
		else
		{
			map_y += ray->step_y;
			ray->side_dist_y += ray->delta_dist_y;
			ray->side = 1;
		}
		if (g->map[map_y][map_x] == '1')
		{
			set_collision(g, ray, map_x, map_y);
			ray->distance = calculate_distance(g, ray, map_x, map_y);
			break ;
		}
	}
}

static void	set_distance(t_cub *g, t_ray *ray)
{
	// Calcular para que lado va a dirigirse el rayo
	if (ray->cos < 0)
		ray->step_x = -1;
	else
		ray->step_x = 1;
	if (ray->sin < 0)
		ray->step_y = -1;
	else
		ray->step_y = 1;
	// Calcular distancias
	if (ray->step_x == 1) // Calcular distancia positivo en x
		ray->side_dist_x = (floor(g->player->x) + 1 - g->player->x) * ray->delta_dist_x;
	else // Calcular distancia negativo en x
		ray->side_dist_x = (g->player->x - floor(g->player->x)) * ray->delta_dist_x;
	if (ray->step_y == 1) // Calcular distancia positivo en y
		ray->side_dist_y = (floor(g->player->y) + 1 - g->player->y) * ray->delta_dist_y;
	else // Calcular distancia negativo en y
		ray->side_dist_y = (g->player->y - floor(g->player->y)) * ray->delta_dist_y;
}

static void	create_walls(t_cub *g, t_ray *ray, int i)
{
	double	distance_corrected;
	int		wall_height;

	distance_corrected = (ray->distance * cos(ray->ang - g->player->r_view));
	wall_height = (W_HEIGHT / distance_corrected);
	if (wall_height > W_HEIGHT)
		wall_height = W_HEIGHT;
	paint_wall(g, ray, i, wall_height);
}

void	ray_casting(t_cub *g, t_ray *ray)
{
	int		i;
	double	r_fov;
	double	ang;
	double	start;

	i = 0;
	r_fov = FOV * N_PI / 180;
	ang = (FOV / W_WIDTH) * N_PI / 180;
	start = g->player->r_view + (ang * (W_WIDTH / 2));
	while (i < W_WIDTH)
	{
		ray[i].ang = start - (ang * i);
		ray[i].cos = cos(ray[i].ang);
		ray[i].sin = sin(ray[i].ang);
		ray[i].delta_dist_x = fabs(1 / ray[i].cos);
		ray[i].delta_dist_y = fabs(1 / ray[i].sin);
		set_distance(g, &ray[i]);
		collision_bucle(g, &ray[i]);
		create_walls(g, &ray[i], i);
		i++;
	}
}
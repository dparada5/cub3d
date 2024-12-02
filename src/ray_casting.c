
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
		i++;
	}
}
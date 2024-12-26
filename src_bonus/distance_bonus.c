/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:39:13 by dparada           #+#    #+#             */
/*   Updated: 2024/12/26 13:13:02 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cub3D_bonus.h"

double	calculate_distance(t_cub *g, t_ray *ray, int map_x, int map_y)
{
	double	dis;

	if (ray->side == 0)
		dis = (map_x - g->player->x + (1 - ray->step_x) / 2) / ray->cos;
	else
		dis = (map_y - g->player->y + (1 - ray->step_y) / 2) / ray->sin;
	return (dis);
}

void	set_distance(t_cub *g, t_ray *ray)
{
	if (ray->cos < 0)
		ray->step_x = -1;
	else
		ray->step_x = 1;
	if (ray->sin < 0)
		ray->step_y = -1;
	else
		ray->step_y = 1;
	if (ray->step_x == 1)
		ray->side_dist_x = (floor(g->player->x) + 1
				- g->player->x) * ray->delta_dist_x;
	else
		ray->side_dist_x = (g->player->x - floor(g->player->x))
			* ray->delta_dist_x;
	if (ray->step_y == 1)
		ray->side_dist_y = (floor(g->player->y) + 1
				- g->player->y) * ray->delta_dist_y;
	else
		ray->side_dist_y = (g->player->y - floor(g->player->y))
			* ray->delta_dist_y;
}

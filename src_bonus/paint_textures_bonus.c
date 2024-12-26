/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_textures_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:40:39 by dparada           #+#    #+#             */
/*   Updated: 2024/12/26 13:20:46 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cub3D_bonus.h"

static int	get_color(mlx_texture_t *curr, int index)
{
	int	color;
	int	red;
	int	green;
	int	blue;
	int	alpha;

	red = curr->pixels[index + 0];
	green = curr->pixels[index + 1];
	blue = curr->pixels[index + 2];
	alpha = curr->pixels[index + 3];
	color = get_rgba(red, green, blue, alpha);
	return (color);
}

void	paint_texture(t_cub *g, t_ray *ray, mlx_texture_t *curr, int wall_h)
{
	int	y;
	int	color;
	int	idx;

	y = ray->start_y;
	if (y < 0)
		y = 0;
	while (y < ray->end_y)
	{
		ray->tex_y = ((y - ray->start_y) * curr->height) / wall_h;
		idx = ((ray->tex_y * curr->width + ray->tex_x) * 4);
		color = get_color(curr, idx);
		mlx_put_pixel(g->window_img, ray->index, y, color);
		y++;
	}
}

static mlx_texture_t	*set_texture(t_cub *g, t_ray *ray)
{
	mlx_texture_t	*current;

	current = NULL;
	if (ray->side == 0)
	{
		ray->wall_x = g->player->y + ray->distance * ray->sin;
		if (ray->cos > 0)
			current = g->coor->east_i;
		else
			current = g->coor->west_i;
	}
	if (ray->side == 1)
	{
		ray->wall_x = g->player->x + ray->distance * ray->cos;
		if (ray->sin > 0)
			current = g->coor->south_i;
		else
			current = g->coor->north_i;
	}
	if (ray->door == true && g->coor->door_i)
		current = g->coor->door_i;
	ray->wall_x -= floor(ray->wall_x);
	return (current);
}

void	create_walls(t_cub *g, t_ray *ray, int i)
{
	mlx_texture_t	*current;
	double			distance_corrected;
	int				wall_height;

	distance_corrected = ray->distance * cos(ray->ang - g->player->r_view);
	wall_height = (int)(W_HEIGHT / distance_corrected);
	ray->start_y = (W_HEIGHT / 2) - (wall_height / 2);
	ray->end_y = (W_HEIGHT / 2) + (wall_height / 2);
	if (ray->end_y > W_HEIGHT)
		ray->end_y = W_HEIGHT;
	current = set_texture(g, ray);
	ray->tex_x = (int)(ray->wall_x * current->width);
	if ((ray->side == 0 && ray->cos < 0) || (ray->side == 1 && ray->sin > 0))
		ray->tex_x = current->width - ray->tex_x - 1;
	ray->index = i;
	paint_texture(g, ray, current, wall_height);
}

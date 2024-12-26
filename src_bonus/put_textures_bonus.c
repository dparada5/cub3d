/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_textures_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dparada <dparada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:41:00 by dparada           #+#    #+#             */
/*   Updated: 2024/12/26 13:09:03 by dparada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cub3D_bonus.h"

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

static void	put_ceiling(t_cub *g, mlx_image_t *img)
{
	int	rgb;
	int	x;
	int	y;

	y = 0;
	rgb = get_rgba(g->coor->t_ceiling->red, g->coor->t_ceiling->green,
			g->coor->t_ceiling->blue, 255);
	while (y < W_HEIGHT / 2)
	{
		x = 0;
		while (x < W_WIDTH)
		{
			mlx_put_pixel(img, x, y, rgb);
			x++;
		}
		y++;
	}
}

static void	put_floor(t_cub *g, mlx_image_t *img)
{
	int	rgb;
	int	x;
	int	y;

	y = W_HEIGHT / 2;
	rgb = get_rgba(g->coor->t_floor->red, g->coor->t_floor->green,
			g->coor->t_floor->blue, 255);
	while (y < W_HEIGHT)
	{
		x = 0;
		while (x < W_WIDTH)
		{
			mlx_put_pixel(img, x, y, rgb);
			x++;
		}
		y++;
	}
}

void	put_textures(t_cub *g)
{
	put_ceiling(g, g->window_img);
	put_floor(g, g->window_img);
}

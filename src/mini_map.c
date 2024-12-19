#include "../Include/cub3D.h"

static void	put_map_background(t_cub *g)
{
	int	start_y;
	int	start_x;

	start_y = g->mini_map->start_y;
	start_x = g->mini_map->start_x;
	while (start_y < g->mini_map->end_y)
	{
		start_x = g->mini_map->start_x;
		while (start_x < g->mini_map->end_x)
		{
			mlx_put_pixel(g->window_img, start_x, start_y, get_rgba(116, 116, 116, 255));
			start_x++;
		}
		start_y++;
	}
}

static void	color_player(t_cub *g, int pos_y, int pos_x, int p_size)
{
	int	start_y;
	int	start_x;

	start_y = pos_y - p_size / 2;
	while (start_y < pos_y + p_size / 2)
	{
		start_x = pos_x - p_size / 2;
		while (start_x < pos_x + p_size / 2)
		{
			mlx_put_pixel(g->window_img, start_x, start_y, get_rgba(255, 255, 255, 255));
			start_x++;
		}
		start_y++;
	}
}

static void	paint_view(t_cub *g, double r_view, int pos_x, int pos_y)
{
	int	ray_len; // longitus del rayo
	int	end_x; // coordenadas finales del rayo en x
	int	end_y; // coordenadas finales del rayo en y

	ray_len = g->mini_map->pixel_size * 3;
	end_x = pos_x + (int)(ray_len * cos(r_view));
	end_y = pos_y + (int)(ray_len * sin(r_view));
}

static void	put_player(t_cub *g)
{
	int	pos_y;
	int	pos_x;
	int	player_size;

	pos_y = g->mini_map->start_y + (g->mini_map->end_y / 2);
	pos_x = g->mini_map->start_x + (g->mini_map->end_x / 2);
	player_size = g->mini_map->width / 30;
	color_player(g, pos_y, pos_x, player_size);
	paint_view(g, g->player->r_view, pos_x, pos_y);
}

void	mini_map(void *param)
{
	t_cub	*g;

	g = (t_cub *)param;
	put_map_background(g);
	//put_walls(g, g->mini_map, g->player->x, g->player->y);
	put_player(g);
}

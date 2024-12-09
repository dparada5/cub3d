#include "../Include/cub3D.h"

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

static void	put_player(t_cub *g)
{
	int	pos_y;
	int	pos_x;
	int	player_size;

	pos_y = g->mini_map->start_y + ((g->mini_map->end_y - g->mini_map->start_y) / 2);
	pos_x = g->mini_map->start_x + ((g->mini_map->end_x - g->mini_map->start_x) / 2);
	player_size = (g->mini_map->end_x - g->mini_map->start_x) / 40;
	color_player(g, pos_y, pos_x, player_size);
}

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
			mlx_put_pixel(g->window_img, start_x, start_y, get_rgba(0, 0, 0, 255));
			start_x++;
		}
		start_y++;
	}
}

static void	put_walls(t_cub *g, t_minimap *mini_map, int start_y, int start_x)
{
	int	real_y;
	int	real_x;
	int	map_y;
	int	map_x;

	map_y = start_y;
	while (map_y < g->mini_map->end_y)
	{
		map_x = start_x;
		while (map_x < g->mini_map->end_x)
		{
			real_y = (map_y - mini_map->start_y) / mini_map->pixel_size;
			real_x = (map_x - mini_map->start_x) / mini_map->pixel_size;
			if (g->map[real_y][real_x] == '1')
				mlx_put_pixel(g->window_img, map_x, map_y, get_rgba(230, 0, 100, 255));
			map_x++;
		}
		map_y++;
	}
}

void	mini_map(void *param)
{
	t_cub	*g;

	g = (t_cub *)param;
	put_map_background(g);
	put_walls(g, g->mini_map, g->mini_map->start_y, g->mini_map->start_x);
	put_player(g);
}

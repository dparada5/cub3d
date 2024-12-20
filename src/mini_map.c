#include "../Include/cub3D.h"

void	put_map_background(t_cub *g)
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
			mlx_put_pixel(g->map_img, start_x, start_y, get_rgba(116, 116, 116, 255));
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
			mlx_put_pixel(g->map_img, start_x, start_y, get_rgba(255, 0, 0, 255));
			start_x++;
		}
		start_y++;
	}
}

void	put_player(t_cub *g)
{
	int	pos_y;
	int	pos_x;
	int	player_size;

	pos_y = g->mini_map->start_y + (g->mini_map->end_y / 2);
	pos_x = g->mini_map->start_x + (g->mini_map->end_x / 2);
	player_size = g->mini_map->width / 30;
	color_player(g, pos_y, pos_x, player_size);
}

void	paint_wall(int color, t_cub *g, int pos_x, int pos_y)
{
	int	end_x;
	int	end_y;

	end_x = pos_x + (W_HEIGHT / 50);
	end_y = pos_y + (W_HEIGHT / 50);
	while (pos_y <= end_y && pos_y < g->mini_map->end_y)
	{
		pos_x = end_x - (W_HEIGHT / 50);
		while (pos_x < end_x && pos_x < g->mini_map->end_x)
		{
			mlx_put_pixel(g->map_img, pos_x, pos_y, color);
			pos_x++;
		}
		pos_y++;
	}
}

void	put_walls(t_cub *g)
{
	int	y;
	int	x;

	y = g->player->y - 5;
	
	while (++y < g->player->y + 5)
	{
		x = g->player->x - 5;
		while (++x < g->player->x + 5)
		{
			if (g->map[y][x] == '1')
				paint_wall(get_rgba(0, 0, 0, 255), g, x * (W_HEIGHT / 50), y * (W_HEIGHT / 50));
			else if (g->map[y][x] == ' ')
				paint_wall(get_rgba(116, 116, 116, 255), g, x * (W_HEIGHT / 50), y * (W_HEIGHT / 50));
			else
				paint_wall(get_rgba(255, 255, 255, 255), g, x * (W_HEIGHT / 50), y * (W_HEIGHT / 50));
		}
	}
}

void	mini_map(void *param)
{
	t_cub	*g;

	g = (t_cub *)param;
	//put_map_background(g);
	//put_walls(g, g->mini_map, g->player->x, g->player->y);
	//resize_map(g);
	//put_player(g);
	// for (size_t i = 0; i < 3; i++)
	// {
	// 	g->map_img->instances->x++;
	// }
	// if (g->map_img->instances[0].x == W_WIDTH)
	// 	g->map_img->instances[0].x = 0 - g->mini_map->end_x;
}

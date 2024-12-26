#include "../Include/cub3D_bonus.h"

static void	paint(mlx_image_t *img, int color, int x, int y)
{
	int	len_y;
	int	len_x;

	len_y = y + W_HEIGHT / 50;
	len_x = x + W_WIDTH / 50;
	while (y <= len_y)
	{
		x = len_x - W_WIDTH / 50;
		while (x <= len_x)
			mlx_put_pixel(img, x++, y, color);
		y++;
	}
}

void	update_minimap(void *param)
{
	t_cub	*g;
	int		y;
	int		x;

	g = (t_cub *)param;
	y = -1;
	while (g->map[++y])
	{
		x = -1;
		while (g->map[y][++x])
		{
			if (g->map[y][x] == '1')
				paint(g->window_img, get_rgba(0, 0, 0, 255), x * W_HEIGHT / 50, y * W_HEIGHT / 50);
			else if (g->map[y][x] == '0' || g->map[y][x] == 'N' || g->map[y][x] == 'S'
				|| g->map[y][x] == 'W' || g->map[y][x] == 'E')
				paint(g->window_img, get_rgba(255, 255, 255, 255), x * W_HEIGHT / 50, y * W_HEIGHT / 50);
			else if (g->map[y][x] == 'D')
				paint(g->window_img, get_rgba(255, 255, 0, 255), x * W_HEIGHT / 50, y * W_HEIGHT / 50);
			else if (g->map[y][x] == 'O')
				paint(g->window_img, get_rgba(0, 255, 0, 255), x * W_HEIGHT / 50, y * W_HEIGHT / 50);
			if (y == (int)g->player->y && x == (int)g->player->x)
				paint(g->window_img, get_rgba(255, 0, 0, 255), x * W_HEIGHT / 50, y * W_HEIGHT / 50);
		}
	}
}

void	paint_minimap(t_cub *g)
{
	int		y;
	int		x;

	y = -1;
	while (g->map[++y])
	{
		x = -1;
		while (g->map[y][++x])
		{
			if (g->map[y][x] == '1')
				paint(g->window_img, get_rgba(0, 0, 0, 255), x * W_HEIGHT / 50, y * W_HEIGHT / 50);
			else if (g->map[y][x] == 'N' || g->map[y][x] == 'S' || g->map[y][x] == 'W' || g->map[y][x] == 'E')
				paint(g->window_img, get_rgba(255, 0, 0, 255), x * W_HEIGHT / 50, y * W_HEIGHT / 50);
			else
				paint(g->window_img, get_rgba(255, 255, 255, 255), x * W_HEIGHT / 50, y * W_HEIGHT / 50);
		}
	}
}


#include "../Include/cub3D.h"

static void	close_window(t_cub *game)
{
	mlx_close_window(game->mlx);
}

static void	make_move(t_cub *g, mlx_key_data_t key)
{
	if (key.key == MLX_KEY_A)
	{
		g->player->r_view -= ANG_MOVE;
		put_textures(g);
		ray_casting(g, g->ray);
	}
	else if (key.key == MLX_KEY_D)
	{
		g->player->r_view += ANG_MOVE;
		put_textures(g);
		ray_casting(g, g->ray);
	}
	if (key.key == MLX_KEY_W)
	{
		if (g->map[(int)(g->player->y + P_MOVE * sin(g->player->r_view))][(int)(g->player->x + P_MOVE * cos(g->player->r_view))] != '1')
		{
			if (g->map[(int)(g->player->y + P_MOVE * sin(g->player->r_view))][(int)g->player->x] != '1'
				&& g->map[(int)g->player->y][(int)(g->player->x + P_MOVE * cos(g->player->r_view))] != '1')
			{
				g->player->y += P_MOVE * sin(g->player->r_view);
				g->player->x += P_MOVE * cos(g->player->r_view);
				put_textures(g);
				ray_casting(g, g->ray);
				printf("mueve y a: %f\n", g->player->y);
			}
		}
	}
	else if (key.key == MLX_KEY_S)
	{
		if (g->map[(int)(g->player->y - P_MOVE * sin(g->player->r_view))][(int)(g->player->x - P_MOVE * cos(g->player->r_view))] != '1')
		{
			if (g->map[(int)(g->player->y - P_MOVE * sin(g->player->r_view))][(int)g->player->x] != '1' 
				&& g->map[(int)g->player->y][(int)(g->player->x - P_MOVE * cos(g->player->r_view))] != '1')
			{
				g->player->y -= P_MOVE * sin(g->player->r_view);
				g->player->x -= P_MOVE * cos(g->player->r_view);
				put_textures(g);
				ray_casting(g, g->ray);
				printf("mueve y a: %f\n", g->player->y);
			}
		}
	}
}

/* Set the moves and the actions */

void	set_moves(mlx_key_data_t key, void *param)
{
	if (key.key == MLX_KEY_ESCAPE && key.action == MLX_PRESS)
		close_window((t_cub *)param);
	if ((key.key == MLX_KEY_A || key.key == MLX_KEY_D
		|| key.key == MLX_KEY_W || key.key == MLX_KEY_S)
		&& (key.action == MLX_REPEAT || key.action == MLX_PRESS))
		make_move((t_cub *)param, key);
}

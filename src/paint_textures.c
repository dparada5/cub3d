#include "../Include/cub3D.h"

// void	first_try(t_cub *game)
// {
// 	mlx_texture_t	*txt;
// 	mlx_image_t		*img;
// 	int				source_x;
// 	int				source_y;
// 	int				size_y;
// 	int				size_x;
// 	int				index;
// 	int				red;
// 	int				green;
// 	int				blue;
// 	int				alpha;
// 	int				y;
// 	int				x;

// 	y = 0;
// 	txt = game->coor->south_i;
// 	size_y = W_HEIGHT / txt->height;
// 	size_x = W_WIDTH / txt->width;
// 	img = mlx_new_image(game->mlx, W_WIDTH, W_HEIGHT);
// 	while (y < W_HEIGHT)
// 	{
// 		x = 0;
// 		while (x < W_WIDTH)
// 		{
// 			source_x = x / size_x;
// 			source_y = y / size_y;
// 			if (source_x >= (int)txt->width)
// 				source_x = txt->width - 1;
// 			if (source_y >= (int)txt->height)
// 				source_y = txt->height - 1;
// 			index = (source_y * txt->width + source_x) * txt->bytes_per_pixel;
// 			red = txt->pixels[index + 0];
// 			green = txt->pixels[index + 1];
// 			blue = txt->pixels[index + 2];
// 			alpha = txt->pixels[index + 3];
// 			mlx_put_pixel(img, x, y, get_rgba(red, green, blue, alpha));
// 			x++;
// 		}
// 		y++;
// 	}
// 	mlx_image_to_window(game->mlx, img, 0, 0);
// 	mlx_loop(game->mlx);
// }

/* void	paint_texture(t_cub *g, t_ray *ray, mlx_texture_t *txt, double wall_h)
{
	double	text_y;
	double	text_x;
	double	y;

	y = ray->start_y;
	text_x = ray->col_x;
	while (y <= ray->end_y)
	{
		text_y = ((y - ray->start_y) * PIXEL) / wall_h;
		uint32_t color = (txt->pixels + (text_y * txt->width + text_x) * 4);
	mlx_put_pixel(g->window_img, g->x, )
		y++;
	}
} */


#include "../Include/cub3D.h"

void	printf_player(t_cub *game)
{
	printf("x = %f y = %f view = %c\n", game->player->x, game->player->y, game->player->view);
}

void	printf_coor(t_coor *coor)
{
	if (!coor)
		return ;
	if (coor->north)
		ft_printf_fd("%s\n", coor->north);
	if (coor->south)
		ft_printf_fd("%s\n", coor->south);
	if (coor->west)
		ft_printf_fd("%s\n", coor->west);
	if (coor->east)
		ft_printf_fd("%s\n", coor->east);
	if (coor->floor)
		ft_printf_fd("%s\n", coor->floor);
	if (coor->cealing)
		ft_printf_fd("%s\n", coor->cealing);
}

void	first_try(t_cub *game)
{
	mlx_texture_t	*txt;
	mlx_image_t		*img;
	int				source_x;
	int				source_y;
	int				size_y;
	int				size_x;
	int				index;
	int				red;
	int				green;
	int				blue;
	int				alpha;
	int				y;
	int				x;

	y = 0;
	txt = game->coor->south_i;
	size_y = W_HEIGHT / txt->height;
	size_x = W_WIDTH / txt->width;
	img = mlx_new_image(game->mlx, W_WIDTH, W_HEIGHT);
	while (y < W_HEIGHT)
	{
		x = 0;
		while (x < W_WIDTH)
		{
			source_x = x / size_x;
			source_y = y / size_y;
			if (source_x >= (int)txt->width)
				source_x = txt->width - 1;
			if (source_y >= (int)txt->height)
				source_y = txt->height - 1;
			index = (source_y * txt->width + source_x) * txt->bytes_per_pixel;
			red = txt->pixels[index + 0];
			green = txt->pixels[index + 1];
			blue = txt->pixels[index + 2];
			alpha = txt->pixels[index + 3];
			mlx_put_pixel(img, x, y, get_rgba(red, green, blue, alpha));
			x++;
		}
		y++;
	}
	mlx_image_to_window(game->mlx, img, 0, 0);
	mlx_loop(game->mlx);
}

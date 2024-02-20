/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzeraig <wzeraig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:25:45 by wzeraig           #+#    #+#             */
/*   Updated: 2024/02/16 10:37:02 by wzeraig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	t_data *game;
	t_img *img;
	t_map *map;

	game = malloc(sizeof(t_data));
	img = malloc(sizeof(t_img));
	map = malloc(sizeof(t_map));
	if (argc == 2)
	{
		init_struct(game);
		init_window(game);
		init_images(game);
		mlx_loop(MLX);
	}
}
int	init_images(t_data *game)
{
	game->img->wall = mlx_xpm_file_to_image(game->mlx, "./Graphique/img.xpm/wall1.xpm", &game->img->width, &game->img->height);
	if (!game->img->wall)
        error_msg(ERRIMG, game->map);
	game->img->coin = mlx_xpm_file_to_image(game->mlx, "./Graphique/img.xpm/coin.xpm", &game->img->width, &game->img->height);
	if (!game->img->coin)
        error_msg(ERRIMG, game->map);
	game->img->exit = mlx_xpm_file_to_image(game->mlx, "./Graphique/img.xpm/exit_1.xpm", &game->img->width, &game->img->height);
	if (!game->img->exit)
        error_msg(ERRIMG, game->map);
	game->img->ground = mlx_xpm_file_to_image(game->mlx, "./Graphique/img.xpm/back.xpm", &game->img->width, &game->img->height);
	if (!game->img->ground)
        error_msg(ERRIMG, game->map);
	game->img->player = mlx_xpm_file_to_image(game->mlx, "./Graphique/img.xpm/player.xpm", &game->img->width, &game->img->height);
	if (!game->img->player)
        error_msg(ERRIMG, game->map);
	return(Success);
}
int	parse_image(t_data *game)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (game->map->map[++j])
	{
		while (game->map->map[j][++i])
		{
			if (game->map->map[j][i] == '1')
				mlx_put_image_to_window(MLX, WIN, IMGWALL, j * IMG_SIZE * 2, IMGxI);
			else if ((game->map->map[j][i] == '0')
				|| (game->map->map[j][i] == 'E' && nbrcoin != 0))
				mlx_put_image_to_window(MLX, WIN, IMGGROUND, j * IMG_SIZE * 2, IMGxI);
			else if (game->map->map[j][i] == 'C')
				mlx_put_image_to_window(MLX, WIN, IMGGROUND, j * IMG_SIZE * 2, IMGxI);
			else if (game->map->map[j][i] == 'P')
				mlx_put_image_to_window(MLX, WIN, IMGGROUND, j * IMG_SIZE * 2, IMGxI);
			else if (game->map->map[j][i] == 'E' && nbrcoin == 0)
				mlx_put_image_to_window(MLX, WIN, IMGGROUND, j * IMG_SIZE * 2, IMGxI);
		}
		i = 0;
	}
	return (0);
}

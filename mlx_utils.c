/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzeraig <wzeraig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:25:24 by wzeraig           #+#    #+#             */
/*   Updated: 2024/02/15 16:13:42 by wzeraig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	init_window(t_data *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		return (ERROR);
	game->win = mlx_new_window(game->mlx, game->win_width, game->win_height, "Test");
	if (!game->win_height)
		return (free(game->mlx), ERROR); // la je free parce que je vais pas destroy ?? destroy ca free a linterieur
	return(Success);
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

int	loop_images(t_data *game)
{
	mlx_loop_hook(game->mlx, &parse_image, game);
	mlx_hook(game->win, KeyPress, KeyPressMask, &handle_input, game);
	mlx_hook(game->win, DestroyNotify, 0, &close, game);
//  si la souris quitte le jeu elle se supprime mais c pas dans le sujet 
	mlx_loop(game->mlx);
	return(0);
}

void destroy_images(t_data *game)
{
	mlx_destroy_image(game->mlx, game->img->coin);
	mlx_destroy_image(game->mlx, game->img->ground);
	mlx_destroy_image(game->mlx, game->img->exit);
	mlx_destroy_image(game->mlx, game->img->player);
	mlx_destroy_image(game->mlx, game->img->wall);
	mlx_destroy_display(game->mlx);
}
int checkcollect(t_data *game, int keysym, char tile) // si j'utilise l'un ou l'autre ca va pas buger ? pck l'autre equivaudra a rien ?  c bon je transforme tout en int keysym
{
	if ((keysym == XK_d && game->map->map[game->player_i + 1][game->player_j]  == tile) || (keysym == XK_Right  && game->map->map[game->player_i + 1][game->player_j] == tile))
		game->map->map[game->player_i][game->player_j - 1] = '0';		
	if ((keysym == XK_s && game->map->map[game->player_i][game->player_j + 1]  == tile) || (keysym == XK_Down  && game->map->map[game->player_i][game->player_j + 1] == tile))
		game->map->map[game->player_i][game->player_j - 1] = '0';
	if ((keysym == XK_a && game->map->map[game->player_i - 1][game->player_j]  == tile) || (keysym == XK_Left  && game->map->map[game->player_i - 1][game->player_j] == tile))
		game->map->map[game->player_i][game->player_j - 1] = '0';
	if ((keysym == XK_w && game->map->map[game->player_i][game->player_j - 1]  == tile) || (keysym == XK_Up  && game->map->map[game->player_i][game->player_j - 1] == tile))
		game->map->map[game->player_i][game->player_j - 1] = '0';
	else
		return(false);
	return(true);
}
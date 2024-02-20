/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzeraig <wzeraig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:42:20 by wzeraig           #+#    #+#             */
/*   Updated: 2024/02/16 12:16:17 by wzeraig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	handle_input(int keysym, t_data *game)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(MLX, WIN);
		exit(0);
	}
	if (keysym == XK_Left || keysym == XK_a)
		movement(game, keysym);
	if (keysym == XK_Right || keysym == XK_d)
		movement(game, keysym);
	if (keysym == XK_Down || keysym == XK_s)
		movement(game, keysym);
	if (keysym == XK_Up || keysym == XK_w)
		movement(game, keysym);
	return (0);
}
void	movement(t_data *game, int keysym)
{
	if (game->map->exit == 0 && checkcollect(game, keysym, 'C') != false)
		game->map->collectables--;
	game->step_count++;
	if (check_next_tile(game, keysym, '1') == false)
	{
		game->map->map[game->player_i][game->player_j] = '0';
		if (keysym == XK_Left || keysym == XK_a)
			game->map->map[game->player_i - 1][game->player_j] = 'P';
		if (keysym == XK_Right || keysym == XK_d)
			game->map->map[game->player_i + 1][game->player_j] = 'P';
		if (keysym == XK_Down || keysym == XK_s)
			game->map->map[game->player_i][game->player_j + 1] = 'P';
		if (keysym == XK_Up || keysym == XK_w)
			game->map->map[game->player_i][game->player_j - 1] = 'P';
	}
	if (game->map->collectables == 0)
	// on peut exit et en plus i)l deviens e donc il s'affiche
	{
		game->map->exit = 1;
		game->map->map[game->exit_i][game->exit_j] = 'E';
	}
	if (game->map->collectables == 0 && game->map->exit == 1
		&& check_next_tile(game, keysym, 'E' == true))
		// si je fais ca ca va pas afficher limage de quand il arrive sur la sortie
		win_game(game);
	// afficher un petit bail style de victoire et supprimer la page heiiin sois je supp que si apres ca ya un event comme supprimer la page ect relire le sujet quand meme au cas ou
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
				mlx_put_image_to_window(MLX, WIN, IMGWALL, IMGxI, IMGxJ);
			else if ((game->map->map[j][i] == '0')
				|| (game->map->map[j][i] == 'E' && nbrcoin != 0))
				mlx_put_image_to_window(MLX, WIN, IMGGROUND, IMGxI, IMGxJ);
			else if (game->map->map[j][i] == 'C')
				mlx_put_image_to_window(MLX, WIN, IMGCOIN,IMGxI, IMGxJ);
			else if (game->map->map[j][i] == 'P')
				mlx_put_image_to_window(MLX, WIN, IMGPLAYER, IMGxI, IMGxJ);
			else if (game->map->map[j][i] == 'E' && nbrcoin == 0)
				mlx_put_image_to_window(MLX, WIN, IMGEXIT, IMGxI, IMGxJ);
		}
		i = -1;
	}
	return (0);
}

int	lclose(t_data *game)
{
	mlx_destroy_window(MLX, WIN);
	exit(0);
}

int	check_next_tile(t_data *game, int keysym, char tile)
// si j'utilise l'un ou l'autre ca va pas buger ? pck l'autre equivaudra a rien ?  c bon je transforme tout en int keysym
{
	if ((keysym == XK_d && game->map->map[game->player_i
			+ 1][game->player_j] == tile) || (keysym == XK_Right
			&& game->map->map[game->player_i + 1][game->player_j] == tile))
		return (true);
	if ((keysym == XK_s && game->map->map[game->player_i][game->player_j
			+ 1] == tile) || (keysym == XK_Down
			&& game->map->map[game->player_i][game->player_j + 1] == tile))
		return (true);
	if ((keysym == XK_a && game->map->map[game->player_i
			- 1][game->player_j] == tile) || (keysym == XK_Left
			&& game->map->map[game->player_i - 1][game->player_j] == tile))
		return (true);
	if ((keysym == XK_w && game->map->map[game->player_i][game->player_j
			- 1] == tile) || (keysym == XK_Up
			&& game->map->map[game->player_i][game->player_j - 1] == tile))
		return (true);
	else
		return (false);
}
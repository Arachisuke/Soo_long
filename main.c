/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzeraig <wzeraig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 09:49:05 by wzeraig           #+#    #+#             */
/*   Updated: 2024/02/15 16:09:59 by wzeraig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv) // int main ???
{
	t_data *game;
	game = malloc(sizeof(t_data));
	game->map = malloc(sizeof(t_map));
	game->img = malloc(sizeof(t_img));
	if (argc == 2)
	{
		if (extension(argv[1], game->map) == ERROR)
			error_msg(ERRBER, game->map);
		init_struct(game);
		checkmap(openfd(argv[1], game), game->map);
		checkelement(game);
		if (move(game->map, game->map->line, game->map->index) == false)
			error_msg(ERRPLAY, game->map);
		init_game(game);   // init la structure pour jouer
		init_window(game); // init la window
		init_images(game); // init les images
		loop_images(game);
		destroy_images(game); // destroy toute les images
		free(game->mlx);
		if (game->map->map)
			ft_free(game->map->map); // pck je dois free chaque ligne mais ya pas que ca que je dois free je dois free mapline et line en plus 
	}
}

// jai check la map jai init les valeur a 0 ensuite jai reinit avant le debut de la partie maintenant place au event y en que peu
// ensuite faire les deplacement
// le RENDER quoi
// ne pas oublier les free
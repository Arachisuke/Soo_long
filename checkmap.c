/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzeraig <wzeraig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:12:30 by wzeraig           #+#    #+#             */
/*   Updated: 2024/02/15 16:08:44 by wzeraig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	openfd(char *path, t_data *game)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		error_msg(ERRFD, game->map);
	return (fd);
}

int	checkmap(int fd, t_map *map)
{
	map->mapline = get_next_line(fd);
	map->lenline = (ft_strlen(map->mapline));
	if (search(map->mapline, Wall, map->lenline)) // ca c le lenline avec /n
		error_msg(ERRWALL, map);
	while (map->line != NULL)
	{
		map->mapline = strjoinfree(map->mapline, map->line); // je peux utiliser quelque lenline pour enlever les ft_strlen 
		map->countline++;
		map->line = get_next_line(fd);
		if (map->line == NULL)
			break ;
		if (!ft_strchr(map->line, '\n'))
			map->lenline--; // a voir si cest vraiment opti !
		if (map->lenline != ft_strlen(map->line))
			error_msg(ERRREC, map);
		if (ft_strchr(map->line, '\n') && map->line[map->lenline - 2] != Wall)
			error_msg(ERRWALL, map);
		if (map->line[0] != Wall)
			error_msg(ERRWALL, map);
		else if (!ft_strchr(map->line, '\n') && search(map->line, Wall, map->lenline + 1))
			error_msg(ERRWALL, map);
	}
	return (Success);
}

int	checkelement(t_data *game)
{
	game->map->count = count(game->map->mapline, Exit) + count(game->map->mapline, Personnage);
	game->map->collected = count(game->map->mapline, Collectable);
	if (game->map->count != 2 || game->map->collected < 1)
		error_msg(ERRNUMBER, game->map);
	modulatemap(game);
	pos_index(game);  // c pour move il a lindex de la position P
	// plus printf jaffiche avec error msg car ca affiche bien les couleur dans le bon fd stderrlog et en meme temps ca free donc carrer comme en coree
	if (search2(game->map->line))
		// si il existe un autre element que les elements de base
		error_msg(ERRFALSE, game->map);       // a faire apres
	game->map->collectables = game->map->collected; // changer gamer en game
	return (Success);
}

int	move(t_map *map, char *str, size_t i)
{
	if (map->exit == 1 && map->collected == 0)
		return (true);
	else if (str[i] == Wall)
		return (false);
	else if (str[i] == Exit)
		map->exit = 1;
	else if (str[i] == Collectable)
		map->collected--;
	str[i] = Wall;
	if ((move(map, str, i + map->lenline)) || (move(map, str, i + 1))
		|| (move(map, str, i - 1)) || (move(map, str, i - map->lenline)))
		return (true);
	else
		return (false);
}

void	modulatemap(t_data *game)
{
	int j;

	j = 0;
	game->map->line = ft_strdup("");
	game->map->map = ft_split(game->map->mapline, '\n'); // la je split en plusieurs string sans n vu que cest le separateur donc la jai une map sans N pour les graphicss hsl tas capte
	while(game->map->map[j]) // tant quil existe
	{
		game->map->line = ft_strjoin(game->map->line, game->map->map[j]); // je prend mapline et je join a chaque ligne de map comme ca ca devient une ligne sans N pour Move
		j++;
	}
}


// jai fini les et ils sont valide  donc je le concatene en une map->maplineing
// free ????
//  si je veux augmenter la vitesse de mon code je transforme tout en else if
// elle aime bien les delimitation  il fois lui imposer des limites clair
// map->line + longueur
// map->line - longueur
// la recursivite aime pas l'incrementation
// cette ligne a l'air de passer
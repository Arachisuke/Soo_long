/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzeraig <wzeraig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 13:37:50 by wzeraig           #+#    #+#             */
/*   Updated: 2024/02/16 12:28:36 by wzeraig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void init_struct(t_data *game)
{
	
	game->step_count = 0;
	game->map->collected = 0;
	game->map->exit = 0;
	game->win_height = 0;
	game->win_width = 0;
	game->map->collectables = 0;
	game->map->lenline = 0;
	game->map->line = ft_strdup("");
	game->map->map = NULL;
	game->map->index = 0;
}

void init_game(t_data *game) // cest tout ce qui a change apres les checks
{
	game->map->collected = 0;
	game->map->exit = 0;
	game->win_height = game->map->countline * IMG_SIZE;
	game->win_width = game->map->lenline * IMG_SIZE;
	game->img->height = IMG_SIZE;
	game->img->width = IMG_SIZE;
	game->map->index = 0;
	pos_exit(game);
	pos_player(game); 
}

int pos_player(t_data *game)
{
	int i;
	int j;
	
	j = 0;
	i = 0;
	while(game->map->map[j])
	{
		while(game->map->map[j][i])
		{
			if(game->map->map[j][i] == 'P')
			{	game->player_i = i;
				game->player_j = j;
			}
			i++;
		}
	j++;
	i = 0;
	}
	return (0);
}



int pos_exit(t_data *game)
{
	int i;
	int j;
	
	j = 0;
	i = 0;
	while(game->map->map[j])
	{
		while(game->map->map[j][i])
		{
			if(game->map->map[j][i] == 'E')
			{	game->exit_i = i;
				game->exit_j = j;
			}
			i++;
		}
	j++;
	i = 0;
	}
	return (0);
}
int pos_index(t_data *game)
{
	int i;
	
	i = 0;
	while(game->map->line[i])
	{
		if(game->map->line[i] == 'P')
		{	game->map->index = i;
			return(0);
		}
		i++;
	}
	return (1);
}
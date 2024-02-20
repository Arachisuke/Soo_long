/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzeraig <wzeraig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:58:10 by wzeraig           #+#    #+#             */
/*   Updated: 2024/02/15 15:58:24 by wzeraig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	win_game(t_data *game)
{
	if (game->map->exit == 1)// je rajouterais pas les collectables
	{
		mlx_destroy_window(game->mlx, game->win);
		return(Success);
	}
	else
		return(ERROR);
}
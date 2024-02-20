/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzeraig <wzeraig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:09:28 by wzeraig           #+#    #+#             */
/*   Updated: 2024/02/13 14:20:09 by wzeraig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_msg(char *str, t_map *map)
{
	if (map->map)
		free(map->map);
	if (map->line)
		free(map->line);
	ft_putstr_fd(RED, 2);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(RESET, 2);
	exit(1);
}
void	move_msg(t_data *game)
{
	//ft_putstr_fd("\E[H\E[2J", 1); // c quoi ce merdier
	ft_putstr_fd(PEACH, 1);
	printf("Moves counter : %d\n", game->step_count);
	ft_putstr_fd(RESET, 1);
}

void	ft_free(char **strs)
{
	int j;

	j = 0;
	if (strs == NULL || !strs)
	
	while(strs[j])
	{
		free(strs[j]);
		j++;
	}
	free(strs);
}
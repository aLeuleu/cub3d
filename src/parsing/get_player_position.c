/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_position.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alevra <alevra@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 17:27:32 by alevra            #+#    #+#             */
/*   Updated: 2023/05/29 17:56:37 by alevra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_player_orientation(t_player *player, const t_map *map);

void	get_player_position(t_player *player, t_map *map)
{
	int pos_x;
	int pos_y;
	int i;
	int j;

	i = 0;
	j = 0;
	pos_x = -1;
	pos_y = -1;
	while(i < map->height)
	{
		j = 0;
		while(j < map->width)
		{
			if(ft_strchr( "NSEW", map->map[i][j]))
			{
				pos_x = j;
				pos_y = i;
				break ;
			}
			j++;
		}
		i ++;
	}
	if (pos_x < 0 || pos_y < 0)
		return ;
	player->pos_x = pos_x;
	player->pos_y = pos_y;
	get_player_orientation(player, map);
}

static void	get_player_orientation(t_player *player, const t_map *map)
{
	int pos_x;
	int pos_y;

	pos_x = player->pos_x;
	pos_y = player->pos_y;
	if (map->map[pos_y][pos_x] == 'N')
		player->orientation = 3*M_PI / 2;
	else if (map->map[pos_y][pos_x] == 'S')
		player->orientation = M_PI / 2;
	else if (map->map[pos_y][pos_x] == 'E')
		player->orientation = 0;
	else
		player->orientation = M_PI;
}

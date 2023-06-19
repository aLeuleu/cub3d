/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_position.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 17:27:32 by alevra            #+#    #+#             */
/*   Updated: 2023/06/19 14:40:20 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_player_orientation(t_player *player, const t_map *map)
{
	int		pos_x;
	int		pos_y;
	double	security_gap;

	security_gap = 0.01;
	pos_x = (int)player->pos.x;
	pos_y = (int)player->pos.y;
	if (map->map[pos_y][pos_x] == 'N')
		player->orientation = 3 * M_PI / 2 + security_gap;
	else if (map->map[pos_y][pos_x] == 'S')
		player->orientation = M_PI / 2 + security_gap;
	else if (map->map[pos_y][pos_x] == 'E')
		player->orientation = security_gap;
	else
		player->orientation = M_PI + security_gap;
}

static void	player_coo(t_display *display, int *pos_x, int *pos_y)
{
	int	i;
	int	j;

	i = 0;
	while (i < display->map.height)
	{
		j = 0;
		while (j < display->map.width)
		{
			if (ft_strchr("NSEW", display->map.map[i][j]))
			{
				*pos_x = j;
				*pos_y = i;
				break ;
			}
			j++;
		}
		i ++;
	}
}

void	get_player_position(t_display *display)
{
	int	pos_x;
	int	pos_y;

	pos_x = -1;
	pos_y = -1;
	player_coo(display, &pos_x, &pos_y);
	if (pos_x < 0 || pos_y < 0)
		return ;
	display->player.pos.x = pos_x + 0.5;
	display->player.pos.y = pos_y + 0.5;
	get_player_orientation(&display->player, &display->map);
}

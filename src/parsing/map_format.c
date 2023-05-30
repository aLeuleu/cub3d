/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:33:35 by lpupier           #+#    #+#             */
/*   Updated: 2023/05/30 14:41:18 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_player_box(char box)
{
	if (box == 'N' || box == 'S' || box == 'W' || box == 'E')
		return (1);
	return (0);
}

static int	check_wall_border(char **map, int line, int column)
{
	int	status;

	status = EXIT_SUCCESS;
	if (map[line][column] == '0' || is_player_box(map[line][column]))
	{
		if ((line == 0 || !map[line + 1]) \
		|| (column == 0 || !map[line][column + 1]))
			status = EXIT_FAILURE;
		if (map[line][column] && map[line][column + 1] == ' ')
			status = EXIT_FAILURE;
		if (column != 0 && map[line][column - 1] == ' ')
			status = EXIT_FAILURE;
		if (line != 0 && map[line - 1][column] == ' ')
			status = EXIT_FAILURE;
		if (map[line + 1] && map[line + 1][column] == ' ')
			status = EXIT_FAILURE;
	}
	if (status == EXIT_FAILURE)
	{
		if (is_player_box(map[line][column]))
			error("The player is out of the game map");
		else
			bad_format_tab("a wall is badly closed", line + 1, column + 1);
	}
	return (status);
}

static int	check_player_position(char box, int *is_player)
{
	if (is_player_box(box))
	{
		if (*is_player)
		{
			error("There are several players on the map");
			return (EXIT_FAILURE);
		}
		*is_player = 1;
	}
	return (EXIT_SUCCESS);
}

int	map_is_formated(t_map *map)
{
	int	line;
	int	column;
	int	is_player;

	line = 0;
	is_player = 0;
	while (line < map->height)
	{
		column = 0;
		while (column < map->width)
		{
			if (check_wall_border(map->map, line, column) == EXIT_FAILURE)
				return (EXIT_FAILURE);
			if (check_player_position(map->map[line][column], \
										&is_player) == EXIT_FAILURE)
				return (EXIT_FAILURE);
			column++;
		}
		line++;
	}
	if (!is_player)
		return (error("The player does not appear on the map"), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

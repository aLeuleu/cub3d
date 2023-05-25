/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 17:27:32 by lpupier           #+#    #+#             */
/*   Updated: 2023/05/25 13:52:08 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/**
 * @brief The purpose of the function is to retrieve the floor, walls,
 * player position of the map.
 * 
 * @param fd The file descriptor of the file being read.
 * @param map Overall structure of the map (see include/cub3d.h)
 * 
 * @return (int) Returns EXIT_SUCCESS or EXIT_FAILURE
 */
int	get_map(int fd, t_map *map)
{
	int		idx;
	char	*line;

	map->map = NULL;
	idx = 0;
	while (1)
	{
		idx++;
		line = get_next_line(fd);
		if (!line)
			break ;
		if (fill_map(line, map) == EXIT_FAILURE)
		{
			error("The game map is incorrectly formatted");
			return (free(line), EXIT_FAILURE);
		}
		free(line);
	}
	return (EXIT_SUCCESS);
}

/**
 * @brief Function to fill the linked list representing the game map.
 * 
 * @param line Character string representing a line of the map file
 * @param map Overall structure of the map (see include/cub3d.h)
 * @return (int) Returns EXIT_SUCCESS or EXIT_FAILURE
 */
int	fill_map(char *line, t_map *map)
{
	t_list	*new;
	int		idx;
	char	c;

	idx = -1;
	while (line[++idx])
	{
		c = line[idx];
		if (c != ' ' && c != '0' && c != '1' && c != '\n' \
		&& c != 'N' && c != 'S' && c != 'W' && c != 'E')
			return (EXIT_FAILURE);
	}
	new = ft_lstnew(ft_strdup(line));
	if (!new)
		return (ft_lstiter(map->map, free), EXIT_FAILURE);
	ft_lstadd_back(&map->map, new);
	return (EXIT_SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 17:27:32 by lpupier           #+#    #+#             */
/*   Updated: 2023/05/29 14:41:59 by lpupier          ###   ########.fr       */
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
	int			idx;
	char		*line;
	t_list_char	*temp_map;

	temp_map = NULL;
	idx = 0;
	while (1)
	{
		idx++;
		line = get_next_line(fd);
		if (!line)
			break ;
		if (fill_temp_map(line, &temp_map) == EXIT_FAILURE)
		{
			error("The game map is incorrectly formatted");
			return (free(line), EXIT_FAILURE);
		}
		free(line);
	}
	fill_map(map, temp_map);
	ft_lstclear((t_list **)&temp_map, free);
	return (EXIT_SUCCESS);
}

/**
 * @brief Function to fill the linked list representing the game map.
 * 
 * @param line Character string representing a line of the map file
 * @param temp_map 
 * @return (int) Returns EXIT_SUCCESS or EXIT_FAILURE
 */
int	fill_temp_map(char *line, t_list_char **temp_map)
{
	t_list_char	*new;
	int			idx;
	char		c;

	if (!line || line[0] == '\n')
		return (EXIT_SUCCESS);
	idx = -1;
	while (line[++idx])
	{
		c = line[idx];
		if (c != ' ' && c != '0' && c != '1' && c != '\n' \
		&& c != 'N' && c != 'S' && c != 'W' && c != 'E')
			return (EXIT_FAILURE);
	}
	new = (t_list_char *)ft_lstnew(ft_strdup(line));
	if (!new)
		return (ft_lstiter((t_list *)*temp_map, free), EXIT_FAILURE);
	if (!(*temp_map))
		*temp_map = new;
	else
		ft_lstadd_back((t_list **)temp_map, (t_list *)new);
	return (EXIT_SUCCESS);
}

/**
 * @brief 
 * 
 * @param map Overall structure of the map (see include/cub3d.h)
 * @param temp_map 
 * @return (int) Returns EXIT_SUCCESS or EXIT_FAILURE
 */
int	fill_map(t_map *map, t_list_char *temp_map)
{
	t_list_char	*temp;
	int			len;
	int			idx;

	map->height = ft_lstsize((t_list *)temp_map);
	map->width = find_big_line(temp_map);
	map->map = malloc(sizeof(char **) * (map->height + 1));
	if (!map->map)
		return (EXIT_FAILURE);
	temp = temp_map;
	len = 0;
	while (temp)
	{
		map->map[len] = malloc(sizeof(char *) * (map->width + 1));
		if (!map->map[len])
			return (EXIT_FAILURE);
		idx = 0;
		while (temp->content[idx])
		{
			if (temp->content[idx] == '\n')
				break ;
			map->map[len][idx] = temp->content[idx];
			idx++;
		}
		while (idx < map->width)
			map->map[len][idx++] = ' ';
		map->map[len][idx] = '\0';
		len++;
		temp = temp->next;
	}
	map->map[len] = NULL;
	return (EXIT_SUCCESS);
}

int	find_big_line(t_list_char *temp_map)
{
	t_list_char	*temp;
	int			len;
	int			temp_len;

	temp = temp_map;
	len = 0;
	while (temp)
	{
		temp_len = ft_strlen(temp->content);
		if (temp->content[temp_len - 1] == '\n')
			temp_len--;
		if (temp_len > len)
			len = temp_len;
		temp = temp->next;
	}
	return (len);
}

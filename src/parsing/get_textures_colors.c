/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures_colors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:43:35 by lpupier           #+#    #+#             */
/*   Updated: 2023/05/24 17:23:23 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/**
 * @brief The purpose of the function is to retrieve the path of the textures
 * and the color of the ceiling and the floor of the map.
 * 
 * @param fd FD of the map file
 * @param map Overall structure of the map (see include/cub3d.h)
 * @return (int) Returns EXIT_SUCCESS or EXIT_FAILURE
 */
int	get_textures_colors(int fd, t_map *map)
{
	int		idx;
	char	*line;
	char	**line_tab;

	idx = 0;
	while (1)
	{
		idx++;
		line = get_next_line(fd);
		if (!line)
			break ;
		if (is_str_empty(line) == EXIT_SUCCESS)
		{
			free(line);
			continue ;
		}
		line_tab = ft_split(line, ' ');
		free(line);
		if (is_texture_color(line_tab, idx, map) == EXIT_FAILURE)
			return (bad_format_line(idx), ft_free_tab(line_tab), EXIT_FAILURE);
		ft_free_tab(line_tab);
	}
	return (EXIT_SUCCESS);
}

/**
 * @brief the purpose of the function is to check if the selected line
 * in the map is composed only of space or just empty.
 * 
 * @param line Character string representing a line of the map file
 * @return (int) Returns EXIT_SUCCESS if the string is composed only of spaces
 * or just emptyor EXIT_FAILURE
 */
int	is_str_empty(char *line)
{
	int	idx;

	idx = 0;
	while (line[idx] == ' ' || line[idx] == '\n')
		idx++;
	if (!line[idx])
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

/**
 * @brief The function assigns to the variables
 * of the structure the path of the textures or colors.
 * 
 * @param line_tab Array of string representing a line
 * of the map separated by its spaces.
 * @param map Overall structure of the map (see include/cub3d.h)
 * @param idx Line index in map file
 * @return (int) Returns EXIT_SUCCESS or EXIT_FAILURE
 */
int	is_texture_color(char **line_tab, int idx, t_map *map)
{
	static int	nb_parameter_set = 0;

	(void)idx;
	if (ft_len_tab(line_tab) != 2 && nb_parameter_set < 6)
		return (EXIT_FAILURE);
	if (!ft_strcmp(line_tab[0], "NO"))
		map->path_texture_no = line_tab[1];
	else if (!ft_strcmp(line_tab[0], "SO"))
		map->path_texture_so = line_tab[1];
	else if (!ft_strcmp(line_tab[0], "WE"))
		map->path_texture_we = line_tab[1];
	else if (!ft_strcmp(line_tab[0], "EA"))
		map->path_texture_ea = line_tab[1];
	else if (!ft_strcmp(line_tab[0], "F"))
		map->color_f = line_tab[1];
	else if (!ft_strcmp(line_tab[0], "C"))
		map->color_c = line_tab[1];
	else
	{
		if (nb_parameter_set == 6)
			return (EXIT_SUCCESS);
		return (EXIT_FAILURE);
	}
	nb_parameter_set++;
	return (EXIT_SUCCESS);
}

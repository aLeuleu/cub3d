/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures_colors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:43:35 by lpupier           #+#    #+#             */
/*   Updated: 2023/05/31 13:21:37 by lpupier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	is_str_empty(char *line)
{
	int	idx;

	idx = 0;
	while (line[idx] == ' ' || line[idx] == '\n')
		idx++;
	if (!line[idx])
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

static int	is_texture_color(char **line_tab, t_map *map)
{
	if (!ft_strcmp(line_tab[0], "NO") && !map->path_texture_no)
		map->path_texture_no = ft_strdup(line_tab[1]);
	else if (!ft_strcmp(line_tab[0], "SO") && !map->path_texture_so)
		map->path_texture_so = ft_strdup(line_tab[1]);
	else if (!ft_strcmp(line_tab[0], "WE") && !map->path_texture_we)
		map->path_texture_we = ft_strdup(line_tab[1]);
	else if (!ft_strcmp(line_tab[0], "EA") && !map->path_texture_ea)
		map->path_texture_ea = ft_strdup(line_tab[1]);
	else if (!ft_strcmp(line_tab[0], "F") && !map->color_f_raw)
		map->color_f_raw = ft_strdup(line_tab[1]);
	else if (!ft_strcmp(line_tab[0], "C") && !map->color_c_raw)
		map->color_c_raw = ft_strdup(line_tab[1]);
	else
	{
		if (map->nb_parameter_set == 6)
			return (EXIT_SUCCESS);
		return (EXIT_FAILURE);
	}
	map->nb_parameter_set++;
	return (EXIT_SUCCESS);
}

static char	**split_name_value(char *line)
{
	int		idx;
	char	*name;
	char	*value;
	char	**tab;

	idx = 0;
	while (line[idx] && line[idx] != ' ')
		idx++;
	name = ft_substr(line, 0, idx);
	while (line[idx] && line[idx] == ' ')
		idx++;
	value = ft_substr(line, idx, ft_strlen(line) - idx);
	if (!name || !value)
		return (NULL);
	tab = malloc(sizeof(char **) * 3);
	if (!tab)
		return (NULL);
	tab[0] = ft_strtrim(name, " \n");
	tab[1] = ft_strtrim(value, " \n");
	tab[2] = NULL;
	free(name);
	free(value);
	return (tab);
}

/**
 * @brief The purpose of the function is to retrieve the path of the textures
 * and the color of the ceiling & floor of the map.
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
		if (map->nb_parameter_set == 6)
			break ;
		idx++;
		line = get_next_line(fd);
		if (!line)
			break ;
		if (is_str_empty(line) == EXIT_SUCCESS)
		{
			free(line);
			continue ;
		}
		line_tab = split_name_value(line);
		free(line);
		if (is_texture_color(line_tab, map) == EXIT_FAILURE)
			return (bad_format_line(idx), ft_free_tab(line_tab), EXIT_FAILURE);
		ft_free_tab(line_tab);
	}
	return (EXIT_SUCCESS);
}
